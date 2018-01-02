/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:50:57 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 02:29:34 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		setred(int *red, float step)
{
	if (step <= 1 || (step > 5 && step <= 6))
		*red = 255;
	else if (step >= 2 && step < 4)
		*red = 0;
	else if (step > 1 && step < 2)
		*red = 510 - (float)255 * step;
	else
		*red = -(1020 - 255 * step);
}

void		setgreen(int *green, float step)
{
	if (step < 2)
		*green = 0;
	else if (step >= 2 && step < 3)
		*green = -(510 - 255 * step);
	else if (step >= 3 && step < 5)
		*green = 255;
	else
		*green = 1530 - (float)255 * step;
}

void		setblue(int *blue, float step)
{
	if (step < 1)
		*blue = 255 * step;
	else if (step >= 1 && step < 3)
		*blue = 255;
	else if (step >= 3 && step < 4)
		*blue = 1020 - (float)255 * step;
	else
		*blue = 0;
}

int			rainbow(int sizemax, int actualpos)
{
	int		r;
	int		g;
	int		b;
	float	i;

	i = (float)actualpos / ((float)(sizemax - 1) / 6);
	setred(&r, i);
	setgreen(&g, i);
	setblue(&b, i);
	return (get_rgb(r, g, b));
}

void		printrainbowgradient(t_data *data, t_point pos, t_point size)
{
	int		x;
	int		y;

	y = pos.y;
	while (y < pos.y + size.y)
	{
		x = pos.x;
		while (x < pos.x + size.x)
		{
			px_to_onscreenimg(data, x, y, rainbow(size.y, y - pos.y));
			x++;
		}
		y++;
	}
}
