/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 18:09:35 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 16:22:00 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_palets(t_mlxdata *data)
{
	t_palet	*current;
	t_palet	*tmp;

	if (!(tmp = (t_palet *)malloc(sizeof(t_palet))))
		exit(0);
	*tmp = mlx_paletmaker(0xffffff, 0xff0000, 0xffff00, 1000);
	data->palet = tmp;
	current = (t_palet *)malloc(sizeof(t_palet));
	*current = mlx_paletmaker(0x000000, 0xff0000, 0xffff00, 1000);
	tmp->next = current;
	tmp = current;
	current = (t_palet *)malloc(sizeof(t_palet));
	*current = mlx_paletmaker(0x000000, 0x9999ff, 0xffff00, 1000);
	tmp->next = current;
	tmp = current;
	current = (t_palet *)malloc(sizeof(t_palet));
	*current = mlx_paletmaker(0x000000, 0x66ff66, 0x6666ff, 1000);
	tmp->next = current;
	tmp = current;
	current->next = data->palet;
}

t_mlxdata	*ft_init(int argc, char **argv)
{
	t_mlxdata *data;

	if (!ft_isdigit(argv[argc - 1][0]))
		return (NULL);
	if (!(data = (t_mlxdata*)malloc(sizeof(t_mlxdata))))
		exit(0);
	data->fractal = ft_atoi(argv[1]);
	data->env.mlx = mlx_init();
	data->env.window = mlx_new_window(data->env.mlx, WIDTH, HEIGHT, "Fortytou");
	data->color = 0;
	data->a.x = 0;
	data->a.y = 0;
	data->a.color = 0x00ffffff;
	data->b.x = 0;
	data->b.y = 0;
	data->b.color = 0x00ffffff;
	data->img.ptr = NULL;
	data->img.endian = 1;
	data->img.bpp = 8;
	data->iterations = ITERATIONS;
	data->pause = 0;
	data->model = 1;
	init_palets(data);
	return (data);
}
