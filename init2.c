/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:12:25 by toliver           #+#    #+#             */
/*   Updated: 2018/01/09 14:25:31 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			img_init(t_fractale *fract, t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (!(fract->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		ft_error("fractal->img creation failed !\n");
	if (!(fract->img_str = mlx_get_data_addr(fract->img, &bpp, &sl, &endian)))
		ft_error("fractal->img_str creation failed !\n");
	if (!(fract->miniimg = mlx_new_image(data->mlx, fract->imgx, fract->imgy)))
		ft_error("fractal->miniimg creation failed !\n");
	if (!(fract->miniimg_str =
				mlx_get_data_addr(fract->miniimg, &bpp, &sl, &endian)))
		ft_error("fractal->miniimg_str creation failed !\n");
}

void			fractinit(t_data *data)
{
	data->mandelbrot = fractalinit(data);
	data->julia = fractalinit(data);
	data->julia->locked = 0;
	data->burningship = fractalinit(data);
	data->multibrot = fractalinit(data);
	data->multibrot->locked = 0;
	data->glynn = fractalinit(data);
	data->mandeldrop = fractalinit(data);
	data->mandelheart = fractalinit(data);
	data->buddhabrot = fractalinit(data);
	data->buddhabrot->ite = 100;
}

void			ft_fractset2(t_data *data)
{
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
	data->buddhabrot->formula = &ft_buddhabrot;
	data->buddhabrot->minx = -2.5;
	data->buddhabrot->maxx = 1.5;
	data->buddhabrot->miny = -1.5;
	data->buddhabrot->maxy = 1.5;
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
	ft_fractset2(data);
}

void			mlx_img_init(t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (!(data->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		exit(-1);
	if (!(data->img_str = mlx_get_data_addr(data->img, &bpp, &sl, &endian)))
		exit(-1);
}
