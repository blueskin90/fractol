/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:19:33 by toliver           #+#    #+#             */
/*   Updated: 2017/12/11 17:56:27 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

int			window_closed(t_data *data)
{
	(void)data;
	ft_error("Next time, use ESC !");
	return (0);
}

t_data		*init(void)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		ft_error("Malloc of t_data* failed.");
	if (!(data->mlx = mlx_init()))
		ft_error("Mlx init failed.");
	if (!(data->win = mlx_new_window(data->mlx, 701, 701, "fractol")))
		ft_error("New window creation failed.");
	data->winx = 701;
	data->winy = 701;
	data->triangle.a.x = 350;
	data->triangle.a.y = 0;
	data->triangle.b.x = 0;
	data->triangle.b.y = 700;
	data->triangle.c.x = 700;
	data->triangle.c.y = 700;
	data->ite = 0;
	data->img = NULL;
	mlx_img_init(data);
return (data);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init();
//	ft_sierpinsky(data->triangle, data, data->ite); // deg a partir de 7 -8 iter
	mlx_hook(data->win, 2, 0, key_on, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	mlx_hook(data->win, 17, 0, window_closed, data);
	mlx_loop(data->mlx);
	return (0);
}
