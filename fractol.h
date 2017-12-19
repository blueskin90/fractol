/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:09:57 by toliver           #+#    #+#             */
/*   Updated: 2017/12/19 08:48:34 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>

# include "mlx.h"
# include "libft.h"
#include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

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

//typedef struct s_data t_data;

typedef	struct		s_fractale
{

	t_complex		c;

	double			zoom;
	t_complex		tran;
	t_complex		last_offset;
	t_complex		zoompos;
	t_complex		offset;

	int				locked;
	int				ite;
	int				imgx;
	int				imgy;
	double			minx;
	double			maxx;
	double			miny;
	double			maxy;
	void			*img;
	char			*img_str;
	void			*miniimg;
	char			*miniimg_str;
	long double		(*formula)(t_complex, t_complex, int);
}					t_fractale;

typedef struct		s_color
{
	int				value;
	long double		index;
	struct s_color	*next;
}					t_color;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;

	int				winx;
	int				winy;

	int				menu;
	int				key[279];
	int				button[7];
	int				buttonx[7];
	int				buttony[7];
//	int				color[2];
//	int				palette_size;
	t_color			*color;

	t_triangle		triangle;

	t_fractale		*mandelbrot;
	t_fractale		*julia;
	t_fractale		*burningship;

	t_fractale		*onscreen;
	t_fractale		*screen1;
	t_fractale		*screen2;
	t_fractale		*screen3;

//	typedef (void)(*gen)(t_data*) generator;
	long double		test;
	long double		test2;

	int				ite; // nombre d'iterations
}					t_data;

typedef struct		s_part
{
	int				y;
	t_complex		z;
	t_fractale		*fra;
	t_data			*data;
}					t_part;

/*
** printing functions
*/

void				ft_sierpinsky(t_triangle triangle, t_data *data, int i);
void				errset1(int *err, int *x, int difinc1, int difinc2);
void				errset2(int *err, int *y, int difinc0, int difinc3);
void				ft_linepart(t_point a, t_point b, t_data *data);
void				ft_line(t_point a, t_point b, t_data *data);
void				ft_triangle(t_triangle triangle, t_data *data);
t_triangle			ft_uppertri(t_triangle tri);
t_triangle			ft_lefttri(t_triangle tri);
t_triangle			ft_righttri(t_triangle tri);
void				px_to_onscreenimg(t_data *data, int x, int y, int c);

void				*ft_fractal(void *part);
void				*ft_minifractal(void *part);
/*
** fonction in testing
*/

int					middlebuttonhandle(int x, int y, t_data *data);
int					button_off(int button, int x, int y, t_data *data);
t_complex			ft_mousecoord(double x, double y, t_fractale *fra, t_data *data);

t_part				*ft_palloc(t_data *data, int i, t_fractale *fra);
void				ft_triangleinit(t_data *data);
int					RGBgradtest(long double retval, t_data *data, t_fractale *fract);
void				px_to_miniimg(t_fractale *fract, int x, int y, int c);
void				print_img(t_data *data);
void				ft_printcolor(long double retvalue, t_data *data, int x, int y);
int					RGB(unsigned char R, unsigned char G, unsigned char B);
int					RGBgrad(int col1, int col2, unsigned int steps);
int					getstep(unsigned char v1, unsigned char v2, long double retval);
unsigned char		get_color(int c, char color);
int					ft_gradcolor(double retval, t_data *data);
void				ft_refresh(t_data *data);


void				ft_onscreenprint(t_data *data, t_fractale *fract);

void				coloradd(t_data *data, int color, long double index);

/*
** menu functions
*/

void				menu(t_data *data);
/*
** burningship functions
*/

//void				*ft_burningship(void *p);
long double			ft_burningship(t_complex c, t_complex z, int ite);
void				*ft_miniburningship(void *data);
/*
** mandelbrot functions
*/

//void				*ft_mandelbrot(void *p);
long double			ft_mandelbrot(t_complex c, t_complex z, int ite);
void				*ft_minimandelbrot(void *data);
/*
** julia functions
*/

long double			ft_julia(t_complex c, t_complex z, int ite);
void				*ft_minijulia(void *data);

/*
** keyboard functions
*/

int					key_on(int keycode, t_data *data);

/*
** mouse functions
*/

int					mouse_mov(int x, int y, t_data *data);
int					button_on(int button, int x, int y, t_data *data);
void				leftbuttonhandle(int x, int y, t_data *data);

/*
** utility functions
*/

void				*ft_malloc(int size);
void				ft_error(char *str);
int					window_closed(t_data *data);

void				ft_printite(t_data *data);


/*
** complex handling functions
*/

t_complex			ft_complex(int x, int y, t_data *data); // convertis en complexe
t_complex			ft_comp(int x, int y);
t_complex			ft_cadd(t_complex c1, t_complex c2); // addition de complexes
t_complex			ft_csqr(t_complex comp); // square du complexe
t_complex			ft_cabs(t_complex c); // retourne la valeur absolue
t_complex			ft_cmul(t_complex c1, t_complex c2);
double				ft_cmod(t_complex comp); // donne la norme du vecteur
long double			ft_checkvalue(t_complex comp); // pour verif ca < limit(carre)
t_complex			ft_coord(double x, double y, t_fractale *fra, t_data *dat);
t_complex			ft_mcoord(double x, double y, t_fractale *fra, t_data *dat);
t_complex			ft_coordzoom(double x, double y, t_fractale *fra, t_data *dat);
/*
** init functions
*/

void				ft_fractset(t_data *data);
t_data				*init(void);
void				mlx_img_init(t_data *data);
#endif
