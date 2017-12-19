/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:13:22 by toliver           #+#    #+#             */
/*   Updated: 2017/12/15 22:45:10 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double		ft_checkvalue(t_complex comp)
{
	return (comp.r * comp.r + comp.i * comp.i);
}

long double		ft_mandelbrot(t_complex c, t_complex z, int ite)
{
	int				i;

	long double		retval;
	i = 0;
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			retval = (i + 1 - log(log(ft_checkvalue(z)))/log(2.0)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}
/*
void			ft_mandelbrot(t_data *data, t_fractale *fract)
{
	int			x;
	int			y;
	t_complex	c;
//	t_complex	z;

	(void)fract; // a suppr plus tard	
	y = 0;
//	z.r = 0;
//	z.i = 0;
	while (y < data->winy)
	{
		x = 0;
		while (x < data->winx)
		{
			c = ft_complex(x, y, data);
			ft_printcolor(ft_mandel(c, data->mandelbrot->c, data->mandelbrot->ite), data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
*/
