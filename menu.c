/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:49:02 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:55:38 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			colorpicker(t_point pos, int size, int color)
{
	int		r;
	int		g;
	int		b;

	r = int_to_rgb(color).r;
	g = int_to_rgb(color).g;
	b = int_to_rgb(color).b;
	r = 255 - ((255 - r) * ((float)pos.x / (size - 1)));
	g = 255 - ((255 - g) * ((float)pos.x / (size - 1)));
	b = 255 - ((255 - b) * ((float)pos.x / (size - 1)));
	r = r * ((float)(size - 1 - pos.y) / (size - 1));
	g = g * ((float)(size - 1 - pos.y) / (size - 1));
	b = b * ((float)(size - 1 - pos.y) / (size - 1));
	return (get_rgb(r, g, b));
}

void		printcolorpicker(t_data *data, t_point pos, int size, int color)
{
	int	xi;
	int	yi;

	yi = pos.y;
	while (yi < pos.y + size)
	{
		xi = pos.x;
		while (xi < pos.x + size)
		{
			px_to_onscreenimg(data, xi, yi, colorpicker(
						ft_point(xi - pos.x, yi - pos.y), size, color));
			xi++;
		}
		yi++;
	}
}

void		colormenu(t_data *data)
{
	printvabar(data, 300, 50, 40);
	printsquare(data, ft_point(94, 98), 184, 0x000000);
	printsquare(data, ft_point(95, 99), 182, 0xffffff);
	printcolorpicker(data, ft_point(96, 100), 180,
			get_closestcolor(data->editedcolor));
	printcolorpickerpreset(data, colorpickerpresetpos(data->editedcolor->hsv));
	printrectangle(data, ft_point(298, 98), ft_point(10, 184), 0x000000);
	printrectangle(data, ft_point(299, 99), ft_point(8, 182), 0xffffff);
	printrainbowgradient(data, ft_point(300, 100), ft_point(6, 180));
	printcolorsquare(data, ft_point(94, 302), 30, data->editedcolor->value);
	printrgbpicker(data);
	printrainbowpreset(data);
}

void		gradientmenu(t_data *data)
{
	t_color	*tmp;

	tmp = data->color;
	printvabar(data, 50, 0, 40);
	printvabar(data, data->onscreen->imgx + 50,
			data->winx - (data->onscreen->imgx + 50), 40);
	printgradient(data);
	while (tmp)
	{
		if (tmp->locked == 1)
			printlockedpreset(data, 19, 22 + round(tmp->index *
						(data->winy - 45)), tmp->value);
		else if (tmp->clicked == 1)
			printclickpreset(data, 19, 22 + round(tmp->index *
						(data->winy - 45)), tmp->value);
		else if (tmp->hover == 1 && tmp->clicked == 0)
			printbigpreset(data, 19, 22 + round(tmp->index *
						(data->winy - 45)), tmp->value);
		else
			printpreset(data, 19, 22 + round(tmp->index * (data->winy - 45))
					, tmp->value);
		tmp = tmp->next;
	}
}

void		menu(t_data *data)
{
	if (data->menu == 1)
	{
		gradientmenu(data);
		if (data->colormenu == 1)
			colormenu(data);
	}
}
