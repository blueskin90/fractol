/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printashapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:32:06 by toliver           #+#    #+#             */
/*   Updated: 2017/12/26 03:30:11 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	printhabar(t_data *data, int width, int offset, int alphaval)
{
	int	y;
	int	x;
	int limit;

	limit = offset + width;
	y = offset;
	while (y < limit)
	{
		x = 0;
		while (x < data->winx)
		{
			data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = alphaval;
			x++;
		}
		y++;
	}
}

void	printvabar(t_data *data, int width, int offset, int alphaval)
{
	int	y;
	int	x;
	int limit;

	limit = offset + width;
	y = 0;
	while (y < data->winy)
	{
		x = offset;
		while (x < limit)
		{
			data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = alphaval;
			x++;
		}
		y++;
	}
}

void	printarectangle(t_data *data, t_point coord, t_point size, int alphaval)
{
	int	y;
	int	x;

	y = coord.y;
	while (y < coord.y + size.y)
	{
		x = coord.x;
		while (x < coord.x + size.x)
		{
			data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = alphaval;
			x++;
		}
		y++;
	}
}
