/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:16:19 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/08 18:06:31 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mlx_tree_branch(t_mlxdata *data, int nb, int angle)
{
	double	theta;
	t_point a;

	a = data->b;
	theta = PI * (angle - data->angleft) / 180.;
	data->b.x = a.x + cos(theta) * (nb + 2) * data->leftzoom;
	data->b.y = a.y + sin(theta) * (nb + 2) * data->leftzoom;
	a.color = (0x0000ff00 - nb * 10 * 256) & 0x0000ff00;
	mlx_putline(data, a, data->b);
	theta = PI * (angle + data->angright) / 180.;
	if (nb > 0)
		mlx_tree_branch(data, nb - 1, angle - data->angleft);
	data->b.x = a.x + cos(theta) * (nb + 2) * data->rightzoom;
	data->b.y = a.y + sin(theta) * (nb + 2) * data->rightzoom;
	mlx_putline(data, a, data->b);
	if (nb > 0)
		mlx_tree_branch(data, nb - 1, angle + data->angright);
	return (1);
}

int mlx_fractal_tree(t_mlxdata *data)
{
	data->b = data->c;
	data->a = data->c;
	data->b.y -= (data->leftzoom + data->rightzoom) * 10;
	mlx_putline(data, data->a, data->b);
	data->a.x += 2;
	data->b.x += 2;
	mlx_putline(data, data->a, data->b);
	data->a.x -= 1;
	data->b.x -= 1;
	mlx_putline(data, data->a, data->b);
	mlx_tree_branch(data, data->branchs, 270);
	return (1);
}
