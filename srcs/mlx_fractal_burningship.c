/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_burningship.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:53:49 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/08 15:27:32 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fuckthenorm(t_point *r, t_point *z, t_point *c)
{
	(*r).x = (*z).x;
	(*r).y = (*z).y;
	(*z).x = ABS((*r).x) * ABS((*z).x) - ABS((*r).y) * ABS((*z).y) + (*c).x;
	(*z).y = 2 * ABS((*r).y) * ABS((*r).x) + (*c).y;
}

static void		burningship_lines(t_mlxdata *data, t_ipoint pt)
{
	t_point		z;
	t_point		c;
	t_point		r;
	int			k;

	c.x = data->a.x + pt.x * (data->b.x - data->a.x) / WIDTH;
	c.y = data->a.y + pt.y * (data->b.y - data->a.y) / HEIGHT;
	z.x = 0;
	z.y = 0;
	k = 0;
	while (k++ < data->iterations && (z.x * z.x + z.y * z.y <= 24))
		fuckthenorm(&r, &z, &c);
	if (k <= data->iterations)
		mlx_putpxl_img(data->img, pt.x, pt.y,
					data->palet->tab[k * 1000 / data->iterations]);
	else
		mlx_putpxl_img(data->img, pt.x, pt.y, 0x00000000);
}

int				mlx_fractal_burningship(t_mlxdata *data)
{
	t_ipoint	pt;

	pt.x = 0;
	pt.y = 0;
	while (pt.x < WIDTH)
	{
		pt.y = 0;
		while (pt.y < HEIGHT)
		{
			burningship_lines(data, pt);
			pt.y++;
		}
		pt.x++;
	}
	return (1);
}
