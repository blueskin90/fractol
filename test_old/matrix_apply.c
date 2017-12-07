/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 02:32:04 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:53:57 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				rotx(t_data *data, double value)
{
	data->rot.x += value;
	if (data->rot.x < -180)
		data->rot.x = 180 - value;
	else if (data->rot.x > 180)
		data->rot.x = -180 + value;
	return (1);
}

int				roty(t_data *data, double value)
{
	data->rot.y += value;
	if (data->rot.y < -180)
		data->rot.y = 180 - value;
	else if (data->rot.y > 180)
		data->rot.y = -180 + value;
	return (1);
}

int				rotz(t_data *data, double value)
{
	data->rot.z += value;
	if (data->rot.z < -180)
		data->rot.z = 180 - value;
	else if (data->rot.z > 180)
		data->rot.z = -180 + value;
	return (1);
}

int				scale(t_data *data, double value)
{
	data->sca.x *= value;
	data->sca.y *= value;
	return (1);
}
