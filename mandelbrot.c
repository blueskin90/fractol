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

	comp.r = ((double)x - (double)(data->winx - 1) / 2) / ((double)(data->winx - 1)/ 2);
	comp.i = ((double)y - (double)(data->winy - 1) / 2) / ((double)(data->winy - 1)/ 2);

	return (comp);
}

t_complex		ft_cadd(t_complex c1, t_complex c2)
{
	c1.r += c2.r;
	c1.i += c2.i;
	return (c1);
}

t_complex		ft_csqr(t_complex comp)
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

t_complex		ft_fmandel(t_complex z, t_complex c)
{
	return (ft_cadd(ft_csqr(z), c));
}

int				ft_rmandel(t_complex c, t_complex z, int ite)
{
	z = ft_fmandel(z, c);
	if (ft_cmod(z) > 2)
		return (1); // outside of the range (might return different value for different colors)
	if (ite == 0)
		return (0);
	return (ft_rmandel(c, z, ite - 1)); 
}

void			ft_mandelbrot(t_data *data, int a, int b)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;
	
	x = 0;
	y = 0;
	z.r = 0;  // ici mettre position curseur pour julia
	z.i = 0; // ici mettre position curseur pour julia
	mlx_img_init(data);
	while (y < data->winy)
	{
		while (x < data->winx)
		{
			c = ft_cadd(ft_complex(x, y, data), ft_complex(a, b, data));
			if (ft_rmandel(c, z, 40) == 0) // inverser z et c pour julia
//				mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
				mlx_px_to_img(data, x, y, 0xffffff);
			else
//				mlx_pixel_put(data->mlx, data->win, x, y, 0x000000);
				mlx_px_to_img(data, x, y, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
