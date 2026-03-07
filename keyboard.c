/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:21:23 by toliver           #+#    #+#             */
/*   Updated: 2026/03/07 13:35:04 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/keysym.h>

void	move(int keycode, t_data *data)
{
	int	x;
	int	y;

	if (data->onscreen == data->buddhabrot)
		return ;
	if (keycode == XK_Down || keycode == XK_Up)
		y = (keycode == XK_Up) ? data->buttony[3] - 1 : data->buttony[3] + 1;
	else
		y = data->buttony[3];
	if (keycode == XK_Left || keycode == XK_Right)
		x = (keycode == XK_Left) ? data->buttonx[3] - 1 : data->buttonx[3] + 1;
	else
		x = data->buttonx[3];
	middlebuttonhandle(x, y, data);
}

void	iterationhandle(int keycode, t_data *data)
{
	int	*ite;

	ite = &ONSCREEN->ite;
	if (keycode == XK_KP_Add && *ite < INT_MAX && data->locked == 0)
	{
		if (ONSCREEN == data->glynn)
			*ite = (*ite < (INT_MAX - 9)) ? *ite + 10 : INT_MAX;
		else if (ONSCREEN == data->buddhabrot)
			*ite = (*ite < (INT_MAX - 249)) ? *ite + 250 : INT_MAX;
		else
			*ite = (*ite < INT_MAX) ? *ite + 1 : *ite;
		ONSCREEN->modified = 1;
	}
	if (keycode == XK_KP_Subtract && *ite > 0 && data->locked == 0)
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
	printf("XK_KP_Add = %d\n", XK_KP_Add);
	printf("XK_space = %d\n", XK_space);
	if (keycode == XK_Up || keycode == XK_Down || keycode == XK_Left || keycode == XK_Right)
		move(keycode, data);
	if (keycode == XK_q)
		exit(0);
	if (keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		iterationhandle(keycode, data);
	if (keycode == XK_space)
		if (ONSCREEN == data->julia || ONSCREEN == data->multibrot)
			ONSCREEN->locked = (ONSCREEN->locked == 0 ? 1 : 0);
	if (keycode == XK_m)
	{
		data->colorchanged = 1;
		data->menu = (data->menu == 0) ? 1 : 0;
	}
	if (keycode == XK_KP_Add || keycode == XK_KP_Subtract || keycode == XK_m)
	{
		ft_refresh(data);
		ft_printite(data);
	}
	return (0);
}
