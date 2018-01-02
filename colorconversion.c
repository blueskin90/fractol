/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorconversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:39:09 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:51:25 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			hsv_to_rgb(t_hsv hsv)
{
	float	c;
	float	h;
	float	x;
	float	m;

	c = (float)hsv.v / 100 * ((float)hsv.s / 100);
	h = (float)hsv.h / 60;
	x = c * (1 - fabsf(h - ((int)h / 2 * 2) - 1));
	m = (float)hsv.v / 100 - c;
	if (h >= 0 && h < 1)
		return (get_rgb(round(CM * 255), round(XM * 255), round(m * 255)));
	if (h >= 1 && h < 2)
		return (get_rgb(round(XM * 255), round(CM * 255), round(m * 255)));
	if (h >= 2 && h < 3)
		return (get_rgb(round(m * 255), round(CM * 255), round(XM * 255)));
	if (h >= 3 && h < 4)
		return (get_rgb(round(m * 255), round(XM * 255), round(CM * 255)));
	if (h >= 4 && h < 5)
		return (get_rgb(round(XM * 255), round(m * 255), round(CM * 255)));
	return (get_rgb(round(CM * 255), round(m * 255), round(XM * 255)));
}

t_hsv		rgb_to_hsv(int color)
{
	t_hsv	hsv;
	float	max;
	float	min;

	hsv.h = (float)int_to_rgb(color).r / 255 * 100;
	hsv.s = (float)int_to_rgb(color).g / 255 * 100;
	hsv.v = (float)int_to_rgb(color).b / 255 * 100;
	max = ft_max(hsv.h, hsv.s, hsv.v);
	min = ft_min(hsv.h, hsv.s, hsv.v);
	if (max == min)
		hsv.h = 0;
	else if (max == hsv.h)
		hsv.h = (int)round((60 * ((float)(hsv.s - hsv.v) / (max - min)) + 360))
			% 360;
	else if (max == hsv.s)
		hsv.h = round(60 * ((float)(hsv.v - hsv.h) / (max - min)) + 120);
	else
		hsv.h = round(60 * ((float)(hsv.h - hsv.s) / (max - min)) + 240);
	hsv.s = round((max == 0) ? 0 : (1 - (float)(min / max)) * 100);
	hsv.v = round(max);
	return (hsv);
}

void		modifyhue(int y, t_data *data)
{
	y = (y < 100) ? 100 : y;
	y = (y > 279) ? 279 : y;
	data->editedcolor->hsv.h = ((float)(279 - y) / 179 * 359);
	data->editedcolor->value = hsv_to_rgb(data->editedcolor->hsv);
	data->editedcolor->rgb = int_to_rgb(data->editedcolor->value);
	data->colorchanged = 1;
}

void		modifysv(int x, int y, t_data *data)
{
	x = (x < 96) ? 96 : x;
	x = (x > 275) ? 275 : x;
	y = (y < 100) ? 100 : y;
	y = (y > 279) ? 279 : y;
	data->editedcolor->hsv.s = ((float)(x - 96) / 179 * 100);
	data->editedcolor->hsv.v = ((float)(279 - y) / 179 * 100);
	data->editedcolor->value = hsv_to_rgb(data->editedcolor->hsv);
	data->editedcolor->rgb = int_to_rgb(data->editedcolor->value);
	data->colorchanged = 1;
}
