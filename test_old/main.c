/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:22:08 by toliver           #+#    #+#             */
/*   Updated: 2017/12/05 18:51:21 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int			window_closed(void)
{
	ft_putendl("Next time, use esc !");
	exit(0);
}

int			checkparam(int argc, char **argv)
{
	argv[0] = 0;
	if (argc != 2)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (checkparam(argc, argv) != 1)
	{
		ft_putendl("usage: ./fillit map_file");
		return (0);
	}
	data = initialize();
	data->map = map_parsing(argv[1]);
	data->isomap = copymap(data->map);
	resetiso(data);
	maptoscreen(data);
	mlx_hook(data->win, 2, 0, key_on, data);
	mlx_hook(data->win, 4, 0, button_on, data);
	mlx_hook(data->win, 5, 0, button_off, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	mlx_hook(data->win, 17, 0, window_closed, data);
	mlx_loop(data->mlx);
	return (0);
}
