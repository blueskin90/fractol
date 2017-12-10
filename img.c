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

#include "fractol.h"

char			get_color(int c, char color)
{
	if (color == 'r')
		return (c >> 16);
	if (color == 'g')
		return ((c >> 8) - ((c >> 16) * 0x100));
	if (color == 'b')
		return (c - ((c >> 8) * 0x10000));
	else
	{
		ft_putendl("Apprends a utiliser ta propre fonction.");
		exit(-1);
	}
}

void	mlx_px_to_img(t_data *data, int x, int y, int c)
{
	data->img_str[x * 4 + y * data->winx * 4] = get_color(c, 'b');
	data->img_str[x * 4 + y * data->winx * 4 + 1] = get_color(c, 'g');
	data->img_str[x * 4 + y * data->winx * 4 + 2] = get_color(c, 'r');
	data->img_str[x * 4 + y * data->winx * 4 + 3] = 0;
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
		exit(-1);
	if (!(data->img_str = mlx_get_data_addr(data->img, &bpp, &sl, &endian)))
		exit(-1);
}
