/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:03:23 by toliver           #+#    #+#             */
/*   Updated: 2018/01/01 05:16:05 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_mov(int x, int y, t_data *data)
{
	if (data->button[1] == 1)
		leftbuttonhandle(x, y, data);
	else if (data->button[3] == 1)
		middlebuttonhandle(x, y, data);
	if (data->julia->locked == 0)
		data->julia->c = ft_coord(x, y, data->onscreen, data);
	if (data->multibrot->locked == 0)
		data->multibrot->c = ft_comp((abs(x) + 1.00) / data->winx * 10 + 1, 0);
	ft_hoverget(data, x, y);
	ft_refresh(data);
	return (1);
}
