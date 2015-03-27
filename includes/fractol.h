/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:48:39 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/27 15:00:04 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define PI 3.141592
# define WIDTH 400
# define HEIGHT 300
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <complex.h>

# define ABS(x)			(( (x) < 0) ? -(x) : (x) )
# define RGB(r, g, b)	(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

/*
**	Here you can define various fractals parameters
*/
# define ITERATIONS 100

/*
**	Keys
*/
# define MINUS 27
# define PLUS 24
# define CROCHOPEN 33
# define CROCHCLOSE 30
# define ARROWOPEN 43
# define ARROWCLOSE 47
# define ARROWTOP 126
# define ARROWLEFT 123
# define ARROWBOT 125
# define ARROWRIGHT 124
# define UKEY 32
# define YKEY 16
# define HKEY 4
# define JKEY 38
# define KKEY 40
# define OKEY 31
# define LKEY 37
# define PKEY 35
# define DOUBLEDOTS 41
# define IKEY 34
# define MSCROLLUP 5
# define MSCROLLDOWN 4
# define MSRIGHTCLICK 2
# define MSLEFTCLICK 1
# define ESCAPE 53

typedef struct		s_ipoint
{
	int				x;
	int				y;
	int				color;
}					t_ipoint;

typedef struct		s_point
{
	double			x;
	double			y;
	int				color;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
}					t_env;

typedef struct		s_img
{
	void			*ptr;
	t_ipoint		size;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_palet
{
	int				size;
	int				*tab;
	struct s_palet	*next;
}					t_palet;

typedef struct		s_mlxdata
{
	t_env			env;
	int				fractal;
	int				model;
	t_point			a;
	t_point			b;
	t_point			c;
	t_img			img;
	t_palet			*palet;
	double			leftzoom;
	double			rightzoom;
	int				branchs;
	int				angleft;
	int				angright;
	int				color;
	int				pause;
	int				iterations;
}					t_mlxdata;

int					mlx_pixel_putsquare(t_mlxdata *data, int xsize,
										int ysize, int color);
int					mlx_putline(t_mlxdata *data, t_point a, t_point b);
int					mlx_putbigline(t_mlxdata *data, t_point a,
									t_point b, int size);
void				swap_points(t_point *a, t_point *b);
void				swap_xy(t_point *a, t_point *b);
t_mlxdata			*ft_init(int argc, char **argv);
int					*ft_createline(char *str);
t_img				mlx_create_image(t_mlxdata *data, int xsize,
										int ysize, int bpp);
void				mlx_img(t_mlxdata *data);
int					mlx_putpxl_img(t_img img, int x, int y, int color);
void				swap_points(t_point *a, t_point *b);
int					mlx_fractal_mandelcomplex(t_mlxdata *data);
int					mlx_fractal_mandelbrot(t_mlxdata *data);
int					mlx_fractal_burningship(t_mlxdata *data);
int					mlx_fractal_mandelbrotcube(t_mlxdata *data);
int					mlx_fractal_mandelbar(t_mlxdata *data);
int					mlx_fractal_julia(t_mlxdata *data);
int					mlx_fractal_tree(t_mlxdata *data);
int					key_hook(int keycode, t_mlxdata *data);
int					mouse_hook(int button, int x, int y, t_mlxdata *data);
int					cursor_hook(int x, int y, t_mlxdata *data);
int					mlx_getpxl_img(int x, int y, t_img img);
int					mlx_fractal_debug(t_mlxdata *data);
int					expose_hook(t_mlxdata *data);
int					loop_hook(t_mlxdata *data);
void				which_fractal(t_mlxdata *data);
t_palet				mlx_paletmaker(unsigned int c1, unsigned int c2,
									unsigned int c3, int size);
#endif
