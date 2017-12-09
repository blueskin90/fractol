/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:21:23 by toliver           #+#    #+#             */
/*   Updated: 2017/12/08 14:14:19 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_on(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && data->ite != 2147483647)
		data->ite++;
	if (keycode == 78 && data->ite != 0)
		data->ite--;
	if (keycode == 69 || keycode == 78)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_sierpinsky(data->triangle, data, data->ite);
	}
	return (0);
}
