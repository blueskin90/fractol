/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:09:57 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 18:08:04 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;

	int				winx;
	int				winy;

	int				key[279];
	int				button[7];
	int				buttonx[7];
	int				buttony[7];
}					t_data;

/*
** printing functions
*/

void				errset1(int *err, double *x, int difinc1, int difinc2);
void				errset2(int *err, double *y, int difinc0, int difinc3);
void				ft_linepart(t_point a, t_point b, t_data *data);
void				ft_line(t_point a, t_point b, t_data *data);
void				ft_triangle(t_point a, t_pointb, t_pointc);
void				ft_filltriangle(t_point a, t_point b, t_point c);
/*
** keyboard functions
*/

/*
** mouse functions
*/

/*
** utility functions
*/

void				ft_error(char *str);
int					window_closed(t_data *data);
/*
** init functions
*/

t_data				*init(void);
#endif
