/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:13:22 by toliver           #+#    #+#             */
/*   Updated: 2017/12/08 21:39:46 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_complex(int x, int y, t_data *data)
{
	t_complex	comp;

	comp.r = (double)x / (data->winx - 1);
	comp.i = (double)y / (data->winy - 1);
	return (comp);
}

t_complex		ft_compadd(t_complex c1, t_complex c2)
{
	c1.r += c2.r;
	c1.i += c2.i;
	return (c1);
}

t_complex		ft_compsqr(t_complex comp)
{
	double	tmp;

	tmp = comp.r;
	comp.r = comp.r * comp.r - comp.i * comp.i;
	comp.i = 2 * tmp * comp.i;
	return (comp);
}

double			ft_cmod(t_complex comp)
{
	return (sqrt(comp.r * comp.r + comp.i * comp.i));
}

t_complex		ft_formula(t_complex z, t_complex c)
{
	return (ft_compadd(ft_compsqr(z), c));
}

void			ft_mandelbrot(t_data *data)
{
	int			x;
	int			y;
	t_complex	c;
	
	x = 0;
	y = 0;
	c.r = 350 / data->winx;
	c.i = 350 / data->winy;

	(void)data;
	while (y < data->winy)
	{
		while (x < data->winx)
		{
			if (ft_cmod(ft_formula(ft_complex(x, y, data), c)) < 4 && ft_cmod(ft_formula(ft_complex(x, y, data), c)) > -4)
				mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
			else
				mlx_pixel_put(data->mlx, data->win, x, y, 0x000000);
			x++;
			x++;
		}
		x = 0;
		y++;
	}
}
