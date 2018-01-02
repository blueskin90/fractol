/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printshapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:31:30 by toliver           #+#    #+#             */
/*   Updated: 2017/12/31 22:23:33 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	printlosange(t_data *data, t_point p, int size, int color)
{
	ft_line(ft_point(p.x - 6, p.y + 6), ft_point(p.x - 6, p.y + size - 6),
			data, color);
	ft_line(ft_point(p.x - 5, p.y + 5), ft_point(p.x - 5, p.y + size - 5),
			data, color);
	ft_line(ft_point(p.x - 4, p.y + 4), ft_point(p.x - 4, p.y + size - 4),
			data, color);
	ft_line(ft_point(p.x - 3, p.y + 3), ft_point(p.x - 3, p.y + size - 3),
			data, color);
	ft_line(ft_point(p.x - 2, p.y + 2), ft_point(p.x - 2, p.y + size - 2),
			data, color);
	ft_line(ft_point(p.x - 1, p.y + 1), ft_point(p.x - 1, p.y + size - 1),
			data, color);
	ft_line(ft_point(p.x, p.y), ft_point(p.x, p.y + size), data, color);
	ft_line(ft_point(p.x + 1, p.y + 1), ft_point(p.x + 1, p.y + size - 1),
			data, color);
	ft_line(ft_point(p.x + 2, p.y + 2), ft_point(p.x + 2, p.y + size - 2),
			data, color);
	ft_line(ft_point(p.x + 3, p.y + 3), ft_point(p.x + 3, p.y + size - 3),
			data, color);
	ft_line(ft_point(p.x + 4, p.y + 4), ft_point(p.x + 4, p.y + size - 4),
			data, color);
	ft_line(ft_point(p.x + 5, p.y + 5), ft_point(p.x + 5, p.y + size - 5),
			data, color);
	ft_line(ft_point(p.x + 6, p.y + 6), ft_point(p.x + 6, p.y + size - 6),
			data, color);
}

void	printrectangle(t_data *data, t_point pos, t_point size, int color)
{
	int	xi;
	int	yi;

	yi = pos.y;
	while (yi < pos.y + size.y)
	{
		xi = pos.x;
		while (xi < pos.x + size.x)
		{
			px_to_onscreenimg(data, xi, yi, color);
			xi++;
		}
		yi++;
	}
}

void	printsquare(t_data *data, t_point pos, int size, int color)
{
	int	xi;
	int	yi;

	yi = pos.y;
	while (yi < pos.y + size)
	{
		xi = pos.x;
		while (xi < pos.x + size)
		{
			px_to_onscreenimg(data, xi, yi, color);
			xi++;
		}
		yi++;
	}
}

void	printemptyrectangle(t_data *data, t_point p, t_point s, int color)
{
	ft_line(p, ft_point(p.x + s.x - 1, p.y), data, color);
	ft_line(p, ft_point(p.x, p.y + s.y - 1), data, color);
	ft_line(ft_point(p.x + s.x - 1, p.y + s.y - 1),
			ft_point(p.x + s.x - 1, p.y), data, color);
	ft_line(ft_point(p.x + s.x - 1, p.y + s.y - 1),
			ft_point(p.x, p.y + s.y - 1), data, color);
}

void	printcolorsquare(t_data *data, t_point p, int size, int color)
{
	printsquare(data, p, size, 0x000000);
	printsquare(data, ft_point(p.x + 1, p.y + 1), size - 2, 0xffffff);
	printsquare(data, ft_point(p.x + 2, p.y + 2), size - 4, color);
}
