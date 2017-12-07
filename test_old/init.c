/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:50:26 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:51:23 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*initialize(void)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		ft_error("failed to malloc the data structure.\n");
	if (!(data->mlx = mlx_init()))
		ft_error("failed to initiate the mlx.\n");
	data->winx = 700;
	data->winy = 700;
	data->img = NULL;
	data->img_str = NULL;
	data->isinmenu = 0;
	vector_init(data);
	array_init(data);
	if (!(data->win = mlx_new_window(data->mlx, data->winx, data->winy, "fdf")))
		ft_error("failed to create a window");
	return (data);
}

void		vector_init(t_data *data)
{
	data->tran.x = (double)data->winx / 2;
	data->tran.y = (double)data->winy / 2;
	data->tran.z = 0;
	data->tran.w = 0;
	data->sca.x = 1;
	data->sca.y = 1;
	data->sca.z = 1;
	data->sca.w = 0;
	data->rot.x = 0;
	data->rot.y = 0;
	data->rot.z = 0;
	data->rot.w = 0;
}

void		array_init(t_data *data)
{
	int		i;

	i = -1;
	while (++i < 280)
	{
		if (i < 7)
		{
			data->button[i] = 0;
			data->buttonx[i] = 0;
			data->buttony[i] = 0;
		}
		data->key[i] = 0;
	}
}
