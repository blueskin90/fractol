/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:53:40 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:47:18 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_on(int keycode, t_data *data)
{
	if (keycode == 13)
		rotz(data, -0.5);
	if (keycode == 12)
		roty(data, 0.5);
	if (keycode == 14)
		roty(data, -0.5);
	if (keycode == 1)
		rotz(data, 0.5);
	if (keycode == 0)
		rotx(data, -0.5);
	if (keycode == 2)
		rotx(data, 0.5);
	if (keycode == 49)
		resetiso(data);
	if (keycode == 78)
		data->sca.z -= 0.05;
	if (keycode == 69)
		data->sca.z += 0.05;
	if (keycode == 2 || keycode == 0 || keycode == 1 || keycode == 14 ||
		keycode == 15 || keycode == 13 || keycode == 49 || keycode == 78 ||
		keycode == 69)
		maptoscreen(data);
	if (keycode == 53)
		exit(0);
	return (1);
}

int			resetiso(t_data *data)
{
	data->rot.x = 35.26;
	data->rot.y = 0;
	data->rot.z = 45;
	data->sca.z = 1;
	return (0);
}
