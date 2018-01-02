/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:19:33 by toliver           #+#    #+#             */
/*   Updated: 2018/01/01 11:23:18 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				window_closed(t_data *data)
{
	(void)data;
	ft_error("Next time, use ESC !");
	return (0);
}

void			ft_triangleinit(t_data *data)
{
	data->triangle.a.x = 350;
	data->triangle.a.y = 0;
	data->triangle.b.x = 0;
	data->triangle.b.y = 700;
	data->triangle.c.x = 700;
	data->triangle.c.y = 700;
}

void			ft_setoffset(t_fractale *fra)
{
	fra->offset.r = (fra->maxx + fra->minx) / 2;
	fra->offset.i = (fra->maxy + fra->miny) / 2;
}

void			ft_fractset(t_data *data)
{
	data->julia->formula = &ft_julia;
	data->julia->minx = -2;
	data->julia->maxx = 2;
	data->julia->miny = -1.5;
	data->julia->maxy = 1.5;
	data->mandelbrot->formula = &ft_mandelbrot;
	data->mandelbrot->minx = -2.5;
	data->mandelbrot->maxx = 1.5;
	data->mandelbrot->miny = -1.5;
	data->mandelbrot->maxy = 1.5;
	data->burningship->formula = &ft_burningship;
	data->burningship->minx = -2.25;
	data->burningship->maxx = 1.75;
	data->burningship->miny = 1;
	data->burningship->maxy = -2;
	data->multibrot->formula = &ft_multibrot;
	data->multibrot->minx = -2;
	data->multibrot->maxx = 2;
	data->multibrot->miny = -1.5;
	data->multibrot->maxy = 1.5;
	data->glynn->formula = &ft_glynn;
	data->glynn->minx = 0.24;
	data->glynn->maxx = -0.24;
	data->glynn->miny = -0.355;
	data->glynn->maxy = -0.715;
	data->mandeldrop->formula = &ft_mandeldrop;
	data->mandeldrop->minx = -4;
	data->mandeldrop->maxx = 4;
	data->mandeldrop->miny = -1.75;
	data->mandeldrop->maxy = 4.25;
	data->mandelheart->formula = &ft_mandelheart;
	data->mandelheart->minx = -4;
	data->mandelheart->maxx = 4;
	data->mandelheart->miny = 3.75;
	data->mandelheart->maxy = -2.25;
	ft_setoffset(data->julia);
	ft_setoffset(data->mandelbrot);
	ft_setoffset(data->burningship);
	ft_setoffset(data->multibrot);
	ft_setoffset(data->glynn);
	ft_setoffset(data->mandeldrop);
	ft_setoffset(data->mandelheart);
}

int				main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init();
	mlx_hook(data->win, 2, 0, key_on, data);
	mlx_hook(data->win, 4, 0, button_on, data);
	mlx_hook(data->win, 5, 0, button_off, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	mlx_hook(data->win, 17, 0, window_closed, data);
	ft_refresh(data);
	mlx_loop(data->mlx);
	return (0);
}
