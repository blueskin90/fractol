/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:09:57 by toliver           #+#    #+#             */
/*   Updated: 2018/01/02 19:53:47 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define XM (x + m)
# define CM (c + m)
# define WINX data->winx
# define WINY data->winy
# define ONSCREEN data->onscreen
# define INT_MAX 2147483647
# include <stdio.h>

# include "mlx.h"
# include "libft.h"
# include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_hsv
{
	float			h;
	float			s;
	float			v;
}					t_hsv;

typedef struct		s_complex
{
	float			r;
	float			i;
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

typedef	struct		s_fractale
{

	t_complex		c;

	float			zoom;
	t_complex		tran;
//	t_complex		last_offset;
	t_complex		zoompos;
	t_complex		offset;

	int				locked;
	int				ite;
	int				imgx;
	int				imgy;
	float			minx;
	float			maxx;
	float			miny;
	float			maxy;
	void			*img;
	char			*img_str;
	void			*miniimg;
	char			*miniimg_str;
	float		(*formula)(t_complex, t_complex, int);
}					t_fractale;

typedef struct		s_color
{
	int				locked;
	int				clicked;
	int				hover;
	int				value;
	float		index;
	t_hsv			hsv;
	t_rgb			rgb;
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
	int				scrollmenuoffset;
	int				colormenu;
	int				clickedsquare;
	int				clickedrainbow;
	int				clickedr;
	int				clickedg;
	int				clickedb;
	int				pickedcolor;
	t_color			*editedcolor;
	int				colorchanged;
	int				key[279];
	int				button[7];
	int				buttonx[7];
	int				buttony[7];
	t_color			*color;

	t_triangle		triangle;

	t_fractale		*mandelbrot;
	t_fractale		*julia;
	t_fractale		*burningship;
	t_fractale		*multibrot;
	t_fractale		*glynn;
	t_fractale		*mandeldrop;
	t_fractale		*mandelheart;

	t_fractale		*onscreen;
	t_fractale		*screen[6];
//	typedef (void)(*gen)(t_data*) generator;
//	float		test;
//	float		test2;

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
void				ft_line(t_point a, t_point b, t_data *data, int color);
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

t_part				ft_palloc(t_data *data, int i, t_fractale *fra);
void				ft_triangleinit(t_data *data);
void				px_to_miniimg(t_fractale *fract, int x, int y, int c);
void				print_img(t_data *data);
void				ft_printcolor(float retvalue, t_data *data, int x, int y);
int					getstep(unsigned char v1, unsigned char v2, float retval);
void				ft_refresh(t_data *data);
void				ft_onscreenprint(t_data *data, t_fractale *fract);
t_point				ft_point(int x, int y);
void				ft_clickset(t_data *data);
int					ft_clickget(t_data *data, int x, int y);
void				ft_hoverget(t_data *data, int x, int y);
int					get_px_color(t_data *data, int x, int y);

float				ft_cangle(t_complex c);

/*
** print functions
*/

void				printlosange(t_data *data, t_point p, int size, int color);
void				printrectangle(t_data *d, t_point p, t_point size, int col);
void				printemptyrectangle(t_data *d, t_point p, t_point s, int c);
void				printsquare(t_data *data, t_point pos, int size, int color);
void				pcirloop(t_data *data, t_point p1, t_point p2, int color);
void				errset(int *y, int *err, int *dy);
void				printcircle(t_point p, int rad, t_data *data, int color);
void				printemptycircle(t_point p, int rad, t_data *data, int col);
void				pcirloop2(t_data *data, t_point p1, t_point p2, int color);
void				printhabar(t_data *data, int width, int offset, int alpha);
void				printvabar(t_data *data, int width, int offset, int alpha);
void				printarectangle(t_data *dat, t_point coord, t_point size, 
									int alpha);
void				printarrow(t_data *data, t_point p, int color);
void				printlockedpreset(t_data *data, int x, int y, int color);
void				printpreset(t_data *data, int x, int y, int color);
void				printbigpreset(t_data *data, int x, int y, int color);
void				printclickpreset(t_data *data, int x, int y, int color);
void				printrainbowgradient(t_data *data, t_point p, t_point s);
void				printrainbowpreset(t_data *data);
int					colorpicker(t_point pos, int size, int color);
void				printcolorpicker(t_data *data, t_point pos, int s, int c);
void				printcolorpickerpreset(t_data *data, t_point p);
t_point				colorpickerpresetpos(t_hsv hsv);
void				printgradient(t_data *data);
int					rainbow(int sizemax, int actualpos);
void				setblue(int *blue, float step);
void				setgreen(int *green, float step);
void				setred(int *red, float step);
int					get_closestcolor(t_color *color);
void				printcolorsquare(t_data *data, t_point p, int size, int c);
void				printrgbpreset(t_data *data, int x, int y);
void				printrgbbar(t_data *data, t_point p, t_point s, int color);
int					rgbsliderpos(unsigned char value);
void				printrgbslider(t_data *data, t_point p, t_point s, int col);
void				printrgbpicker(t_data *data);

/*
** color functions
*/

void				coloradd(t_data *data, int color, float index);
int					colordel(t_data *data);
void				ft_reorganize_colors(t_data *data);
int					ft_gradcolor(float retval, t_data *data);
//unsigned char		get_color(int c, char color);
t_rgb				int_to_rgb(int color);
int					get_rgb(unsigned char r, unsigned char g, unsigned char b);
int					rgb_grad(float retval, t_data *data, t_fractale *fra);
int					hsv_to_rgb(t_hsv hsv);
t_hsv				rgb_to_hsv(int color);
void				modifyhue(int y, t_data *data);
void				modifysv(int x, int y, t_data *data);
int					rgb_to_int(t_rgb rgb);
void				modifyrgb(int x, t_data *data);
/*
** printscreen functions
*/

void				ft_printscreen(t_data *data);

/*
** menu functions
*/

void				menu(t_data *data);
void				gradientmenu (t_data *data);
void				colormenu(t_data *data);

/*
** fractal functions
*/

float			ft_glynn(t_complex c, t_complex z, int ite);
float			ft_burningship(t_complex c, t_complex z, int ite);
float			ft_mandelbrot(t_complex c, t_complex z, int ite);
float			ft_julia(t_complex c, t_complex z, int ite);
float			ft_multibrot(t_complex c, t_complex z, int ite);
float			ft_mandeldrop(t_complex c, t_complex z, int ite);
float			ft_mandelheart(t_complex c, t_complex z, int ite);
/*
** keyboard functions
*/

int					key_on(int keycode, t_data *data);

/*
** mouse functions
*/

int					middlebuttonhandle(int x, int y, t_data *data);
int					button_off(int button, int x, int y, t_data *data);
t_complex			ft_mousecoord(float x, float y, t_fractale *fra, t_data *data);
int					mouse_mov(int x, int y, t_data *data);
int					button_on(int button, int x, int y, t_data *data);
void				leftbuttonclick(int x, int y, t_data *data);
int					leftbuttonhandle(int x, int y, t_data *data);
int					movingpresets(int y, t_data *data);
int					rightbuttonclick(int x, int y, t_data *data);
void				menuhandle(int x, int y, t_data *data);
void				colormenuhandle(int x, int y, t_data *data);
void				rgbmenuhandle(int x, int y, t_data *data);
int					ft_clickget(t_data *data, int x, int y);
void				ft_clickset(t_data *data);
void				ft_hoverget(t_data *data, int x, int y);
void				scrollbutton(int button, int x, int y, t_data *data);
void				zoom(int zoom, int x, int y, t_data *data);

/*
** utility functions
*/

void				*ft_malloc(int size);
void				ft_error(char *str);
int					window_closed(t_data *data);
float				ft_min(float a, float b, float c);
float				ft_max(float a, float b, float c);
void				ft_printite(t_data *data);
void				ptrswap(t_fractale **ptr1, t_fractale **ptrd, t_data *data);

/*
** complex handling functions
*/

t_complex			ft_complex(int x, int y, t_data *data); // convertis en complexe
t_complex			ft_comp(float x, float y);
t_complex			ft_cadd(t_complex c1, t_complex c2); // addition de complexes
t_complex			ft_csqr(t_complex comp); // square du complexe
t_complex			ft_cabs(t_complex c); // retourne la valeur absolue
t_complex			ft_cmul(t_complex c1, t_complex c2);
float				ft_cmod(t_complex comp); // donne la norme du vecteur
float			ft_checkvalue(t_complex comp); // pour verif ca < limit(carre)
t_complex			ft_coord(float x, float y, t_fractale *fra, t_data *dat);
t_complex			ft_mcoord(float x, float y, t_fractale *fra, t_data *dat);
t_complex			ft_coordzoom(float x, float y, t_fractale *fra, t_data *dat);
t_complex			ft_cpow(t_complex c, float pow);
t_complex			ft_conj(t_complex c);
t_complex			ft_cinv(t_complex c);
/*
** init functions
*/

void				ft_fractset(t_data *data);
t_data				*init(void);
void				mlx_img_init(t_data *data);
void				img_init(t_fractale *fract, t_data *data);
t_fractale			*fractalinit(t_data *data);
void				colorinit(t_data *data);
void				boolinit(t_data *data);
#endif
