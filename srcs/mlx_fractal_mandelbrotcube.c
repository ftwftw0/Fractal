/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_mandelbrotcube.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 12:49:27 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/08 17:11:24 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrotcube_pixel(t_mlxdata *data, t_ipoint pt)
{
	int		k;
	t_point z;
	t_point c;
	t_point r;

	c.x = data->a.x + pt.x * (data->b.x - data->a.x) / WIDTH;
	c.y = data->a.y + pt.y * (data->b.y - data->a.y) / HEIGHT;
	z.x = 0;
	z.y = 0;
	k = 0;
	while (k++ <= data->iterations && (z.x * z.x + z.y * z.y <= 4))
	{
		r.x = z.x;
		r.y = z.y;
		z.x = r.x * r.x * r.x - 3 * r.x * r.y * r.y + c.x;
		z.y = -r.y * r.y * r.y + 3 * z.y * r.x * r.x + c.y;
	}
	if (k < data->iterations)
		mlx_putpxl_img(data->img, pt.x, pt.y,
					data->palet->tab[k * 1000 / data->iterations]);
}

int			mlx_fractal_mandelbrotcube(t_mlxdata *data)
{
	t_ipoint pt;

	pt.x = 0;
	pt.y = 0;
	while (pt.x < WIDTH)
	{
		pt.y = 0;
		while (pt.y < HEIGHT)
		{
			mandelbrotcube_pixel(data, pt);
			pt.y++;
		}
		pt.x++;
	}
	return (1);
}
