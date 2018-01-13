/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:15:45 by toliver           #+#    #+#             */
/*   Updated: 2018/01/12 11:39:22 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			*ft_minifracolor(void *part)
{
	int			x;
	int			y;
	t_part		*p;

	p = part;
	y = -1;
	while (++y < p->fra->imgy)
	{
		x = -1;
		while (++x < p->fra->imgx)
		{
			if (p->fra->miniarray[y][x].value == -1)
				px_to_miniimg(p->fra, x, y, 0x000000);
			else
				px_to_miniimg(p->fra, x, y, rgb_grad(
					p->fra->miniarray[y][x].value, p->data, p->data->onscreen));
		}
	}
	return (NULL);
}

void			*ft_coloredfractal(void *part)
{
	int			x;
	int			y;
	t_part		*p;

	p = part;
	y = p->y;
	while (y < p->WINY)
	{
		x = -1;
		while (++x < p->WINX)
		{
			if (p->fra->array[y][x].value == -1)
				px_to_onscreenimg(p->data, x, y, 0x000000);
			else
				px_to_onscreenimg(p->data, x, y, rgb_grad(
					p->fra->array[y][x].value, p->data, p->data->onscreen));
		}
		y += 4;
	}
	return (NULL);
}
