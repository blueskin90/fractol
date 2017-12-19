/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:51:15 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 08:48:32 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				button_on(int button, int x, int y, t_data *data)
{
	t_complex	test;
	data->button[button] = 1;
	data->buttonx[button] = x;
	data->buttony[button] = y;
	if (button == 5) // scroll arriere
	{
		data->onscreen->zoompos = ft_mousecoord(x, y, data->onscreen, data);
		data->onscreen->zoom *= 1.1;
		test = ft_mousecoord(x, y, data->onscreen, data);
		data->onscreen->offset.r -= (test.r - data->onscreen->zoompos.r); 
		data->onscreen->offset.i -= (test.i - data->onscreen->zoompos.i);
		data->onscreen->ite -= 1 ;
	}
	if (button == 4) // scroll avant
	{
		data->onscreen->zoompos = ft_mousecoord(x, y, data->onscreen, data);
		data->onscreen->zoom /= 1.1;
		test = ft_mousecoord(x, y, data->onscreen, data);
		data->onscreen->offset.r -= (test.r - data->onscreen->zoompos.r);
		data->onscreen->offset.i -= (test.i - data->onscreen->zoompos.i);
		data->onscreen->ite += 1;
	}
	if (button == 4 || button == 5)
	{
		ft_refresh(data);
	}
	if (button == 3)
	{
		ft_putchar('A');
	}
	if (button == 1)
		leftbuttonhandle(x, y, data);
	return (0);
}

int		button_off(int button, int x, int y, t_data *data)
{
	data->button[button] = 0;
	data->buttonx[button] = x;
	data->buttony[button] = y;
	return (1);
}

void			ptrswap(t_fractale **ptr1, t_fractale **ptr2, t_data *data)
{
	t_fractale	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
	ft_refresh(data);
}

void			leftbuttonhandle(int x, int y, t_data *data)
{
	if(data->menu == 1)
	{
		if (x >= data->winx - data->onscreen->imgx - 25 && x <= data->winx - 25)
		{
			if (y >= 25 && y <= 25 + data->onscreen->imgy)
				ptrswap(&data->onscreen, &data->screen1, data);
			if (y >= 50 + data->onscreen->imgy && y <= 50 + 2 * data->onscreen->imgy)
				ptrswap(&data->onscreen, &data->screen2, data);
			if (y >= 75 + 2 * data->onscreen->imgy  && y <= 75 + 3 * data->onscreen->imgy)
				ptrswap(&data->onscreen, &data->screen3, data);
		}
	}
}

int				middlebuttonhandle(int x, int y, t_data *data)
{
	t_complex	test;
	t_complex	test2;

	test = ft_coord(x, y, data->onscreen, data);
	test2 = ft_coord(data->buttonx[3], data->buttony[3], data->onscreen, data);
	if (data->buttonx[3] != x)
	{
		data->onscreen->tran.r += test.r - test2.r;
		data->buttonx[3] = x;
	}
	if (data->buttony[3] != y)
	{
		data->onscreen->tran.i += test.i - test2.i;
		data->buttony[3] = y;
	}
	ft_refresh(data);
	return (1);
}


