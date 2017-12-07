/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:22:18 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 17:27:19 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		errset1(int *err, double *x, int difinc1, int difinc2)
{
	*err -= difinc1;
	*x += difinc2;
}

void		errset2(int *err, double *y, int difinc0, int difinc3)
{
	*err += difinc0;
	*y += difinc3;
}

void		putlinepart(t_vector4 a, t_vector4 b, t_data *data)
{
	int		difinc[4];
	int		err;
	int		err2;

	difinc[0] = abs((int)b.x - (int)a.x);
	difinc[1] = abs((int)b.y - (int)a.y);
	difinc[2] = (int)a.x < (int)b.x ? 1 : -1;
	difinc[3] = (int)a.y < (int)b.y ? 1 : -1;
	err = (difinc[0] > difinc[1] ? difinc[0] : -difinc[1]) / 2;
	err2 = 0;
	while (42)
	{
		if ((int)a.x < data->winx && (int)a.x >= 0 &&
				(int)a.y < data->winy && (int)a.y >= 0)
			mlx_px_to_img(data, data->img_str, a, a.w);
		if ((int)a.x == (int)b.x && (int)a.y == (int)b.y)
			break ;
		err2 = err;
		if (err2 > -difinc[0])
			errset1(&err, &a.x, difinc[1], difinc[2]);
		if (err2 < difinc[1])
			errset2(&err, &a.y, difinc[0], difinc[3]);
	}
}

void		putline(t_vector4 a, t_vector4 b, t_data *data)
{
	int		difinc[4];
	int		err;
	int		err2;

	difinc[0] = abs((int)b.x - (int)a.x);
	difinc[1] = abs((int)b.y - (int)a.y);
	difinc[2] = (int)a.x < (int)b.x ? 1 : -1;
	difinc[3] = (int)a.y < (int)b.y ? 1 : -1;
	err = (difinc[0] > difinc[1] ? difinc[0] : -difinc[1]) / 2;
	err2 = 0;
	while (42)
	{
		mlx_px_to_img(data, data->img_str, a, a.w);
		if ((int)a.x == (int)b.x && (int)a.y == (int)b.y)
			break ;
		err2 = err;
		if (err2 > -difinc[0])
			errset1(&err, &a.x, difinc[1], difinc[2]);
		if (err2 < difinc[1])
			errset2(&err, &a.y, difinc[0], difinc[3]);
	}
}
