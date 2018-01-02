/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:21:23 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 20:00:38 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_on(int keycode, t_data *data)
{
	if (keycode == 35)
		ft_printscreen(data);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && ONSCREEN->ite != INT_MAX 
			&& (data->colorchanged = 1) == 1)
		ONSCREEN->ite++;
	if (keycode == 78 && ONSCREEN->ite != 0 && (data->colorchanged = 1) == 1)
		ONSCREEN->ite--;
	if (keycode == 49)
		if (ONSCREEN == data->julia || ONSCREEN == data->multibrot)
			ONSCREEN->locked = (ONSCREEN->locked == 0 ? 1 : 0);
	if (keycode == 46)
	{
		data->menu = (data->menu == 0 ? 1 : 0);
		data->colorchanged = 1;
	}
	if (keycode == 69 || keycode == 78 || keycode == 46)
	{
		ft_refresh(data);
		ft_printite(data);
	}
	return (0);
}
