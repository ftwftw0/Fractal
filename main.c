/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:09:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 16:20:13 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_mlxdata	*data;

	if (argc < 2)
		return (-1);
	if (!(data = ft_init(argc, argv)))
		return (-1);
	data->img = mlx_create_image(data, WIDTH, HEIGHT, 32);
	which_fractal(data);
	mlx_expose_hook(data->env.window, expose_hook, data);
	mlx_loop_hook(data->env.mlx, loop_hook, data);
	mlx_loop(data->env.mlx);
	return (1);
}
