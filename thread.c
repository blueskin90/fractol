/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:34:47 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:21:07 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_part			ft_palloc(t_data *data, int i, t_fractale *fract)
{
	t_part		part;

	part.y = i;
	part.z = fract->c;
	part.fra = fract;
	part.data = data;
	return (part);
}

void			ft_refresh(t_data *data)
{
	pthread_t	thr[6];
	t_part		part[6];
	int			i;
	
	if (data->onscreen->locked == 0 || data->colorchanged == 1)
		ft_onscreenprint(data, data->onscreen);
	if (data->menu == 1)
	{
		i = -1;
		while (++i < 6)
		{
			if (data->colorchanged == 1 || data->screen[i]->locked == 0)
			{
				part[i] = ft_palloc(data, -1, data->screen[i]);
				pthread_create(&thr[i], NULL, ft_minifractal, (void*)&part[i]);
			}
		}
		if (data->colorchanged == 1)
			data->colorchanged = 0;
		i = -1;
		while (++i < 6)
			pthread_join(thr[i], NULL);
	}
	print_img(data);
}

void			ft_onscreenprint(t_data *data, t_fractale *fract)
{
	pthread_t	thr[4];
	t_part		part[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		part[i] = ft_palloc(data, i, fract);
		pthread_create(&thr[i], NULL, ft_fractal, (void*)&part[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(thr[i], NULL);
	menu(data);
}

void			*ft_fractal(void *part)
{
	int			x;
	int			y;
	t_part		*p;
	float		retval;

	p = part;
	y = p->y;
	while (y < p->data->winy)
	{
		x = -1;
		while (++x < p->data->winx)
		{
			if ((retval = p->fra->formula(ft_coord(x, y, p->fra, p->data),
				p->fra->c, p->data->onscreen->ite)) == -1)
				px_to_onscreenimg(p->data, x, y, 0x000000);
			else
				px_to_onscreenimg(p->data, x, y, rgb_grad(retval, p->data,
							p->data->onscreen));
		}
		y += 4;
	}
	return (NULL);
}

void			*ft_minifractal(void *part)
{
	int			x;
	t_complex	z;
	float		retval;
	t_part		*p;

	p = part;
	while (++p->y < p->fra->imgy)
	{
		x = -1;
		while (++x < p->fra->imgx)
		{
			z = ft_mcoord(x, p->y, p->fra, p->data);
			if ((retval = p->fra->formula(z, p->fra->c, p->fra->ite)) == -1)
				px_to_miniimg(p->fra, x, p->y, 0x000000);
			else
				px_to_miniimg(p->fra, x, p->y, rgb_grad(retval, p->data,
							p->fra));
		}
	}
	return (NULL);
}
