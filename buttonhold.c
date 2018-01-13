/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttonhold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:40:10 by toliver           #+#    #+#             */
/*   Updated: 2018/01/11 20:51:48 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				leftbuttonhandle(int x, int y, t_data *data)
{
	if (data->buttonx[1] != x || data->buttony[1] != y)
	{
		if (data->clickedsquare == 1)
			modifysv(x, y, data);
		else if (data->clickedrainbow == 1)
			modifyhue(y, data);
		else if (movingpresets(y, data))
			ft_reorganize_colors(data);
		else if (data->clickedr || data->clickedg || data->clickedb)
			modifyrgb(x, data);
		ft_refresh(data);
	}
	return (1);
}

int				middlebuttonhandle(int x, int y, t_data *data)
{
	t_complex	test;
	t_complex	test2;

	test = ft_coord(x, y, data->onscreen, data);
	test2 = ft_coord(data->buttonx[3], data->buttony[3], data->onscreen, data);
	if (data->buttonx[3] != x)
	{
		data->onscreen->tran.r += test.r - test2.r;
		data->buttonx[3] = x;
		ONSCREEN->modified = 1;
	}
	if (data->buttony[3] != y)
	{
		data->onscreen->tran.i += test.i - test2.i;
		data->buttony[3] = y;
		ONSCREEN->modified = 1;
	}
	ft_refresh(data);
	return (1);
}

void			menuhandle(int x, int y, t_data *data)
{
	int			i;

	i = -1;
	if (x >= data->winx - data->onscreen->imgx - 25 && x <= data->winx - 25)
	{
		y = y - data->scrollmenuoffset - 25;
		while (++i < 7)
			if (y >= i * 25 + i * data->onscreen->imgy &&
					y <= i * 25 + (i + 1) * data->onscreen->imgy)
			{
				ONSCREEN->modified = 1;
				data->screen[i]->modified = 1;
				ptrswap(&data->onscreen, &data->screen[i], data);
				ft_refresh(data);
				break ;
			}
	}
	else if (x >= 0 && x <= 50 && y >= 22 && y <= data->winy - 22 &&
			ft_clickget(data, x, y) == 0)
		coloradd(data, get_px_color(data, 15, y), (float)(y - 22) /
				(data->winy - 44));
}

void			rgbmenuhandle(int x, int y, t_data *data)
{
	if (y >= 350 && y <= 356)
	{
		data->clickedr = 1;
		data->editedcolor->rgb.r = round((float)(x - 121) / 154 * 255);
		data->editedcolor->value = rgb_to_int(data->editedcolor->rgb);
		data->editedcolor->hsv = rgb_to_hsv(data->editedcolor->value);
		data->colorchanged = 1;
	}
	else if (y >= 375 && y <= 381)
	{
		data->clickedg = 1;
		data->editedcolor->rgb.g = round((float)(x - 121) / 154 * 255);
		data->editedcolor->value = rgb_to_int(data->editedcolor->rgb);
		data->editedcolor->hsv = rgb_to_hsv(data->editedcolor->value);
		data->colorchanged = 1;
	}
	else if (y >= 401 && y <= 407)
	{
		data->clickedb = 1;
		data->editedcolor->rgb.b = round((float)(x - 121) / 154 * 255);
		data->editedcolor->value = rgb_to_int(data->editedcolor->rgb);
		data->editedcolor->hsv = rgb_to_hsv(data->editedcolor->value);
		data->colorchanged = 1;
	}
}

void			colormenuhandle(int x, int y, t_data *data)
{
	if (x >= 96 && x <= 275 && y >= 100 && y <= 100 + 179)
	{
		data->clickedsquare = 1;
		data->editedcolor->hsv.s = ((float)(x - 96) / 179 * 100);
		data->editedcolor->hsv.v = ((float)(279 - y) / 179 * 100);
		data->editedcolor->value = hsv_to_rgb(data->editedcolor->hsv);
		data->colorchanged = 1;
	}
	else if (x >= 300 && x <= 305 && y >= 100 && y <= 100 + 179)
	{
		data->clickedrainbow = 1;
		data->editedcolor->hsv.h = ((float)(279 - y) / 179 * 359);
		data->editedcolor->value = hsv_to_rgb(data->editedcolor->hsv);
		data->colorchanged = 1;
	}
	else if (x >= 121 && x <= 276 && y >= 350 && y <= 407)
		rgbmenuhandle(x, y, data);
}
