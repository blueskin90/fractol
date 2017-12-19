/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:21:02 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 08:44:14 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				RGB(unsigned char r, unsigned char g, unsigned char b)
{
	int			result;

	
	result = r;
	result = (result << 8) + g;
	result = (result << 8) + b;
	return (result);
}

unsigned char	get_color(int c, char color)
{
	if (color == 'r')
		return (c >> 16);
	if (color == 'g')
		return ((c >> 8) - ((c >> 16) * 0x100));
	if (color == 'b')
		return (c - ((c >> 8) * 0x100));
	else
	{
		ft_putendl("Apprends a utiliser ta propre fonction.");
		exit(-1);
	}
}

void	px_to_miniimg(t_fractale *fract, int x, int y, int c)
{
	fract->miniimg_str[x * 4 + y * fract->imgx * 4] = get_color(c, 'b');
	fract->miniimg_str[x * 4 + y * fract->imgx * 4 + 1] = get_color(c, 'g');
	fract->miniimg_str[x * 4 + y * fract->imgx * 4 + 2] = get_color(c, 'r');
	fract->miniimg_str[x * 4 + y * fract->imgx * 4 + 3] = 0;
}

void	px_to_onscreenimg(t_data *data, int x, int y, int c)
{
	data->onscreen->img_str[x * 4 + y * data->winx * 4] = get_color(c, 'b');
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 1] = get_color(c, 'g');
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 2] = get_color(c, 'r');
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = 0;
}

void	mlx_img_init(t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (!(data->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		exit(-1);
	if (!(data->img_str = mlx_get_data_addr(data->img, &bpp, &sl, &endian)))
		exit(-1);
}

void			print_img(t_data *data)
{
	int			xinc;
	int			yinc;

	xinc = data->winx - 25 - data->winx / 6;
	yinc = data->winy / 6 + 25;
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->onscreen->img, 0, 0);
	if (data->menu == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->screen1->miniimg,
				xinc,25);
		mlx_put_image_to_window(data->mlx, data->win, data->screen2->miniimg,
				xinc,25 + yinc);
		mlx_put_image_to_window(data->mlx, data->win, data->screen3->miniimg,
				xinc,25 + 2 * yinc);
	}
	ft_printite(data);
}
