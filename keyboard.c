/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:21:23 by toliver           #+#    #+#             */
/*   Updated: 2018/01/09 17:39:34 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int keycode, t_data *data)
{
	int	x;
	int	y;

	if (keycode == 126 || keycode == 125)
		y = (keycode == 126) ? data->buttony[3] - 1 : data->buttony[3] + 1;
	else
		y = data->buttony[3];
	if (keycode == 123 || keycode == 124)
		x = (keycode == 123) ? data->buttonx[3] - 1 : data->buttonx[3] + 1;
	else
		x = data->buttonx[3];
	middlebuttonhandle(x, y, data);
}

void	iterationhandle(int keycode, t_data *data)
{
	int	*ite;

	ite = &ONSCREEN->ite;
	if (keycode == 69 && *ite < INT_MAX)
	{
		if (ONSCREEN == data->glynn)
			*ite = (*ite < (INT_MAX - 9)) ? *ite + 10 : INT_MAX;
		else if (ONSCREEN == data->buddhabrot)
			*ite = (*ite < (INT_MAX - 499)) ? *ite + 500 : INT_MAX;
		else
			*ite = (*ite < INT_MAX) ? *ite + 1 : *ite;
		data->colorchanged = 1;
	}
	if (keycode == 78 && *ite > 0)
	{
		if (ONSCREEN == data->glynn)
			*ite = (*ite < 10) ? 0 : *ite - 10;
		else if (ONSCREEN == data->buddhabrot)
			*ite = (*ite < 500) ? 0 : *ite - 500;
		else
			*ite = (*ite == 0) ? 0 : *ite - 1;
		data->colorchanged = 1;
	}
}

int		key_on(int keycode, t_data *data)
{
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		move(keycode, data);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		iterationhandle(keycode, data);
	if (keycode == 49)
		if (ONSCREEN == data->julia || ONSCREEN == data->multibrot)
			ONSCREEN->locked = (ONSCREEN->locked == 0 ? 1 : 0);
	if (keycode == 46)
	{
		data->colorchanged = 1;
		data->menu = (data->menu == 0) ? 1 : 0;
	}
	if (keycode == 69 || keycode == 78 || keycode == 46)
	{
		ft_refresh(data);
		ft_printite(data);
	}
	return (0);
}
