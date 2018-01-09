/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:21:02 by toliver           #+#    #+#             */
/*   Updated: 2018/01/09 21:41:00 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				px_to_miniimg(t_fractale *fract, int x, int y, int c)
{
	fract->miniimg_str[x * 4 + y * fract->imgx * 4] = int_to_rgb(c).b;
	fract->miniimg_str[x * 4 + y * fract->imgx * 4 + 1] = int_to_rgb(c).g;
	fract->miniimg_str[x * 4 + y * fract->imgx * 4 + 2] = int_to_rgb(c).r;
	fract->miniimg_str[x * 4 + y * fract->imgx * 4 + 3] = 0;
}

void				px_to_onscreenimg(t_data *data, int x, int y, int c)
{
	data->onscreen->img_str[x * 4 + y * data->winx * 4] = int_to_rgb(c).b;
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 1] = int_to_rgb(c).g;
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 2] = int_to_rgb(c).r;
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = 0;
}

int					get_px_color(t_data *data, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = data->onscreen->img_str[x * 4 + y * data->winx * 4];
	g = data->onscreen->img_str[x * 4 + y * data->winx * 4 + 1];
	r = data->onscreen->img_str[x * 4 + y * data->winx * 4 + 2];
	return (get_rgb(r, g, b));
}

int					put_image_to_image(char *imgtoput,
		t_point imgp, t_point imgs, t_data *data)
{
	int				x;
	int				y;
	int				offset;

	offset = (imgp.y < 0) ? -imgp.y : 0;
	imgp.y = (imgp.y < 0) ? 0 : imgp.y;
	if (offset >= imgs.y - 1 || (y = -1) == 0)
		return (0);
	while (++y + offset < imgs.y)
	{
		if (y + imgp.y >= WINY || (x = -1) == 0)
			break ;
		while (++x < imgs.x)
		{
			ONSCREEN->img_str[(x + imgp.x) * 4 + (y + imgp.y) * WINX * 4] =
				imgtoput[x * 4 + (y + offset) * imgs.x * 4];
			ONSCREEN->img_str[(x + imgp.x) * 4 + (y + imgp.y) * WINX * 4 + 1] =
				imgtoput[x * 4 + (y + offset) * imgs.x * 4 + 1];
			ONSCREEN->img_str[(x + imgp.x) * 4 + (y + imgp.y) * WINX * 4 + 2] =
				imgtoput[x * 4 + (y + offset) * imgs.x * 4 + 2];
			ONSCREEN->img_str[(x + imgp.x) * 4 + (y + imgp.y) * WINX * 4 + 3] =
				imgtoput[x * 4 + (y + offset) * imgs.x * 4 + 3];
		}
	}
	return (0);
}

void				print_img(t_data *data)
{
	int				xinc;
	int				yinc;
	int				i;

	xinc = data->winx - 25 - data->winx / 6;
	yinc = data->onscreen->imgy + 25;
	if (data->menu == 1)
	{
		i = -1;
		while (++i < 7)
			put_image_to_image(data->screen[i]->miniimg_str, ft_point(xinc, 25 +
				data->scrollmenuoffset + i * yinc), ft_point(
					data->screen[i]->imgx, data->screen[i]->imgy), data);
		ft_printite(data);
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->onscreen->img, 0, 0);
}
