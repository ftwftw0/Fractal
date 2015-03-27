/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractol.hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 00:01:42 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/03 16:35:14 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_hook(t_mlxdata *data)
{
	mlx_destroy_image(data->env.mlx, data->img.ptr);
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	which_fractal(data);
	expose_hook(data);
	return (1);
}

int expose_hook(t_mlxdata *data)
{
	mlx_put_image_to_window(data->env.mlx, data->env.window,
							data->img.ptr,
							0, 0);
	mlx_fractal_debug(data);
	return (1);
}
