/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:21:02 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 17:23:19 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_px_to_img(t_data *data, char *img, t_vector4 a, int color)
{
	(void)color;
	img[(int)a.x * 4 + (int)a.y * data->winx * 4] = get_color(a, 'b');
	img[(int)a.x * 4 + (int)a.y * data->winx * 4 + 1] = get_color(a, 'g');
	img[(int)a.x * 4 + (int)a.y * data->winx * 4 + 2] = get_color(a, 'r');
	img[(int)a.x * 4 + (int)a.y * data->winx * 4 + 3] = 0;
}

void	mlx_img_init(t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (data->img != NULL)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (!(data->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		exit(0);
	if (!(data->img_str = mlx_get_data_addr(data->img, &bpp, &sl, &endian)))
		exit(0);
}
