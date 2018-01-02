/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpreset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:40:39 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 01:28:32 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		printrainbowpreset(t_data *data)
{
	int y;

	y = (float)(359 - data->editedcolor->hsv.h) / 359 * 179 + 100;
	ft_line(ft_point(300 - 2, y - 3), ft_point(300 + 7, y - 3), data, 0x000000);
	ft_line(ft_point(300 - 2, y - 2), ft_point(300 + 7, y - 2), data, 0xffffff);
	ft_line(ft_point(300 - 2, y - 1), ft_point(300 + 7, y - 1), data, 0x000000);
	ft_line(ft_point(300 - 2, y + 1), ft_point(300 + 7, y + 1), data, 0x000000);
	ft_line(ft_point(300 - 2, y + 2), ft_point(300 + 7, y + 2), data, 0xffffff);
	ft_line(ft_point(300 - 2, y + 3), ft_point(300 + 7, y + 3), data, 0x000000);
	ft_line(ft_point(300 - 3, y - 1), ft_point(300 - 3, y + 1), data, 0xffffff);
	ft_line(ft_point(300 - 4, y - 1), ft_point(300 - 4, y + 1), data, 0x000000);
	ft_line(ft_point(300 + 8, y - 1), ft_point(300 + 8, y + 1), data, 0xffffff);
	ft_line(ft_point(300 + 9, y - 1), ft_point(300 + 9, y + 1), data, 0x000000);
	px_to_onscreenimg(data, 300 - 3, y - 2, 0x000000);
	px_to_onscreenimg(data, 300 - 3, y + 2, 0x000000);
	px_to_onscreenimg(data, 300 + 8, y - 2, 0x000000);
	px_to_onscreenimg(data, 300 + 8, y + 2, 0x000000);
}

void		printcolorpickerpreset(t_data *dat, t_point p)
{
	px_to_onscreenimg(dat, p.x - 2, p.y - 2, 0xffffff);
	px_to_onscreenimg(dat, p.x + 2, p.y - 2, 0xffffff);
	px_to_onscreenimg(dat, p.x + 2, p.y + 2, 0xffffff);
	px_to_onscreenimg(dat, p.x - 2, p.y + 2, 0xffffff);
	ft_line(ft_point(p.x - 1, p.y - 3), ft_point(p.x + 1, p.y - 3), dat,
			0xffffff);
	ft_line(ft_point(p.x - 1, p.y + 3), ft_point(p.x + 1, p.y + 3), dat,
			0xffffff);
	ft_line(ft_point(p.x - 3, p.y - 1), ft_point(p.x - 3, p.y + 1), dat,
			0xffffff);
	ft_line(ft_point(p.x + 3, p.y - 1), ft_point(p.x + 3, p.y + 1), dat,
			0xffffff);
	px_to_onscreenimg(dat, p.x - 3, p.y - 2, 0x000000);
	px_to_onscreenimg(dat, p.x + 3, p.y - 2, 0x000000);
	px_to_onscreenimg(dat, p.x + 3, p.y + 2, 0x000000);
	px_to_onscreenimg(dat, p.x - 3, p.y + 2, 0x000000);
	px_to_onscreenimg(dat, p.x - 2, p.y - 3, 0x000000);
	px_to_onscreenimg(dat, p.x + 2, p.y - 3, 0x000000);
	px_to_onscreenimg(dat, p.x + 2, p.y + 3, 0x000000);
	px_to_onscreenimg(dat, p.x - 2, p.y + 3, 0x000000);
	ft_line(ft_point(p.x - 1, p.y - 4), ft_point(p.x + 1, p.y - 4), dat, 0);
	ft_line(ft_point(p.x - 1, p.y + 4), ft_point(p.x + 1, p.y + 4), dat, 0);
	ft_line(ft_point(p.x - 4, p.y - 1), ft_point(p.x - 4, p.y + 1), dat, 0);
	ft_line(ft_point(p.x + 4, p.y - 1), ft_point(p.x + 4, p.y + 1), dat, 0);
}

t_point		colorpickerpresetpos(t_hsv hsv)
{
	return (ft_point(hsv.s / 100 * 179 + 96, (100.00 - hsv.v) / 100 * 179
				+ 100));
}
