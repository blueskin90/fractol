/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:19:33 by toliver           #+#    #+#             */
/*   Updated: 2018/01/09 14:29:47 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				window_closed(t_data *data)
{
	(void)data;
	ft_error("Next time, use ESC !");
	return (0);
}

int				paramcheck(char *arg, char *tocomp)
{
	int			i;

	i = 0;
	while (arg[i] == tocomp[i] && arg[i] && tocomp[i])
		++i;
	if (arg[i] == '\0')
		return (1);
	return (0);
}

int				argcheck(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage:	./fractol fractal");
		ft_putendl("		mandelbrot, julia, burningship, multibrot, glynn, mandeldrop, mandelheart, buddhabrot");
		exit(-1);
	}
	else if (paramcheck(argv[1], "mandelbrot") == 1)
		return (0);
	else if (paramcheck(argv[1], "julia") == 1)
		return (1);
	else if (paramcheck(argv[1], "burningship") == 1)
		return (2);
	else if (paramcheck(argv[1], "multibrot") == 1)
		return (3);
	else if (paramcheck(argv[1], "glynn") == 1)
		return (4);
	else if (paramcheck(argv[1], "mandeldrop") == 1)
		return (5);
	else if (paramcheck(argv[1], "mandelheart") == 1)
		return (6);
	else if (paramcheck(argv[1], "buddhabrot") == 1)
		return (7);
	else
		return (argcheck(1, argv));
}

int				main(int argc, char **argv)
{
	t_data		*data;
	int			fra;

	fra = argcheck(argc, argv);
	data = init(fra);
	mlx_hook(data->win, 2, 0, key_on, data);
	mlx_hook(data->win, 4, 0, button_on, data);
	mlx_hook(data->win, 5, 0, button_off, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	mlx_hook(data->win, 17, 0, window_closed, data);
	ft_buddhainit(data->buddhabrot, data);
	ft_refresh(data);
	mlx_loop(data->mlx);
	return (0);
}
