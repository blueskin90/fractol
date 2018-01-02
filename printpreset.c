/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpreset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:36:02 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 01:31:15 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	printarrow(t_data *data, t_point p, int color)
{
	ft_line(ft_point(p.x - 2, p.y - 3), ft_point(p.x, p.y - 3), data, color);
	ft_line(ft_point(p.x - 4, p.y - 2), ft_point(p.x, p.y - 2), data, color);
	ft_line(ft_point(p.x - 6, p.y - 1), ft_point(p.x, p.y - 1), data, color);
	ft_line(ft_point(p.x - 7, p.y), ft_point(p.x, p.y), data, color);
	ft_line(ft_point(p.x - 6, p.y + 1), ft_point(p.x, p.y + 1), data, color);
	ft_line(ft_point(p.x - 4, p.y + 2), ft_point(p.x, p.y + 2), data, color);
	ft_line(ft_point(p.x - 2, p.y + 3), ft_point(p.x, p.y + 3), data, color);
}

void	printlockedpreset(t_data *data, int x, int y, int color)
{
	printarrow(data, ft_point(x + 3, y), 0x4d4d4d);
	printarrow(data, ft_point(x + 5, y), 0x4d4d4d);
	printarrow(data, ft_point(x + 7, y), color);
	printcircle(ft_point(x + 11, y), 10, data, 0x4d4d4d);
	printcircle(ft_point(x + 11, y), 9, data, 0x4d4d4d);
	printcircle(ft_point(x + 11, y), 8, data, color);
	printlosange(data, ft_point(x + 11, y - 6), 12, color);
	px_to_onscreenimg(data, x + 4, y - 4, color);
	px_to_onscreenimg(data, x + 4, y + 4, color);
	px_to_onscreenimg(data, x + 7, y - 7, color);
	px_to_onscreenimg(data, x + 7, y + 7, color);
	px_to_onscreenimg(data, x + 15, y - 7, color);
	px_to_onscreenimg(data, x + 15, y + 7, color);
	px_to_onscreenimg(data, x + 18, y - 4, color);
	px_to_onscreenimg(data, x + 18, y + 4, color);
}

void	printpreset(t_data *data, int x, int y, int color)
{
	printarrow(data, ft_point(x + 3, y), 0);
	printarrow(data, ft_point(x + 5, y), 0xffffff);
	printarrow(data, ft_point(x + 7, y), color);
	printcircle(ft_point(x + 11, y), 9, data, 0);
	printcircle(ft_point(x + 11, y), 8, data, 0xffffff);
	printcircle(ft_point(x + 11, y), 7, data, color);
	printlosange(data, ft_point(x + 11, y - 5), 10, color);
	px_to_onscreenimg(data, x + 6, y - 5, color);
	px_to_onscreenimg(data, x + 6, y + 5, color);
	px_to_onscreenimg(data, x + 16, y - 5, color);
	px_to_onscreenimg(data, x + 16, y + 5, color);
}

void	printbigpreset(t_data *data, int x, int y, int color)
{
	printarrow(data, ft_point(x + 3, y), 0);
	printarrow(data, ft_point(x + 5, y), 0xffffff);
	printarrow(data, ft_point(x + 7, y), color);
	printcircle(ft_point(x + 11, y), 10, data, 0);
	printcircle(ft_point(x + 11, y), 9, data, 0xffffff);
	printcircle(ft_point(x + 11, y), 8, data, color);
	printlosange(data, ft_point(x + 11, y - 6), 12, color);
	px_to_onscreenimg(data, x + 4, y - 4, color);
	px_to_onscreenimg(data, x + 4, y + 4, color);
	px_to_onscreenimg(data, x + 7, y - 7, color);
	px_to_onscreenimg(data, x + 7, y + 7, color);
	px_to_onscreenimg(data, x + 15, y - 7, color);
	px_to_onscreenimg(data, x + 15, y + 7, color);
	px_to_onscreenimg(data, x + 18, y - 4, color);
	px_to_onscreenimg(data, x + 18, y + 4, color);
}

void	printclickpreset(t_data *data, int x, int y, int color)
{
	printarrow(data, ft_point(x + 3, y), 0xff0000);
	printarrow(data, ft_point(x + 5, y), 0xffffff);
	printarrow(data, ft_point(x + 7, y), color);
	printcircle(ft_point(x + 11, y), 10, data, 0xff0000);
	printcircle(ft_point(x + 11, y), 9, data, 0xffffff);
	printcircle(ft_point(x + 11, y), 8, data, color);
	printlosange(data, ft_point(x + 11, y - 6), 12, color);
	px_to_onscreenimg(data, x + 4, y - 4, color);
	px_to_onscreenimg(data, x + 4, y + 4, color);
	px_to_onscreenimg(data, x + 7, y - 7, color);
	px_to_onscreenimg(data, x + 7, y + 7, color);
	px_to_onscreenimg(data, x + 15, y - 7, color);
	px_to_onscreenimg(data, x + 15, y + 7, color);
	px_to_onscreenimg(data, x + 18, y - 4, color);
	px_to_onscreenimg(data, x + 18, y + 4, color);
}
