/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:23:29 by toliver           #+#    #+#             */
/*   Updated: 2018/01/09 21:49:15 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_buddhafill(void *part)
{
	int		x;
	int		y;
	t_part	*p;

	p = part;
	y = p->y;
	while (y < p->WINY)
	{
		x = -1;
		while (++x < p->WINX)
		{
			if (ft_buddhabrot(ft_coord(x, y, p->fra, p->data),
						ft_comp(0, 0), p->data->buddhabrot->ite) != -1)
				ft_buddhabrotfill(ft_coord(x, y, p->fra, p->data),
						ft_comp(0, 0), p->fra->array, p->data);
		}
		y += 4;
	}
	return (NULL);
}

void		*ft_minibuddhafill(void *part)
{
	int		x;
	int		y;
	t_part	*p;

	p = part;
	y = -1;
	while (++y < p->fra->imgy)
	{
		x = -1;
		while (++x < p->fra->imgx)
		{
			if (ft_buddhabrot(ft_mcoord(x, y, p->fra, p->data),
						ft_comp(0, 0), p->fra->ite) != -1)
				ft_buddhabrotfill(ft_mcoord(x, y, p->fra, p->data),
						ft_comp(0, 0), p->fra->miniarray, p->data);
		}
	}
	ft_buddhaminiimg(p->data);
	return (NULL);
}

void		ft_buddhabrotfill(t_complex c, t_complex z, t_value **target,
		t_data *data)
{
	int		i;

	i = 0;
	while (i < data->buddhabrot->ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		pingpixel(z, target, data);
		if (ft_checkvalue(z) > 4)
			break ;
		i++;
	}
}

void		ft_buddhaminiimg(t_data *data)
{
	int		x;
	int		y;
	int		biggest;

	y = -1;
	biggest = 0;
	while (++y < ONSCREEN->imgy)
	{
		x = -1;
		while (++x < ONSCREEN->imgx)
			biggest = (data->buddhabrot->miniarray[y][x].ping > biggest) ?
				data->buddhabrot->miniarray[y][x].ping : biggest;
	}
	if (biggest < 1)
		biggest = 1;
	ft_scalearray(biggest, data->buddhabrot->miniarray, 1, data);
}

void		ft_buddhaimg(t_data *data)
{
	int		x;
	int		y;
	int		biggest;

	y = -1;
	biggest = 0;
	while (++y < WINY)
	{
		x = -1;
		while (++x < WINX)
			biggest = (data->buddhabrot->array[y][x].ping > biggest) ?
				data->buddhabrot->array[y][x].ping : biggest;
	}
	if (biggest < 1)
		biggest = 1;
	ft_scalearray(biggest, data->buddhabrot->array, 0, data);
}
