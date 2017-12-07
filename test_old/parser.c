/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 03:46:07 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 17:17:35 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					hexvalue(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

int					ft_get_hexcolor(char *str)
{
	int				i;
	unsigned int	color;

	i = 0;
	color = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0xffffff);
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
	{
		i += 3;
		while (((str[i] >= '0' && str[i] <= '9') ||
		(str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f')))
		{
			color *= 16;
			color += hexvalue(str[i]);
			i++;
		}
		return (color);
	}
	else
		return (-1);
}

int					map_array_fill(t_map *map)
{
	t_map			*ptr;
	int				i;

	ptr = map;
	while (ptr)
	{
		i = 0;
		while (ptr->splitted[i])
		{
			ptr->posz[i] = ft_atoi(ptr->splitted[i]);
			ptr->color[i] = ft_get_hexcolor(ptr->splitted[i]);
			if (ptr->color[i] == -1)
				ft_error("wrong map !\n");
			i++;
		}
		ptr = ptr->next;
	}
	return (0);
}

int					map_array_init(t_map *map)
{
	t_map			*ptr;
	int				array_size;

	ptr = map;
	while (ptr)
	{
		array_size = -1;
		ptr->splitted = ft_strsplit(ptr->str, ' ');
		while (ptr->splitted[++array_size])
			;
		ptr->array_size = array_size;
		if (!(ptr->posz = (int*)malloc(sizeof(int) * array_size)))
			exit(0);
		if (!(ptr->color = (int*)malloc(sizeof(int) * array_size)))
			exit(0);
		ptr = ptr->next;
	}
	map_array_fill(map);
	return (0);
}

t_map				*map_parsing(char *argv)
{
	int				fd;
	t_map			*map;
	t_map			*ptr;
	char			*str;
	int				gnl_ret;

	map = mapnew();
	ptr = map;
	if (0 > (fd = open(argv, O_RDONLY)))
		ft_error("wrong map !\n");
	while ((gnl_ret = ft_get_next_line(fd, &str)) > 0)
	{
		ptr->next = mapnew();
		ptr = ptr->next;
		ptr->str = str;
		str = NULL;
	}
	if (str)
		free(str);
	if (gnl_ret == -1)
		ft_error("A problem occured in the GNL\n");
	ptr = map->next;
	free(map);
	map_array_init(ptr);
	return (ptr);
}
