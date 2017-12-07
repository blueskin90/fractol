/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:09:57 by toliver           #+#    #+#             */
/*   Updated: 2017/12/07 22:10:31 by toliver          ###   ########.fr       */
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

typedef struct		s_triangle
{
	t_point			a;
	t_point			b;
	t_point			c;
}					t_triangle;

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

	t_point			a;
	t_point			b;
	t_point			c;
	t_triangle		triangle;
}					t_data;

/*
** printing functions
*/

void				errset1(int *err, int *x, int difinc1, int difinc2);
void				errset2(int *err, int *y, int difinc0, int difinc3);
void				ft_linepart(t_point a, t_point b, t_data *data);
void				ft_line(t_point a, t_point b, t_data *data);
void				ft_triangle(t_triangle triangle, t_data *data);
void				ft_sierpinsky(t_triangle triangle, t_data *data, int i);

t_triangle			ft_uppertri(t_triangle tri);
t_triangle			ft_lefttri(t_triangle tri);
t_triangle			ft_righttri(t_triangle tri);

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
