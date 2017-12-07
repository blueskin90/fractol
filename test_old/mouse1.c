/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 04:45:54 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:58:10 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_mov(int x, int y, t_data *data)
{
	int			i;

	i = 0;
	while (!data->button[i] && i < 7)
		i++;
	if (i == 7)
		return (1);
	if (data->button[i] == 1 && i == 1)
		left_button(x, y, data, i);
	if (data->button[i] == 1 && i == 2)
		right_button(x, y, data, i);
	if (data->button[i] == 1 && i == 3)
		middle_button(x, y, data, i);
	return (1);
}

int		right_button(int x, int y, t_data *data, int i)
{
	(void)y;
	if (data->buttonx[i] != x)
	{
		data->rot.z += (data->buttonx[i] - x) / data->sca.x;
		data->buttonx[i] = x;
	}
	maptoscreen(data);
	return (1);
}

int		middle_button(int x, int y, t_data *data, int i)
{
	if (data->buttonx[i] != x)
	{
		data->tran.x -= (data->buttonx[i] - x) / data->sca.x;
		data->buttonx[i] = x;
	}
	if (data->buttony[i] != y)
	{
		data->tran.y -= (data->buttony[i] - y) / data->sca.y;
		data->buttony[i] = y;
	}
	maptoscreen(data);
	return (1);
}

int		left_button(int x, int y, t_data *data, int i)
{
	if (data->buttonx[i] != x)
	{
		data->rot.y -= ((data->buttonx[i] - x) / data->sca.x);
		data->buttonx[i] = x;
	}
	if (data->buttony[i] != y)
	{
		data->rot.x += ((data->buttony[i] - y) / data->sca.y);
		data->buttony[i] = y;
	}
	maptoscreen(data);
	return (1);
}
