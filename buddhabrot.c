/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:55:13 by toliver           #+#    #+#             */
/*   Updated: 2018/01/12 10:56:16 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_buddhabrot(t_complex c, t_complex z, int ite)
{
	int		i;
	float	retval;

	i = 0;
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 4)
		{
			retval = 0.5;
			return (retval);
		}
		i++;
	}
	return (-1);
}

void		ft_buddhainit(t_fractale *bud, t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WINY && (x = -1))
	{
		while (++x < WINX)
		{
			bud->array[y][x].value = 0;
			bud->array[y][x].ping = 0;
			bud->array[y][x].r = ft_coord(x, y, data->buddhabrot, data).r;
			bud->array[y][x].i = ft_coord(x, y, data->buddhabrot, data).i;
		}
	}
	y = -1;
	while (++y < bud->imgy && (x = -1))
	{
		while (++x < bud->imgx)
		{
			bud->miniarray[y][x].value = 0;
			bud->miniarray[y][x].ping = 0;
			bud->miniarray[y][x].r = ft_mcoord(x, y, data->buddhabrot, data).r;
			bud->miniarray[y][x].i = ft_mcoord(x, y, data->buddhabrot, data).i;
		}
	}
}

void		ft_scalearray(int max, t_value **array, int b, t_data *data)
{
	int		x;
	int		y;
	int		maxx;
	int		maxy;

	maxx = (b == 0) ? WINX : ONSCREEN->imgx;
	maxy = (b == 0) ? WINY : ONSCREEN->imgy;
	y = -1;
	while (++y < maxy)
	{
		x = -1;
		while (++x < maxx)
		{
			array[y][x].value = (float)array[y][x].ping / max;
			if (b == 0)
				px_to_onscreenimg(data, x, y, rgb_grad(array[y][x].value, data,
						data->buddhabrot));
			else
				px_to_miniimg(data->buddhabrot, x, y,
						rgb_grad(array[y][x].value, data, data->buddhabrot));
		}
	}
}

int			pingpixel(t_complex z, t_value **target, t_data *data)
{
	int		x;
	int		y;
	int		maxx;
	int		maxy;

	y = 0;
	x = 0;
	maxx = (target == data->buddhabrot->array) ? WINX : ONSCREEN->imgx;
	maxy = (target == data->buddhabrot->array) ? WINY : ONSCREEN->imgy;
	if (z.r < data->buddhabrot->minx || z.r > data->buddhabrot->maxx ||
		z.i < data->buddhabrot->miny || z.i > data->buddhabrot->maxy)
		return (0);
	while (target[y][x].r < z.r && x < maxx)
		x++;
	while (target[y][x].i > z.i && y < maxy)
		y++;
	if (y < maxy && x < maxx && target[y][x].ping < INT_MAX)
		target[y][x].ping++;
	return (1);
}
