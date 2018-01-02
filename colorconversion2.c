/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorconversion2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:05:42 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:51:37 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			modifyrgb(int x, t_data *data)
{
	x = (x < 121) ? 121 : x;
	x = (x > 275) ? 275 : x;
	if (data->clickedr)
		data->editedcolor->rgb.r = round((float)(x - 121) / 154 * 255);
	else if (data->clickedg)
		data->editedcolor->rgb.g = round((float)(x - 121) / 154 * 255);
	else if (data->clickedb)
		data->editedcolor->rgb.b = round((float)(x - 121) / 154 * 255);
	data->editedcolor->value = rgb_to_int(data->editedcolor->rgb);
	data->editedcolor->hsv = rgb_to_hsv(data->editedcolor->value);
	data->colorchanged = 1;
}

t_rgb			int_to_rgb(int c)
{
	t_rgb		rgb;

	rgb.r = c >> 16;
	rgb.g = (c >> 8) - ((c >> 16) * 0x100);
	rgb.b = c - ((c >> 8) * 0x100);
	return (rgb);
}

int				get_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	int			result;

	result = r;
	result = (result << 8) + g;
	result = (result << 8) + b;
	return (result);
}

int				rgb_to_int(t_rgb rgb)
{
	return (get_rgb(rgb.r, rgb.g, rgb.b));
}

int				get_closestcolor(t_color *color)
{
	t_hsv		hsv;

	hsv.h = color->hsv.h;
	hsv.s = 100;
	hsv.v = 100;
	return (hsv_to_rgb(hsv));
}
