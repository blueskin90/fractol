/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:46:46 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 08:48:31 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				getstep(unsigned char val1, unsigned char val2, long double retval)
{
	long double	color;
	color = (val2 - val1) * retval;
	color = roundl(color);
	return (color);	
}
/*
int					RGBgrad(int col1, int col2, unsigned int steps)
{
	unsigned int	i;
	int				col3;
	double			rstep;
	double			gstep;
	double			bstep;

	col3 = col1;
	rstep = getstep(get_color(col1, 'r'), get_color(col2, 'r'),steps) * 0x10000;
	gstep = getstep(get_color(col1, 'g'), get_color(col2, 'g'),steps) * 0x100;
	bstep = getstep(get_color(col1, 'b'), get_color(col2, 'b'),steps);
	i = 0;
	while(i < steps)
	{
		col3 += rstep + gstep + bstep;
		i++;
	}
	return (1);	
}
*/ // useless pour le moment
int					ft_get_firstcolor(long double retval, t_data *data)
{
	int				color;
	t_color			*ptr;

	ptr = data->color;
	color = ptr->value;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->index <= retval)
			color = ptr->value;
	}
	return (color);
}

int					ft_get_lastcolor(long double retval, t_data *data)
{
	int				color;
	t_color			*ptr;

	ptr = data->color;
	color = ptr->value;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->index >= retval)
			return (ptr->value);
	}
	return (color);
}

long double			ft_get_retval(long double retval, t_data *data)
{
	long double		inf;
	long double		sup;
	t_color			*ptr;

	ptr = data->color;
	while (ptr->next->index < retval)
		ptr = ptr->next;
	inf = ptr->index;
	sup = ptr->next->index;
	return ((double)(retval - inf)/(sup - inf));
}

int					RGBgradtest(long double retval, t_data *data, t_fractale *fract)
{
	int				col1;
	int				col2;
	int				col3;
	long double		ret;

	(void)fract;
	col1 = ft_get_firstcolor(retval, data);
	col2 = ft_get_lastcolor(retval, data);
	col3 = col1;
	ret = ft_get_retval(retval, data); 
	col3 += (getstep(get_color(col1, 'r'), get_color(col2, 'r'), ret)
			* 0x10000);
	col3 += (getstep(get_color(col1, 'g'), get_color(col2, 'g'), ret) 
			* 0x100);
	col3 += (getstep(get_color(col1, 'b'), get_color(col2, 'b'), ret));
	return (col3);
}
