/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:49:02 by toliver           #+#    #+#             */
/*   Updated: 2017/12/15 20:37:59 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_data *data)
{
	int	y;
	int	x;		
	y = 0;

	if (data->menu == 1)
	{
		while (y < data->winy)
		{
			x = data->winx - data->onscreen->imgx - 50;
			while (x < data->winx)
			{
				data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = 40;
				x++;
			}
			y++;
		}
	}
}
