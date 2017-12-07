#include "fractol.h"

void		errset1(int *err, double *x, int difinc1, int difinc2)
{
	*err -= difinc1;
	*x += difinc2;
}

void		errset2(int *err, double *y, int difinc0, int difinc3)
{
	*err += difinc0;
	*y += difinc3;
}

void		ft_linepart(t_point a, t_point b, t_data *data)
{
	int		difinc[4];
	int		err;
	int		err2;

	difinc[0] = abs(b.x - a.x);
	difinc[1] = abs(b.y - a.y);
	difinc[2] = a.x < b.x ? 1 : -1;
	difinc[3] = a.y < b.y ? 1 : -1;
	err = (difinc[0] > difinc[1] ? difinc[0] : -difinc[1]) / 2;
	err2 = 0;
	while (42)
	{
		if (a.x < data->winx && a.x >= 0 && a.y < data->winy && a.y >= 0)
			mlx_px_to_img(data, data->img_str, a, a.w);
		if (a.x == b.x && a.y == b.y)
			break ;
		err2 = err;
		if (err2 > -difinc[0])
			errset1(&err, &a.x, difinc[1], difinc[2]);
		if (err2 < difinc[1])
			errset2(&err, &a.y, difinc[0], difinc[3]);
	}
}

void		ft_line(t_point a, t_point b, t_data *data)
{
	int		difinc[4];
	int		err;
	int		err2;

	difinc[0] = abs(b.x - a.x);
	difinc[1] = abs(b.y - a.y);
	difinc[2] = a.x < b.x ? 1 : -1;
	difinc[3] = a.y < b.y ? 1 : -1;
	err = (difinc[0] > difinc[1] ? difinc[0] : -difinc[1]) / 2;
	err2 = 0;
	while (42)
	{
		mlx_px_to_img(data, data->img_str, a, a.w);
		if (a.x == b.x && a.y == b.y)
			break ;
		err2 = err;
		if (err2 > -difinc[0])
			errset1(&err, &a.x, difinc[1], difinc[2]);
		if (err2 < difinc[1])
			errset2(&err, &a.y, difinc[0], difinc[3]);
	}
}

void		ft_triangle(t_point a, t_point b, t_point c)
{
	ft_line(a, b);
	ft_line(b, c);
	ft_line(c, a);
	ft_filltriangle(a, b, c);
}
