/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:51:15 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 20:11:27 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				button_on(int button, int x, int y, t_data *data)
{
	data->button[button] = 1;
	data->buttonx[button] = x;
	data->buttony[button] = y;
	if (button == 4 || button == 5)
		scrollbutton(button, x, y, data);
	if (button == 4 || button == 5)
	{
		data->colorchanged = 1;
		ft_refresh(data);
	}
	if (button == 1)
		leftbuttonclick(x, y, data);
	if (button == 2)
		rightbuttonclick(x, y, data);
	if (button == 3)
	{
		colordel(data);
		data->colorchanged = 1;
	}
	return (0);
}

int				button_off(int button, int x, int y, t_data *data)
{
	data->button[button] = 0;
	data->buttonx[button] = x;
	data->buttony[button] = y;
	if (button == 1)
	{
		data->clickedrainbow = 0;
		data->clickedsquare = 0;
		data->clickedr = 0;
		data->clickedg = 0;
		data->clickedb = 0;
		ft_clickset(data);
	}
	ft_refresh(data);
	return (1);
}

void			leftbuttonclick(int x, int y, t_data *data)
{
	if (data->menu == 1)
		menuhandle(x, y, data);
	if (data->colormenu == 1)
		colormenuhandle(x, y, data);
	if (data->menu == 1 || data->colormenu == 1)
		ft_refresh(data);
}

int				rightbuttonclick(int x, int y, t_data *data)
{
	t_color		*ptr;

	(void)x;
	(void)y;
	ptr = data->color;
	while (ptr && ptr->hover == 0)
		ptr = ptr->next;
	if (ptr == NULL)
	{
		data->colormenu = 0;
		data->editedcolor = NULL;
		return (0);
	}
	else if (ptr->hover == 1)
	{
		data->colormenu = 1;
		data->editedcolor = ptr;
	}
	ft_refresh(data);
	return (1);
}

void			scrollbutton(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		if (data->menu == 1 && x > data->winx - data->onscreen->imgx - 50 &&
				x < data->winx && y >= 0 && y < data->winy)
			data->scrollmenuoffset -= (data->scrollmenuoffset >
					-(data->onscreen->imgy + 50)) ? 25 : 0;
		else
			zoom(1, x, y, data);
	}
	if (button == 4)
	{
		if (data->menu == 1 && x > data->winx - data->onscreen->imgx - 50 &&
				x < data->winx && y >= 0 && y < data->winy)
			data->scrollmenuoffset += (data->scrollmenuoffset < 0) ? 25 : 0;
		else
			zoom(-1, x, y, data);
	}
	if (data->scrollmenuoffset > 0)
		data->scrollmenuoffset = 0;
	if (data->scrollmenuoffset < -(data->onscreen->imgy + 50))
		data->scrollmenuoffset = -(data->onscreen->imgy + 50);
}
