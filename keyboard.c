/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:21:23 by toliver           #+#    #+#             */
/*   Updated: 2026/02/22 20:16:45 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int keycode, t_data *data)
{
	int	x;
	int	y;

	if (data->onscreen == data->buddhabrot)
		return ;
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
	if (keycode == 69 && *ite < INT_MAX && data->locked == 0)
	{
		if (ONSCREEN == data->glynn)
			*ite = (*ite < (INT_MAX - 9)) ? *ite + 10 : INT_MAX;
		else if (ONSCREEN == data->buddhabrot)
			*ite = (*ite < (INT_MAX - 249)) ? *ite + 250 : INT_MAX;
		else
			*ite = (*ite < INT_MAX) ? *ite + 1 : *ite;
		ONSCREEN->modified = 1;
	}
	if (keycode == 78 && *ite > 0 && data->locked == 0)
	{
		if (ONSCREEN == data->glynn)
			*ite = (*ite < 10) ? 0 : *ite - 10;
		else if (ONSCREEN == data->buddhabrot)
			*ite = (*ite < 250) ? 0 : *ite - 250;
		else
			*ite = (*ite == 0) ? 0 : *ite - 1;
		ONSCREEN->modified = 1;
	}
}

int		key_on(int keycode, t_data *data)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		move(keycode, data);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		iterationhandle(keycode, data);
	if (keycode == 49)
		if (ONSCREEN == data->julia || ONSCREEN == data->multibrot)
			ONSCREEN->locked = (ONSCREEN->locked == 0 ? 1 : 0);
	if (keycode == 109)
	{
		data->colorchanged = 1;
		data->menu = (data->menu == 0) ? 1 : 0;
	}
	if (keycode == 69 || keycode == 78 || keycode == 46 || keycode == 109)
	{
		ft_refresh(data);
		ft_printite(data);
	}
	return (0);
}
