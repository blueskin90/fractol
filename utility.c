/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:31:08 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 01:37:57 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_max(float a, float b, float c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}

float		ft_min(float a, float b, float c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void		ft_printite(t_data *data)
{
	char	*str;

	str = ft_itoa(data->onscreen->ite);
	mlx_string_put(data->mlx, data->win, 300, 20, 0xffffff, str);
	free(str);
}

void		*ft_malloc(int size)
{
	void	*memory;

	if (!(memory = malloc(size)))
		ft_error("Malloc failed !\n");
	return (memory);
}

void		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}
