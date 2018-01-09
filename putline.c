/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:18:44 by toliver           #+#    #+#             */
/*   Updated: 2018/01/07 14:14:24 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		errset1(int *err, int *x, int difinc1, int difinc2)
{
	*err -= difinc1;
	*x += difinc2;
}

void		errset2(int *err, int *y, int difinc0, int difinc3)
{
	*err += difinc0;
	*y += difinc3;
}

void		ft_line(t_point a, t_point b, t_data *data, int color)
{
	int		difinc[4];
	int		err;
	int		err2;

	difinc[0] = abs(b.x - a.x);
	difinc[1] = abs(b.y - a.y);
	difinc[2] = a.x < b.x ? 1 : -1;
	difinc[3] = a.y < b.y ? 1 : -1;
	err = (difinc[0] > difinc[1] ? difinc[0] : -difinc[1]) / 2;
	err2 = 0;
	while (42)
	{
		px_to_onscreenimg(data, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		err2 = err;
		if (err2 > -difinc[0])
			errset1(&err, &a.x, difinc[1], difinc[2]);
		if (err2 < difinc[1])
			errset2(&err, &a.y, difinc[0], difinc[3]);
	}
}
