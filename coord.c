/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:26:17 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:53:19 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_coordzoom(float x, float y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	comp.r = (x + (((data->winx - 1) / fabs(fra->maxx - fra->minx)) *
				fra->minx))
		/ ((data->winx - 1) / fabs(fra->maxx - fra->minx));
	comp.i = (y + (((data->winy - 1) / fabs(fra->maxy - fra->miny)) *
				fra->miny))
		/ ((data->winy - 1) / fabs(fra->maxy - fra->miny));
	return (comp);
}

t_complex		ft_mousecoord(float x, float y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	comp.r = x / (data->winx - 1) *
		(data->onscreen->maxx - data->onscreen->minx) + data->onscreen->minx;
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) * (data->onscreen->maxy
			- data->onscreen->miny) + data->onscreen->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_complex		ft_coord(float x, float y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	(void)data;
	comp.r = x / (data->winx - 1) * (fra->maxx - fra->minx) + fra->minx;
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) *
		(fra->maxy - fra->miny) + fra->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_complex		ft_mcoord(float x, float y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	(void)data;
	comp.r = x / (fra->imgx - 1) * (fra->maxx - fra->minx) + fra->minx;
	comp.i = (-(y - fra->imgy + 1)) / (fra->imgy - 1) * (fra->maxy - fra->miny)
		+ fra->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_point			ft_point(int x, int y)
{
	t_point		p;

	p.x = x;
	p.y = y;
	return (p);
}
