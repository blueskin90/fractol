/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:15:48 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 18:47:57 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractale		*fractalinit(t_data *data)
{
	t_fractale	*fract;

	fract = (t_fractale*)ft_malloc(sizeof(t_fractale));
	fract->zoompos.r = 0;
	fract->zoompos.i = 0;
	fract->offset.r = 0;
	fract->offset.i = 0;
	fract->tran.r = 0;
	fract->tran.i = 0;
	fract->zoom = 1;
	fract->ite = 50;
	fract->c = ft_comp(0, 0);
	fract->imgx = data->winx / 6;
	fract->imgy = (data->winy - 125) / 5;
	fract->locked = 1;
	img_init(fract, data);
	return (fract);
}

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
}

void			screeninit(t_data *data)
{
	data->onscreen = data->julia;
	data->screen[0] = data->mandelbrot;
	data->screen[1] = data->burningship;
	data->screen[2] = data->multibrot;
	data->screen[3] = data->glynn;
	data->screen[4] = data->mandeldrop;
	data->screen[5] = data->mandelheart;
}

t_data			*init(void)
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
	data->mandelbrot = fractalinit(data);
	data->julia = fractalinit(data);
	data->julia->locked = 0;
	data->burningship = fractalinit(data);
	data->multibrot = fractalinit(data);
	data->multibrot->locked = 0;
	data->glynn = fractalinit(data);
	data->mandeldrop = fractalinit(data);
	data->mandelheart = fractalinit(data);
	boolinit(data);
	ft_fractset(data);
//	ft_triangleinit(data);
	screeninit(data);
	colorinit(data);
	mlx_img_init(data);
	return (data);
}
