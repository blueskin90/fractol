/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:15:48 by toliver           #+#    #+#             */
/*   Updated: 2018/01/12 12:13:44 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			colorinit(t_data *data)
{
	data->color = (t_color*)ft_malloc(sizeof(t_color));
	data->color->value = 0x3d2900;
	data->color->index = 0;
	data->color->hover = 0;
	data->color->locked = 1;
	data->color->clicked = 0;
	data->color->rgb = int_to_rgb(data->color->value);
	data->color->hsv = rgb_to_hsv(0x3d2900);
	data->color->next = (t_color*)ft_malloc(sizeof(t_color));
	data->color->next->value = 0xfdc549;
	data->color->next->index = 1;
	data->color->next->hover = 0;
	data->color->next->locked = 1;
	data->color->next->clicked = 0;
	data->color->next->rgb = int_to_rgb(data->color->next->value);
	data->color->next->hsv = rgb_to_hsv(0xfdc549);
	data->color->next->next = NULL;
	data->colormenu = 0;
	data->editedcolor = NULL;
}

void			boolinit(t_data *data)
{
	data->menu = 0;
	data->colormenu = 0;
	data->clickedsquare = 0;
	data->clickedrainbow = 0;
	data->clickedr = 0;
	data->clickedg = 0;
	data->clickedb = 0;
	data->scrollmenuoffset = 0;
	data->colorchanged = 1;
	data->locked = 0;
	data->button[3] = 0;
	data->buttony[3] = 0;
	data->buttonx[3] = 0;
}

void			screeninit(t_data *data, int fra)
{
	data->onscreen = data->mandelbrot;
	data->screen[0] = data->julia;
	data->screen[1] = data->burningship;
	data->screen[2] = data->multibrot;
	data->screen[3] = data->glynn;
	data->screen[4] = data->mandeldrop;
	data->screen[5] = data->mandelheart;
	data->screen[6] = data->buddhabrot;
	if (fra != 0)
		ptrswap(&ONSCREEN, &data->screen[fra - 1], data);
}

t_data			*init(int fra)
{
	t_data	*data;

	data = (t_data*)ft_malloc(sizeof(t_data));
	if (!(data->mlx = mlx_init()))
		ft_error("Mlx init failed.");
	data->winx = 800;
	data->winy = 600;
	if (!(data->win =
				mlx_new_window(data->mlx, data->winx, data->winy, "fractol")))
		ft_error("New window creation failed.");
	data->img = NULL;
	fractinit(data);
	boolinit(data);
	ft_fractset(data);
	screeninit(data, fra);
	colorinit(data);
	mlx_img_init(data);
	return (data);
}
