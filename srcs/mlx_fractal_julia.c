/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 17:08:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/08 16:27:45 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fuckthenorm(t_point *r, t_point *z, t_mlxdata *data)
{
	(*r).x = (*z).x;
	(*r).y = (*z).y;
	(*z).x = (*r).x * (*r).x - (*r).y * (*r).y + data->c.x;
	(*z).y = 2 * (*r).y * (*r).x + data->c.y;
}

int			mlx_fractal_julia(t_mlxdata *data)
{
	t_point		pt;
	t_point		z;
	t_point		r;
	int			k;

	pt.x = 0;
	while (pt.x < WIDTH)
	{
		pt.y = 0;
		while (pt.y < HEIGHT)
		{
			z.x = data->a.x + pt.x * (data->b.x - data->a.x) / WIDTH;
			z.y = data->a.y + pt.y * (data->b.y - data->a.y) / HEIGHT;
			k = 0;
			while (z.x * z.x + z.y * z.y <= 4 && k++ <= data->iterations)
				fuckthenorm(&r, &z, data);
			if (k <= data->iterations)
				mlx_putpxl_img(data->img, pt.x, pt.y++,
							data->palet->tab[k * 1000 / data->iterations]);
			else
				mlx_putpxl_img(data->img, pt.x, pt.y++, 0x00000000);
		}
		pt.x++;
	}
	return (1);
}
