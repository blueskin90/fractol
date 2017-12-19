/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:18:13 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 07:58:34 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_cmul(t_complex c1, t_complex c2)
{
	double		tmpr;
	double		tmpi;

	tmpr = c1.r;
	tmpi = c1.i;
	c1.r = c1.r * c2.r - c1.i * c2.i;
	c1.i = tmpr * c2.i + tmpi * c2.r;
	return (c1);
}

t_complex		ft_comp(int x, int y)
{
	t_complex	comp;
	comp.r = x;
	comp.i = y;
	return (comp);
}
// refaire cette fonction, pour qu'elle donne le point modifie par le zoom et l'offset
t_complex		ft_complex(int x, int y, t_data *data)
{
	t_complex	comp;

	comp.r = ((double)x - (double)(data->winx) / 3 * 2) /
		((double)(data->winx - 1) / 3); // /10 = puissance zoom, rajouter l'offset du zoom / decalage apres l'applicaton du zoom
	// et prendre en compte le zoom dans l'offset lorsqu'on deplace
	// pouvoir modifier les limites du set dans une variable dans un t_fractale 
	comp.i = ((double)y - (double)(data->winy) / 2) /
		((double)(data->winy - 1) / 2);
	return (comp);
}

t_complex		ft_cadd(t_complex c1, t_complex c2)
{
	c1.r += c2.r;
	c1.i += c2.i;
	return (c1);
}

t_complex		ft_csqr(t_complex comp)
{
	double	tmp;

	tmp = comp.r;
	comp.r = comp.r * comp.r - comp.i * comp.i;
	comp.i = 2 * tmp * comp.i;
	return (comp);
}

double			ft_cmod(t_complex comp)
{
	return (sqrt(comp.r * comp.r + comp.i * comp.i));
}

t_complex		ft_cabs(t_complex c)
{
	c.r = fabs(c.r);
	c.i = fabs(c.i);
	return (c);
}

t_complex		ft_coordzoom(double x, double y, t_fractale *fra, t_data *data)
{
	t_complex	comp;
	comp.r = (x + (((data->winx - 1) / fabs(fra->maxx - fra->minx)) * fra->minx))
		/ ((data->winx - 1) / fabs(fra->maxx - fra->minx));
	comp.i = (y + (((data->winy - 1) / fabs(fra->maxy - fra->miny)) * fra->miny))
		/ ((data->winy - 1) / fabs(fra->maxy - fra->miny));
	// retourne parfaitement la valeur de x et y selon la taille du tableau reele, reste a implementer le zoom
	return (comp);
}
/*
t_complex		ft_mousecoord(double x, double y, t_fractale *fra, t_data *data)
{
	(void)fra;
	(void)data;
	t_complex	comp;
	comp.r = x / (data->winx - 1) * (data->onscreen->maxx - data->onscreen->minx);
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) * (data->onscreen->maxy - data->onscreen->miny);
	return (comp);
}
*/
t_complex		ft_mousecoord(double x, double y, t_fractale *fra, t_data *data)
{
	(void)fra;
	(void)data;
	t_complex	comp;
	comp.r = x / (data->winx - 1) * (data->onscreen->maxx - data->onscreen->minx) + data->onscreen->minx;
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) * (data->onscreen->maxy - data->onscreen->miny) + data->onscreen->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_complex		ft_coord(double x, double y, t_fractale *fra, t_data *data)
{
	(void)fra;
	(void)data;
	t_complex	comp;
	comp.r = x / (data->winx - 1) * (fra->maxx - fra->minx) + fra->minx;
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) * (fra->maxy - fra->miny) + fra->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_complex		ft_mcoord(double x, double y, t_fractale *fra, t_data *data)
{
	(void)fra;
	(void)data;
	t_complex	comp;
	comp.r = x / (fra->imgx - 1) * (fra->maxx - fra->minx) + fra->minx;
	comp.i = (-(y - fra->imgy + 1)) / (fra->imgy - 1) * (fra->maxy - fra->miny) + fra->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}
