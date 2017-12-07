/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 23:17:04 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 18:10:17 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			setangle(t_vector4 *anglerad, t_vector4 angle)
{
	anglerad->x = (double)angle.x * M_PI / 180;
	anglerad->y = (double)angle.y * M_PI / 180;
	anglerad->z = (double)angle.z * M_PI / 180;
}

void			rloop(size_t i, t_vector4 angle, t_parsedmap *map, t_data *data)
{
	double		tmp;

	map->pointp[i].x = (map->point[i].x * cos(angle.z)) -
						(map->point[i].y * sin(angle.z));
	map->pointp[i].y = (map->point[i].y * cos(angle.z)) +
					(map->point[i].x * sin(angle.z));
	map->pointp[i].z = map->point[i].z * data->sca.z;
	map->pointp[i].w = map->point[i].w;
	tmp = map->pointp[i].x;
	map->pointp[i].x = (map->pointp[i].x * cos(angle.y)) +
						(map->pointp[i].z * sin(angle.y));
	map->pointp[i].z = (map->pointp[i].z * cos(angle.y)) -
						(tmp * sin(angle.y));
	tmp = map->pointp[i].y;
	map->pointp[i].y = (map->pointp[i].y * cos(angle.x)) -
						(map->pointp[i].z * sin(angle.x));
	map->pointp[i].z = (tmp * sin(angle.x)) +
						(map->pointp[i].z * sin(angle.x));
	map->pointp[i].x = ((double)(map->pointp[i].x + data->tran.x -
					data->winx / 2) * data->sca.x) + data->winx / 2;
	map->pointp[i].y = ((double)(map->pointp[i].y + data->tran.y -
					data->winy / 2) * data->sca.y) + data->winy / 2;
	map->pointp[i].z = ((double)(map->pointp[i].z) * data->sca.y);
}

int				rotate(t_data *data)
{
	t_parsedmap	*map;
	size_t		i;
	t_vector4	angle;

	map = data->isomap;
	i = -1;
	setangle(&angle, data->rot);
	while (++i < map->array_size)
		rloop(i, angle, map, data);
	return (1);
}

char			get_color(t_vector4 a, char color)
{
	if (color == 'r')
		return (a.w >> 16);
	if (color == 'g')
		return ((a.w >> 8) - ((a.w >> 16) * 0x100));
	if (color == 'b')
		return (a.w - ((a.w >> 8) * 0x10000));
	else
	{
		ft_putendl("Apprends a utiliser ta propre fonction.");
		exit(0);
	}
}

int				maptoscreen(t_data *data)
{
	size_t		i;
	t_vector4	*vector;

	vector = data->isomap->pointp;
	rotate(data);
	mlx_img_init(data);
	i = -1;
	while (++i < data->isomap->array_size)
	{
		vector[i].x = round(vector[i].x);
		vector[i].y = round(vector[i].y);
		jointoprec(i, vector, data);
		jointoupper(i, vector, data);
		jointodiag(i, vector, data);
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->img_str = NULL;
	return (1);
}
