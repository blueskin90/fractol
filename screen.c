/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:55:03 by toliver           #+#    #+#             */
/*   Updated: 2018/01/11 18:39:00 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			zoom(int zoom, int x, int y, t_data *data)
{
	t_complex	test;

	data->onscreen->zoompos = ft_mousecoord(x, y, data->onscreen, data);
	if (data->onscreen->zoom < 1 && zoom > 0)
		data->onscreen->zoom *= 1.1;
	else if (zoom <= 0)
		data->onscreen->zoom /= 1.1;
	test = ft_mousecoord(x, y, data->onscreen, data);
	data->onscreen->offset.r -= (test.r - data->onscreen->zoompos.r);
	data->onscreen->offset.i -= (test.i - data->onscreen->zoompos.i);
	if (zoom > 0 && data->onscreen->ite > 0)
		data->onscreen->ite -= 1;
	else
		data->onscreen->ite += 1;
	ONSCREEN->modified = 1;
}
