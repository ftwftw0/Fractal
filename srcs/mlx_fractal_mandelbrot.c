/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:41:00 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/08 16:46:49 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void mandel_pixel(t_mlxdata *data, t_ipoint pt)
{
	int			k;
	t_point		z;
	t_point		c;
	t_point		r;

	c.x = data->a.x + pt.x * (data->b.x - data->a.x) / WIDTH;
	c.y = data->a.y + pt.y * (data->b.y - data->a.y) / HEIGHT;
	z.x = 0;
	z.y = 0;
	k = 0;
	while (k++ < data->iterations && (z.x * z.x + z.y * z.y <= 24))
	{
		r.x = z.x;
		r.y = z.y;
		z.x = r.x * z.x - r.y * z.y + c.x;
		z.y = 2 * r.y * r.x + c.y;
	}
	if (k <= data->iterations)
		mlx_putpxl_img(data->img, pt.x, pt.y,
					data->palet->tab[k * 1000 / data->iterations]);
	else
		mlx_putpxl_img(data->img, pt.x, pt.y, 0x00000000);
}

int			mlx_fractal_mandelbrot(t_mlxdata *data)
{
	t_ipoint	pt;

	pt.x = 0;
	pt.y = 0;
	while (pt.x < WIDTH)
	{
		pt.y = 0;
		while (pt.y < HEIGHT)
		{
			mandel_pixel(data, pt);
			pt.y++;
		}
		pt.x++;
	}
	return (1);
}
