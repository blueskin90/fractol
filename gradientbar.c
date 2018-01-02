/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradientbar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:47:59 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 20:08:47 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			printgradient(t_data *data)
{
	int			y;
	int			x;

	y = 20;
	while (y < data->winy - 20)
	{
		x = 10;
		while (x < 20)
		{
			if (x == 10 || x == 19 || y == 20 || y == data->winy - 21)
				px_to_onscreenimg(data, x, y, 0);
			else if ((x == 11 && y >= 21 && y <= data->winy - 22) ||
					(x == 18 && y >= 21 && y <= data->winy - 22) ||
					(y == 21 && x >= 11 && x <= 18) ||
					(y == data->winy - 22 && x >= 11 && x <= 18))
				px_to_onscreenimg(data, x, y, 0xffffff);
			else
				px_to_onscreenimg(data, x, y,
					rgb_grad((float)(y - 22) / (data->winy - 44), data, NULL));
			x++;
		}
		y++;
	}
}

int				ft_clickget(t_data *data, int x, int y)
{
	t_color	*tmp;

	tmp = data->color;
	while (tmp)
	{
		if (x >= 22 && x <= 38 && y > 15 + round(tmp->index * (data->winy - 45))
				&& y < 33 + round(tmp->index * (data->winy - 45))
				&& tmp->locked == 0)
		{
			tmp->clicked = 1;
			data->colorchanged = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void			ft_clickset(t_data *data)
{
	t_color	*tmp;

	tmp = data->color;
	while (tmp)
	{
		tmp->clicked = 0;
		data->colorchanged = 1;
		tmp = tmp->next;
	}
}

void			ft_hoverget(t_data *data, int x, int y)
{
	t_color		*tmp;

	tmp = data->color;
	while (tmp)
	{
		if (x >= 22 && x <= 38 && y > 15 + round(tmp->index * (data->winy - 45))
				&& y < 33 + round(tmp->index * (data->winy - 45)))
		{
			tmp->hover = 1;
			data->colorchanged = 1;
		}
		else
		{
			if (tmp->hover == 1)
				data->colorchanged = 1;
			tmp->hover = 0;
		}
		tmp = tmp->next;
	}
}

int				movingpresets(int y, t_data *data)
{
	t_color		*ptr;
	int			diff;

	ptr = data->color;
	while (ptr && ptr->clicked != 1)
		ptr = ptr->next;
	if (ptr == NULL)
		return (0);
	if (y < 22)
		y = 22;
	if (data->buttony[1] < 22)
		data->buttony[1] = 22;
	if (y > data->winy - 24)
		y = data->winy - 24;
	if (data->buttony[1] > data->winy - 22)
		data->buttony[1] = data->winy - 22;
	diff = y - data->buttony[1];
	if (ptr->index + ((float)diff / (data->winy - 45)) >= 1)
		ptr->index = 0.99999999999999999999999999999999;
	else if (ptr->index + ((float)diff / (data->winy - 45)) <= 0)
		ptr->index = 0.00000000000000000000000000000001;
	else
		ptr->index += (float)diff / (data->winy - 45);
	data->buttony[1] = y;
	data->colorchanged = 1;
	return (1);
}
