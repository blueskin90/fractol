/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:12:25 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 15:13:37 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			img_init(t_fractale *fract, t_data *data)
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
