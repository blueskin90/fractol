/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycbcr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:40:47 by toliver           #+#    #+#             */
/*   Updated: 2018/01/05 01:24:26 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ycbcrset(t_data *data, int pos)
{
	data->ycbcr[pos].y = data->ycbcr[pos].r * 0.299;
	data->ycbcr[pos].y += (data->ycbcr[pos].g * 0.587); 
	data->ycbcr[pos].y += (data->ycbcr[pos].b * 0.114);
	data->ycbcr[pos].cb = 0.492 * data->ycbcr[pos].b - 0.492 * data->ycbcr[pos].y;
	data->ycbcr[pos].cr = 0.877 * (data->ycbcr[pos].r - data->ycbcr[pos].y);

}



void	testsmooth(t_ycbcr *ycbcr, t_data *data)
{
	int x;
	int	y;

	float EDGE_THRESHOLD_MIN = 0.0312;
	float EDGE_THRESHOLD_MAX = 0.125;
	float lumamax;
	float lumamin;
	float lumadelta;

	float lumacenter;
	float lumaleft;
	float lumaright;
	float lumatop;
	float lumabottom;

	y = -1;
	while (++y < WINY)
	{
		x = -1;
		while (++x < WINX)
		{
			lumacenter = ycbcr[x + y * WINX].y;
			if (x > 0)	
				lumaleft = ycbcr[x + y * WINX - 1].y;	
			if (x < WINX - 1)
				lumaright = ycbcr[x + y * WINX + 1].y;	
			if (y > 1)
				lumatop = ycbcr[x + y * WINX - WINX].y;	
			if (y < WINY - 1)
				lumabottom = ycbcr[x + y * WINX + WINX].y;

			lumamin = ft_min(lumacenter, lumaleft, ft_min(lumaright, lumatop, lumabottom));
			lumamax = ft_max(lumacenter, lumaleft, ft_max(lumaright, lumatop, lumabottom));
			lumadelta = lumamax - lumamin;
			if (lumarange < ft_max(EDGE_THRESHOLD_MIN, lumamax * EDGE_THRESHOLD_MAX))
				ycbcr[x + y * WINX].y2 = ycbcr[x + y * WINX].y; 
		}
	}
}



void	ycbcr(t_data *data)
{
	int		x;
	int		y;
	t_rgb	rgb;
	t_hsv	hsv;

	y = -1;
	while (++y < WINY)
	{
		x = -1;
		while (++x < WINX)
		{
			rgb = int_to_rgb(get_px_color(data, x, y));
			data->ycbcr[x + y * WINX].r = rgb.r / 255.00;
			data->ycbcr[x + y * WINX].g = rgb.g / 255.00;
			data->ycbcr[x + y * WINX].b = rgb.b / 255.00;
			ycbcrset(data, x + y * WINX);


		//	rgb.r = (data->ycbcr[x + y * WINX].y +  data->ycbcr[x + y * WINX].cr * 1.13983) * 255;
			rgb.r = 0;
//			rgb.g = (data->ycbcr[x + y * WINX].y - data->ycbcr[x + y * WINX].cb * 0.39465 - data->ycbcr[x + y * WINX].cr * 0.58060) * 255;
			rgb.g = 0;
		//	rgb.b = (data->ycbcr[x + y * WINX].y +  data->ycbcr[x + y * WINX].cb * 2.03211) * 255;
	//		rgb.b = 0;

			hsv.h = 0;
			hsv.s = 0;
			hsv.v = data->ycbcr[x + y * WINX].y * 100;


			px_to_onscreenimg(data, x, y, hsv_to_rgb(hsv));
		//	px_to_onscreenimg(data, x, y, rgb_to_int(rgb));
		}
	}
	print_img(data);
	testsmooth(data->ycbcr, data);
			sleep(3);
}

// conversion ycbcr correcte !
