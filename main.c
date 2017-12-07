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
	data->a.x = 350;
	data->a.y = 0;
	data->b.x = 0;
	data->b.y = 700;
	data->c.x = 700;
	data->c.y = 700;
	return (data);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init();
	ft_triangle(data->a, data->b, data->c, data);
	mlx_hook(data->win, 17, 0, window_closed, data);
	mlx_loop(data->mlx);
	return (0);
}
