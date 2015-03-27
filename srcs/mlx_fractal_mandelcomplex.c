/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_mandelcomplex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:15:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/27 13:53:00 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

int		mlx_fractal_mandelcomplex(t_mlxdata *data)
{
	t_ipoint		pt;
	int				k;
	_Complex double	z;
	_Complex double	c;

	pt.x = 0;
	while (pt.x < WIDTH)
	{
		pt.y = 0;
		while (pt.y < HEIGHT)
		{
			c = (data->a.x + pt.x * (data->b.x - data->a.x) / WIDTH)
				+ I * (data->a.y + pt.y * (data->b.y - data->a.y) / HEIGHT);
			z = 0;
			k = 0;
			while (k++ < data->iterations && (creal(z) <= 10))
				z = cpow(z, data->model) + c;
			(k <= data->iterations) ? mlx_putpxl_img(data->img, pt.x, pt.y++,
								data->palet->tab[k * 1000 / data->iterations])
				: mlx_putpxl_img(data->img, pt.x, pt.y++, 0x000000);
		}
		pt.x++;
	}
	return (1);
}

int		mouse_hook_mandelcomplex(int button, int x, int y, t_mlxdata *data)
{
	double tmp;

	if (button == 4)
	{
		tmp = (data->b.x - data->a.x);
		data->a.x = data->a.x + (tmp * x / WIDTH) / 200;
		data->b.x = data->b.x - (tmp * (1 - (double)x / WIDTH)) / 200;
		tmp = (data->b.y - data->a.y);
		data->a.y = data->a.y + (tmp * y / HEIGHT) / 200;
		data->b.y = data->b.y - (tmp * (1 - (double)y / HEIGHT)) / 200;
	}
	else if (button == 5)
	{
		tmp = (data->b.x - data->a.x);
		data->a.x = data->a.x - (tmp * (1 - (double)x / WIDTH)) / 100;
		data->b.x = data->b.x + (tmp * x / WIDTH) / 100;
		tmp = (data->b.y - data->a.y);
		data->a.y = data->a.y - (tmp * (1 - (double)y / HEIGHT)) / 100;
		data->b.y = data->b.y + (tmp * y / HEIGHT) / 100;
	}
	return (1);
}
