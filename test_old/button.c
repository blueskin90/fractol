/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:57:31 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:58:09 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		button_on(int button, int x, int y, t_data *data)
{
	data->button[button] = 1;
	data->buttonx[button] = x;
	data->buttony[button] = y;
	if (button == 4)
	{
		scale(data, 1.1);
		maptoscreen(data);
	}
	if (button == 5)
	{
		scale(data, (double)10 / 11);
		maptoscreen(data);
	}
	return (1);
}

int		button_off(int button, int x, int y, t_data *data)
{
	data->button[button] = 0;
	data->buttonx[button] = x;
	data->buttony[button] = y;
	return (1);
}
