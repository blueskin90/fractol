/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:21:02 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:54:25 by toliver          ###   ########.fr       */
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

void				mlx_img_init(t_data *data)
{
	int				bpp;
	int				sl;
	int				endian;

	if (!(data->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		exit(-1);
	if (!(data->img_str = mlx_get_data_addr(data->img, &bpp, &sl, &endian)))
		exit(-1);
}

/*
void				print_testcircle(t_data *data)
{
	float			stepsx;
	float			stepsy;
	int				i;

	stepsx = data->onscreen->maxx - data->onscreen->minx;
	stepsy = data->onscreen->maxy - data->onscreen->miny;

	stepsx *= 10;	
	stepsy *= 10;	
	stepsy -= 10;
	i = 0;
	while (i < stepsy + 1)
	{
		if (i % 10 == 0)
			printemptycircle(ft_point((float)data->winx / 2, 299), (data->winx / stepsx) * (i), data, 0xff0000);
		else if (i % 5 == 0)
			printemptycircle(ft_point((float)data->winx / 2, 299), (data->winx / stepsx) * (i), data, 0xff00ff);
		else
			printemptycircle(ft_point((float)data->winx / 2, 299), (data->winx / stepsx) * (i), data, 0xffffff);
		i++;
	}
}

void				print_powerline(t_data *data)
{
	float			stepsx;
	int				i;

	stepsx = (float)(data->winx + 1) / 10;

	i = 0;
	while (i < 10)
	{
		ft_line(ft_point((float)stepsx * (i + 1), 250), ft_point((float)stepsx * (i + 1), 350), data, 0xffffff);
		i++;
	}

}

void				print_testline(t_data *data)
{
	float			stepsx;
	float			stepsy;
	int				i;

	stepsx = data->onscreen->maxx - data->onscreen->minx;
	stepsy = data->onscreen->maxy - data->onscreen->miny;
	if ((int)stepsy % 2 == 1)
		stepsy *= 2;

	i = 0;
	while (i < stepsx)
	{
		ft_line(ft_point((float)data->winx/ stepsx * (i + 1), 250), ft_point((float)data->winx / stepsx * (i + 1), 350), data, 0xffffff);
		i++;
	}

	stepsx *= 2;
	i = 0;
while (i < stepsx)
	{
		ft_line(ft_point((float)data->winx/ stepsx * (i + 1), 280), ft_point((float)data->winx / stepsx * (i + 1), 320), data, 0xffffff);
		i++;
	}
	stepsx *= 5;
	i = 0;
while (i < stepsx)
	{
		ft_line(ft_point((float)data->winx/ stepsx * (i + 1), 295), ft_point((float)data->winx / stepsx * (i + 1), 305), data, 0xffffff);
		i++;
	}

	i = 0;
	while (i < stepsy)
	{
		ft_line(ft_point(350, (float)data->winy/ stepsy * (i + 1)), ft_point(450, (float)data->winy / stepsy * (i + 1)), data, 0xffffff);
		i+=2;
	}
	
	i = 0;
	while (i < stepsy)
	{
		ft_line(ft_point(380, (float)data->winy/ stepsy * (i + 1)), ft_point(420, (float)data->winy / stepsy * (i + 1)), data, 0xffffff);
		i+=1;
	}
	stepsy *= 5;
	i = 0;
	while (i < stepsy)
	{
		ft_line(ft_point(395, (float)data->winy/ stepsy * (i + 1)), ft_point(405, (float)data->winy / stepsy * (i + 1)), data, 0xffffff);
		i+=1;
	}
}
*/

int				put_image_to_image(char *imgtoput,
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
//	print_testcircle(data);
//	print_testline(data);
//	print_powerline(data);
//	mlx_clear_window(data->mlx, data->win);
//	mlx_put_image_to_window(data->mlx, data->win, data->onscreen->img, 0, 0);
	if (data->menu == 1)
	{
		i = -1;
		while (++i < 6)
			put_image_to_image(data->screen[i]->miniimg_str, ft_point(xinc, 25 + data->scrollmenuoffset + i * yinc), ft_point(data->screen[i]->imgx, data->screen[i]->imgy), data);
		ft_printite(data);
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->onscreen->img, 0, 0);
}
