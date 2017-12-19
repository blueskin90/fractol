/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:19:33 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 08:47:37 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
** trouver un moyen de simplifier les fonctions mini... en une seule
** LIS BIEN LES COMMENTAIRES FFS
*/
void			*ft_malloc(int size)
{
	void	*memory;

	if (!(memory=malloc(size)))
		ft_error("Malloc failed !\n");
	return (memory);
}

void			ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}

int				window_closed(t_data *data)
{
	(void)data;
	ft_error("Next time, use ESC !");
	return (0);
}

void	img_init(t_fractale *fract, t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (!(fract->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		ft_error("fractal->img creation failed !\n");
	if (!(fract->img_str = mlx_get_data_addr(fract->img, &bpp, &sl, &endian)))
		ft_error("fractal->img_str creation failed !\n");
	if (!(fract->miniimg = mlx_new_image(data->mlx, fract->imgx, fract->imgy)))
		ft_error("fractal->miniimg creation failed !\n");
	if (!(fract->miniimg_str =
				mlx_get_data_addr(fract->miniimg, &bpp, &sl, &endian)))
		ft_error("fractal->miniimg_str creation failed !\n");
}

t_fractale		*ft_fractalinit(t_data *data)
{
	t_fractale	*fract;
	
	fract = (t_fractale*)ft_malloc(sizeof(t_fractale));
	fract->zoompos.r = 0;
	fract->zoompos.i = 0;
	fract->offset.r = 0;
	fract->offset.i = 0;
	fract->tran.r = 0;
	fract->tran.i = 0;
	fract->zoom = 1;
	fract->ite = 50;
	fract->c = ft_comp(0, 0);
	fract->imgx = data->winx / 6;
	fract->imgy = data->winy / 6;
	fract->locked = 0;
	img_init(fract, data);
	return (fract);
}
void			coloradd(t_data *data, int color, long double index)
{
	t_color		*ptr;
	t_color		*tmp;

	ptr = data->color;
	while (ptr->index < index && ptr->next && ptr->next->index < index)
		ptr = ptr->next;
	tmp = (t_color*)ft_malloc(sizeof(t_color));
	tmp->value = color;
	tmp->index = index;
	tmp->next = ptr->next;
	ptr->next = tmp;
}
void			colorinit(t_data *data)
{
	data->color = (t_color*)ft_malloc(sizeof(t_color));
	data->color->value = 0x3d2900;
	data->color->index = 0;
	data->color->next = (t_color*)ft_malloc(sizeof(t_color));
	data->color->next->value = 0xfdc549;
	data->color->next->index = 1;
	data->color->next->next = NULL;
//	data->color[0] = 0x3d2900;
//	data->color[1] = 0xfdc549;
}

void			ft_triangleinit(t_data *data)
{
	data->triangle.a.x = 350;
	data->triangle.a.y = 0;
	data->triangle.b.x = 0;
	data->triangle.b.y = 700;
	data->triangle.c.x = 700;
	data->triangle.c.y = 700;
}

void			ft_setoffset(t_fractale *fra)
{
	fra->offset.r = (fra->maxx + fra->minx) / 2;
	fra->offset.i = (fra->maxy + fra->miny) / 2;
}

void			ft_fractset(t_data *data)
{
	data->julia->formula = &ft_julia;
	data->julia->minx = -2;
	data->julia->maxx = 2;
	data->julia->miny = -1.5;
	data->julia->maxy = 1.5;
	data->mandelbrot->formula = &ft_mandelbrot;
	data->mandelbrot->minx = -2;
	data->mandelbrot->maxx = 1;
	data->mandelbrot->miny = -1;
	data->mandelbrot->maxy = 1;
	data->burningship->formula = &ft_burningship;
	data->burningship->minx = -2;
	data->burningship->maxx = 1.5;
	data->burningship->miny = 1;
	data->burningship->maxy = -2;
	ft_setoffset(data->julia);
	ft_setoffset(data->mandelbrot);
	ft_setoffset(data->burningship);
}

t_data			*init(void)
{
	t_data	*data;

	data = (t_data*)ft_malloc(sizeof(t_data));
	if (!(data->mlx = mlx_init()))
		ft_error("Mlx init failed.");
	data->winx = 800;
	data->winy = 600;
	if (!(data->win = 
				mlx_new_window(data->mlx, data->winx, data->winy, "fractol")))
		ft_error("New window creation failed.");
	data->menu = 0;
	data->img = NULL;
	data->mandelbrot = ft_fractalinit(data);
	data->julia = ft_fractalinit(data);
	data->burningship = ft_fractalinit(data);
	ft_fractset(data);
	ft_triangleinit(data);
	data->onscreen = data->julia;
	data->screen1 = data->mandelbrot;
	data->screen2 = data->burningship;
	data->screen3 = data->julia;

	colorinit(data);
	mlx_img_init(data);
return (data);
}

int				main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init();
	ft_coord(0, 0, data->mandelbrot, data);
//	ft_sierpinsky(data->triangle, data, data->ite); // deg a partir de 7 -8 iter 
	mlx_hook(data->win, 2, 0, key_on, data);
	mlx_hook(data->win, 4, 0, button_on, data);
	mlx_hook(data->win, 5, 0, button_off, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	mlx_hook(data->win, 17, 0, window_closed, data);
	coloradd(data, 0xff0000, 0.2535);
	coloradd(data, 0xfff000, 0.4);
	coloradd(data, 0x00ff00, 0.6);
	coloradd(data, 0x0000ff, 0.714124);
	mlx_loop(data->mlx);
	return (0);
}
