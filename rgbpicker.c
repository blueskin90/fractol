/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbpicker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:33:07 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:57:33 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		printrgbpreset(t_data *data, int x, int y)
{
	printemptyrectangle(data, ft_point(x - 1, y - 3), ft_point(3, 7), 0x000000);
	printemptyrectangle(data, ft_point(x - 2, y - 4), ft_point(5, 9), 0xffffff);
	ft_line(ft_point(x - 3, y - 3), ft_point(x - 3, y + 3), data, 0x000000);
	ft_line(ft_point(x + 3, y - 3), ft_point(x + 3, y + 3), data, 0x000000);
	ft_line(ft_point(x - 1, y - 5), ft_point(x + 1, y - 5), data, 0x000000);
	ft_line(ft_point(x - 1, y + 5), ft_point(x + 1, y + 5), data, 0x000000);
	px_to_onscreenimg(data, x - 2, y - 4, 0x000000);
	px_to_onscreenimg(data, x + 2, y - 4, 0x000000);
	px_to_onscreenimg(data, x - 2, y + 4, 0x000000);
	px_to_onscreenimg(data, x + 2, y + 4, 0x000000);
}

void		printrgbbar(t_data *data, t_point p, t_point s, int color)
{
	int		x;
	int		y;
	t_hsv	hsv;

	hsv.h = rgb_to_hsv(color).h;
	hsv.s = 100;
	hsv.v = 0;
	y = p.y;
	while (y < p.y + s.y)
	{
		x = p.x;
		while (x < p.x + s.x)
		{
			hsv.v = round((float)(x - p.x) / s.x * 100);
			px_to_onscreenimg(data, x, y, hsv_to_rgb(hsv));
			x++;
		}
		y++;
	}
}

int			rgbsliderpos(unsigned char value)
{
	return (round((float)value / 255 * 154 + 121));
}

void		printrgbslider(t_data *data, t_point p, t_point s, int color)
{
	printrectangle(data, p, s, 0x000000);
	printrectangle(data, ft_point(p.x + 1, p.y + 1),
			ft_point(s.x - 2, s.y - 2), 0xffffff);
	printrgbbar(data, ft_point(p.x + 2, p.y + 2),
			ft_point(s.x - 4, s.y - 4), color);
}

void		printrgbpicker(t_data *data)
{
	int		r;
	int		g;
	int		b;

	r = data->editedcolor->rgb.r;
	g = data->editedcolor->rgb.g;
	b = data->editedcolor->rgb.b;
	printcolorsquare(data, ft_point(94, 342), 19, get_rgb(r, 0, 0));
	printrgbslider(data, ft_point(119, 348), ft_point(159, 7), 0xff0000);
	printrgbpreset(data, rgbsliderpos(r), 351);
	printcolorsquare(data, ft_point(94, 367), 19, get_rgb(0, g, 0));
	printrgbslider(data, ft_point(119, 373), ft_point(159, 7), 0x00ff00);
	printrgbpreset(data, rgbsliderpos(g), 376);
	printcolorsquare(data, ft_point(94, 393), 19, get_rgb(0, 0, b));
	printrgbslider(data, ft_point(119, 399), ft_point(159, 7), 0x0000ff);
	printrgbpreset(data, rgbsliderpos(b), 402);
}
