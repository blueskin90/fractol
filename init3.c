/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:13:09 by toliver           #+#    #+#             */
/*   Updated: 2018/01/11 21:14:57 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_value			**arrayinit(int xmax, int ymax)
{
	int			i;
	t_value		**array;

	array = (t_value**)ft_malloc(sizeof(t_value*) * ymax);
	i = -1;
	while (++i < ymax)
		array[i] = (t_value*)ft_malloc(sizeof(t_value) * xmax);
	return (array);
}

t_fractale		*fractalinit(t_data *data)
{
	t_fractale	*fract;

	fract = (t_fractale*)ft_malloc(sizeof(t_fractale));
	fract->zoompos.r = 0;
	fract->zoompos.i = 0;
	fract->offset.r = 0;
	fract->offset.i = 0;
	fract->tran.r = 0;
	fract->tran.i = 0;
	fract->zoom = 1;
	fract->ite = 50;
	fract->c = ft_comp(0, 0);
	fract->imgx = data->winx / 6;
	fract->imgy = (data->winy - 125) / 5;
	fract->locked = 1;
	fract->modified = 1;
	img_init(fract, data);
	fract->array = arrayinit(WINX, WINY);
	fract->miniarray = arrayinit(WINX / 6, (WINY - 125) / 5);
	return (fract);
}
