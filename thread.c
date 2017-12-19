/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:34:47 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 07:58:36 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_refresh(t_data *data)
{
	pthread_t	thr1;
	pthread_t	thr2;
	pthread_t	thr3;

	ft_onscreenprint(data, data->onscreen);
	if (data->menu == 1)
	{
		pthread_create(&thr1, NULL, ft_minifractal, ft_palloc(data, -1, data->screen1));
		pthread_create(&thr2, NULL, ft_minifractal, ft_palloc(data, -1, data->screen2));
		pthread_create(&thr3, NULL, ft_minifractal, ft_palloc(data, -1, data->screen3)); 
		pthread_join(thr1, NULL);
		pthread_join(thr2, NULL);
		pthread_join(thr3, NULL);
	}
	print_img(data);
}

void			ft_onscreenprint(t_data *data, t_fractale *fract)
{
	pthread_t	thr1;
	pthread_t	thr2;
	pthread_t	thr3;
	pthread_t	thr4;
	pthread_create(&thr1, NULL, ft_fractal, ft_palloc(data, 0, fract));
	pthread_create(&thr2, NULL, ft_fractal, ft_palloc(data, 1, fract));
	pthread_create(&thr3, NULL, ft_fractal, ft_palloc(data, 2, fract));
	pthread_create(&thr4, NULL, ft_fractal, ft_palloc(data, 3, fract));	
	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
	pthread_join(thr3, NULL);
	pthread_join(thr4, NULL);
	menu(data);	
}

t_part			*ft_palloc(t_data *data, int i, t_fractale *fract)
{
	t_part		*part;

	part = (t_part*)ft_malloc(sizeof(t_part));
	part->y = i;
	part->z = fract->c;
	part->fra = fract;
	part->data = data;
	return (part);
}

void			ft_printcolor(long double retval, t_data *dat, int x, int y)
{
	if (retval == -1)
		px_to_onscreenimg(dat, x, y, 0x000000);
	else
		px_to_onscreenimg(dat, x, y, RGBgradtest(retval, dat, dat->onscreen));
}
/*
void			*ft_fractal(void *part)
{
	int			x;
	int			y;
	t_part		*p;

	p = part;
	y = p->y;
	while (y < p->data->winy)
	{
		x = 0;
		while (x < p->data->winx)
		{
			ft_printcolor(p->fra->formula(ft_complex(x * p->fra->zoom, y * p->fra->zoom, p->data),
			p->fra->c, p->data->onscreen->ite), p->data, x, y);
			x++;
		}
		y += 4;
	}
	free(part);
	return (NULL);
}
*/
void			*ft_fractal(void *part)
{
	int			x;
	int			y;
	t_part		*p;

	p = part;
	y = p->y;
	while (y < p->data->winy)
	{
		x = 0;
		while (x < p->data->winx)
		{
			ft_printcolor(p->fra->formula(ft_coord(x, y, p->fra, p->data),
			p->fra->c, p->data->onscreen->ite), p->data, x, y);
			x++;
		}
		y += 4;
	}
	free(part);
	return (NULL);
}

void			*ft_minifractal(void *part)
{
	int			x;
	t_complex	z;
	long double	retval;
	t_part		*p;

	p = part;	
	while (++p->y < p->fra->imgy)
	{
		x = -1;
		while (++x < p->fra->imgx)
		{
	//		z.r = (x - (double)(p->fra->imgx / 2)) / (p->fra->imgx / 4);
	//		z.i = (p->y - (double)(p->fra->imgy / 2)) / (p->fra->imgy / 3);
			z = ft_mcoord(x, p->y, p->fra, p->data); 
			if ((retval = p->fra->formula(z, p->fra->c, p->fra->ite)) == -1)
				px_to_miniimg(p->fra, x, p->y, 0x000000);
			else
				px_to_miniimg(p->fra, x, p->y, RGBgradtest(retval, p->data, p->fra));
		}
	}
	free(part);
	return (NULL);
}
