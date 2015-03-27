/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 00:04:27 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/27 13:59:32 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_tree(t_mlxdata *data)
{
	data->c.color = 0x00663300;
	data->b.color = 0x00663300;
	data->c.x = WIDTH / 2;
	data->c.y = HEIGHT;
	data->b.x = WIDTH / 2;
	data->b.y = 2 * HEIGHT / 3;
	data->angleft = 30;
	data->angright = 10;
	data->leftzoom = 2;
	data->rightzoom = 2;
	data->branchs = 5;
}

static void	init_mandel(t_mlxdata *data)
{
	if (data->fractal == 6)
	{
		data->a.x = -2.10;
		data->a.y = -1.60;
		data->b.y = 1.60;
		data->b.x = 2.10;
	}
	else
	{
		data->a.x = -1.70;
		data->a.y = -1.30;
		data->b.y = 1.30;
		data->b.x = 1.10;
	}
}

int			init_fractal(t_mlxdata *data)
{
	if (data->fractal == 1 || data->fractal == 6)
		init_mandel(data);
	else if (data->fractal == 2)
	{
		data->a.x = -1;
		data->a.y = -1.2;
		data->b.y = 1.2;
		data->b.x = 1;
		data->c.x = 0;
		data->c.x = 0;
	}
	else if (data->fractal == 3)
		init_tree(data);
	else if (data->fractal == 4 || data->fractal == 5)
	{
		data->a.x = -1.3;
		data->a.y = -1.2;
		data->b.y = 1.2;
		data->b.x = 1.4;
	}
	else if (data->fractal == 7)
		init_mandel(data);
	else
		data->fractal = 1;
	return (data->fractal);
}

void		which_fractal(t_mlxdata *data)
{
	static int fractal = -1;

	if (fractal != data->fractal)
		fractal = init_fractal(data);
	else
	{
		if (fractal == 1)
			mlx_fractal_mandelbrot(data);
		else if (fractal == 2)
			mlx_fractal_julia(data);
		else if (fractal == 3)
			mlx_fractal_tree(data);
		else if (fractal == 4)
			mlx_fractal_mandelbar(data);
		else if (fractal == 5)
			mlx_fractal_mandelbrotcube(data);
		else if (fractal == 6)
			mlx_fractal_burningship(data);
		else if (fractal == 7)
			mlx_fractal_mandelcomplex(data);
	}
	mlx_key_hook(data->env.window, key_hook, data);
	mlx_hook(data->env.window, 6, (1L<<6),
			cursor_hook, data);
	mlx_mouse_hook(data->env.window, mouse_hook, data);
}
