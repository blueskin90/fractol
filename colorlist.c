/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:20 by toliver           #+#    #+#             */
/*   Updated: 2018/01/12 11:43:44 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			coloradd(t_data *data, int color, float index)
{
	t_color		*ptr;
	t_color		*tmp;

	ptr = data->color;
	while (ptr->index < index && ptr->next && ptr->next->index < index)
		ptr = ptr->next;
	tmp = (t_color*)ft_malloc(sizeof(t_color));
	tmp->value = color;
	tmp->hover = 0;
	tmp->clicked = 0;
	tmp->locked = 0;
	tmp->index = index;
	tmp->next = ptr->next;
	tmp->hsv = rgb_to_hsv(color);
	tmp->rgb = int_to_rgb(color);
	ptr->next = tmp;
	data->colorchanged = 1;
}

int				colordel(t_data *data)
{
	t_color		*ptr;
	t_color		*tmp;

	ptr = data->color;
	while (ptr && (ptr->locked == 1 || ptr->hover == 0))
		ptr = ptr->next;
	if (ptr == NULL)
		return (0);
	tmp = data->color;
	while (tmp->next != ptr)
		tmp = tmp->next;
	if (ptr == data->editedcolor)
	{
		data->colormenu = 0;
		data->editedcolor = NULL;
	}
	tmp->next = tmp->next->next;
	free(ptr);
	data->colorchanged = 1;
	return (1);
}

void			ft_switchnext(t_color *first, t_color *second, t_data *data)
{
	t_color		*ptr;

	ptr = data->color;
	while (ptr->next != first)
		ptr = ptr->next;
	ptr->next = second;
	first->next = second->next;
	second->next = first;
	data->colorchanged = 1;
}

void			ft_reorganize_colors(t_data *data)
{
	t_color	*ptr;

	ptr = data->color;
	while (ptr && ptr->next)
	{
		if (ptr->index > ptr->next->index)
		{
			ft_switchnext(ptr, ptr->next, data);
			ptr = data->color;
		}
		else
			ptr = ptr->next;
	}
	data->colorchanged = 1;
}

void			ptrswap(t_fractale **ptr1, t_fractale **ptr2, t_data *data)
{
	t_fractale	*tmp;

	(void)data;
	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
