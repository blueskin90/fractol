#include "fractol.h"

int		mouse_mov(int x, int y, t_data *data)
{
	ft_mandelbrot(data, x, y);
	return (1);
}
