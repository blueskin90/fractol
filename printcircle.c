/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcircle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:11:07 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 01:26:16 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pcirloop(t_data *data, t_point p1, t_point p2, int color)
{
	ft_line(ft_point(p1.x + p2.x, p1.y + p2.y),
			ft_point(p1.x + p2.y, p1.y + p2.x), data, color);
	ft_line(ft_point(p1.x - p2.y, p1.y + p2.x),
			ft_point(p1.x - p2.x, p1.y + p2.y), data, color);
	ft_line(ft_point(p1.x - p2.x, p1.y - p2.y),
			ft_point(p1.x - p2.y, p1.y - p2.x), data, color);
	ft_line(ft_point(p1.x + p2.y, p1.y - p2.x),
			ft_point(p1.x + p2.x, p1.y - p2.y), data, color);
}

void		pcirloop2(t_data *data, t_point p1, t_point p2, int color)
{
	px_to_onscreenimg(data, p1.x + p2.x, p1.y + p2.y, color);
	px_to_onscreenimg(data, p1.x + p2.y, p1.y + p2.x, color);
	px_to_onscreenimg(data, p1.x - p2.y, p1.y + p2.x, color);
	px_to_onscreenimg(data, p1.x - p2.x, p1.y + p2.y, color);
	px_to_onscreenimg(data, p1.x - p2.x, p1.y - p2.y, color);
	px_to_onscreenimg(data, p1.x - p2.y, p1.y - p2.x, color);
	px_to_onscreenimg(data, p1.x + p2.y, p1.y - p2.x, color);
	px_to_onscreenimg(data, p1.x + p2.x, p1.y - p2.y, color);
}

void		errset(int *y, int *err, int *dy)
{
	*y += 1;
	*err += *dy;
	*dy += 2;
}

void		printemptycircle(t_point p, int rad, t_data *data, int color)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		err;

	x = rad - 1;
	y = 0;
	dx = 1;
	dy = 1;
	err = dx - (rad << 1);
	while (x >= y)
	{
		pcirloop2(data, p, ft_point(x, y), color);
		if (err <= 0)
			errset(&y, &err, &dy);
		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (rad << 1);
		}
	}
}

void		printcircle(t_point p, int rad, t_data *data, int color)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		err;

	x = rad - 1;
	y = 0;
	dx = 1;
	dy = 1;
	err = dx - (rad << 1);
	while (x >= y)
	{
		pcirloop(data, p, ft_point(x, y), color);
		if (err <= 0)
			errset(&y, &err, &dy);
		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (rad << 1);
		}
	}
}
