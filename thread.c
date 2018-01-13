/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:34:47 by toliver           #+#    #+#             */
/*   Updated: 2018/01/12 11:43:40 by toliver          ###   ########.fr       */
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
	pthread_t	thr[7];
	t_part		part[7];
	int			i;

	ft_onscreenprint(data, data->onscreen);
	if ((i = -1) && data->menu == 1)
	{
		while (++i < 7)
		{
			part[i] = ft_palloc(data, -1, data->screen[i]);
			if (data->screen[i]->modified == 1 || data->screen[i]->locked == 0)
			{
				if (data->screen[i] != data->buddhabrot)
					pthread_create(&thr[i], NULL, ft_minifra, (void*)&part[i]);
				else
					pthread_create(&thr[i], NULL, ft_minibudf, (void*)&part[i]);
				data->screen[i]->modified = 0;
			}
			else if (data->colorchanged == 1)
				pthread_create(&thr[i], NULL, ft_minifracolor, (void*)&part[i]);
		}
		while (--i >= 0 && (data->colorchanged = 0) == 0)
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
	if (fract == data->buddhabrot && ONSCREEN->locked == 0)
		ft_buddhainit(data->buddhabrot, data);
	while (++i < 4)
	{
		part[i] = ft_palloc(data, i, fract);
		if (ONSCREEN->locked == 0 || ONSCREEN->modified == 1)
		{
			if (fract == data->buddhabrot)
				pthread_create(&thr[i], NULL, ft_buddhafill, (void*)&part[i]);
			else
				pthread_create(&thr[i], NULL, ft_fractal, (void*)&part[i]);
		}
		else if (data->colorchanged == 1)
			pthread_create(&thr[i], NULL, ft_coloredfractal, (void*)&part[i]);
	}
	while (--i >= 0)
		pthread_join(thr[i], NULL);
	if (!(ONSCREEN->modified = 0) && fract == data->buddhabrot)
		ft_buddhaimg(data);
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
			p->ONSCREEN->array[y][x].value = retval;
		}
		y += 4;
	}
	return (NULL);
}

void			*ft_minifra(void *part)
{
	int			x;
	t_complex	z;
	float		retval;
	t_part		*p;

	p = part;
	if (p->fra == p->data->buddhabrot)
		ft_buddhainit(p->data->buddhabrot, p->data);
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
			p->fra->miniarray[p->y][x].value = retval;
		}
	}
	return (NULL);
}
