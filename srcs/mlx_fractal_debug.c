/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fractal_debug.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 21:30:37 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/27 14:54:35 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_fractal_debug(t_mlxdata *data)
{
	char *nb;

	mlx_string_put(data->env.mlx, data->env.window, 10, 10, 0x00fffffd,
					"C      : ");
	mlx_string_put(data->env.mlx, data->env.window, 100, 10, 0x00fffffd,
					(nb = ft_dtoa(data->c.x, 3)));
	free(nb);
	mlx_string_put(data->env.mlx, data->env.window, 150, 10, 0x00fffffd,
					(nb = ft_dtoa(data->c.y, 3)));
	free(nb);
	mlx_string_put(data->env.mlx, data->env.window, 10, 30, 0x00fffffd,
					"Iter   : ");
	mlx_string_put(data->env.mlx, data->env.window, 100, 30, 0x00fffffd,
					(nb = ft_itoa(data->iterations)));
	free(nb);
	mlx_string_put(data->env.mlx, data->env.window, 10, 50, 0x00fffffd,
					"Fractal: ");
	mlx_string_put(data->env.mlx, data->env.window, 100, 50, 0x00fffffd,
					(nb = ft_itoa(data->fractal)));
	free(nb);
	return (1);
}
