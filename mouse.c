/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:03:23 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 08:48:39 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_mov(int x, int y, t_data *data)
{
		if (data->button[3] == 1)
			middlebuttonhandle(x, y, data);
		if (data->julia->locked == 0)
			data->julia->c = ft_complex(x, y, data);
//	data->mandelbrot->c = ft_complex(x, y, data);
//	data->burningship->c = ft_complex(x, y, data);
		ft_refresh(data);
	return (1);
}
