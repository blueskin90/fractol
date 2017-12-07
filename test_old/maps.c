/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:44:49 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:53:22 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map				*mapnew(void)
{
	t_map			*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(0);
	map->str = NULL;
	map->array_size = 0;
	map->posz = NULL;
	map->color = NULL;
	map->next = NULL;
	return (map);
}

t_parsedmap			*copymap(t_map *map)
{
	int				i;
	t_map			*ptr;
	t_parsedmap		*copy;

	i = 0;
	ptr = map;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	if (!(copy = (t_parsedmap*)malloc(sizeof(t_parsedmap))))
		exit(0);
	copy->array_size = i * map->array_size;
	if (!(copy->point =
				(t_vector4*)malloc(sizeof(t_vector4) * copy->array_size)))
		exit(0);
	if (!(copy->pointp =
				(t_vector4*)malloc(sizeof(t_vector4) * copy->array_size)))
		exit(0);
	copy->xmid = (double)map->array_size / 2;
	copy->ymid = (double)i / 2;
	copyparam(map, copy);
	return (copy);
}

int					copyparam(t_map *map, t_parsedmap *copy)
{
	int				i;
	size_t			j;
	int				k;
	t_map			*ptr;

	i = 0;
	k = 0;
	ptr = map;
	while (ptr != NULL)
	{
		j = 0;
		while (j < map->array_size)
		{
			copy->point[i].x = j - copy->xmid;
			copy->point[i].y = k - copy->ymid;
			copy->point[i].z = ptr->posz[j];
			copy->point[i].w = ptr->color[j];
			j++;
			i++;
		}
		k++;
		ptr = ptr->next;
	}
	return (1);
}
