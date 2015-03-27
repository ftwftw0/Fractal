/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 01:23:00 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/27 14:41:05 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mv_hooks(int keycode, t_mlxdata *data, double tmp)
{
	if (keycode == ARROWTOP)
	{
		tmp = (data->b.x - data->a.x) / 10;
		data->a.y -= tmp;
		data->b.y -= tmp;
	}
	else if (keycode == ARROWLEFT)
	{
		tmp = (data->b.x - data->a.x) / 10;
		data->a.x -= tmp;
		data->b.x -= tmp;
	}
	else if (keycode == ARROWBOT)
	{
		tmp = (data->b.x - data->a.x) / 10;
		data->a.y += tmp;
		data->b.y += tmp;
	}
	else if (keycode == ARROWRIGHT)
	{
		tmp = (data->b.x - data->a.x) / 10;
		data->a.x += tmp;
		data->b.x += tmp;
	}
}

void	zoom_hooks(int keycode, t_mlxdata *data, double tmp)
{
	if (keycode == IKEY)
	{
		tmp = (data->b.x - data->a.x);
		data->a.x = data->a.x + tmp / 10;
		data->b.x = data->b.x - tmp / 10;
		tmp = (data->b.y - data->a.y);
		data->a.y = data->a.y + tmp / 10;
		data->b.y = data->b.y - tmp / 10;
	}
	else if (keycode == KKEY)
	{
		tmp = (data->b.x - data->a.x);
		data->a.x = data->a.x - tmp / 20;
		data->b.x = data->b.x + tmp / 20;
		tmp = (data->b.y - data->a.y);
		data->a.y = data->a.y - tmp / 20;
		data->b.y = data->b.y + tmp / 20;
	}
}

void	norm_treehooks(int keycode, t_mlxdata *data)
{
	if (keycode == YKEY)
		data->leftzoom++;
	else if (keycode == IKEY)
	{
		data->leftzoom *= 1.1;
		data->rightzoom *= 1.1;
	}
	else if (keycode == HKEY)
		data->leftzoom--;
	else if (keycode == UKEY || keycode == JKEY)
		(keycode == UKEY) ? data->angleft++ : data->angleft--;
	else if (keycode == KKEY)
	{
		data->leftzoom /= 1.1;
		data->rightzoom /= 1.1;
	}
	else if (keycode == OKEY)
		data->angright += 1;
	else if (keycode == LKEY)
		data->angright -= 1;
	else if (keycode == PKEY)
		data->rightzoom++;
	else if (keycode == DOUBLEDOTS)
		data->rightzoom--;
}

void	tree_hooks(int keycode, t_mlxdata *data)
{
	if (keycode == PLUS)
		data->branchs++;
	else if (keycode == MINUS)
		data->branchs--;
	else if (keycode == ARROWTOP)
		data->c.y -= 10;
	else if (keycode == ARROWLEFT)
		data->c.x -= 10;
	else if (keycode == ARROWBOT)
		data->c.y += 10;
	else if (keycode == ARROWRIGHT)
		data->c.x += 10;
	norm_treehooks(keycode, data);
}

int		key_hook(int keycode, t_mlxdata *data)
{
	if (keycode == ESCAPE)
		exit(0);
	else if (keycode == CROCHOPEN && data->fractal > 1)
		data->fractal--;
	else if (keycode == CROCHCLOSE)
		data->fractal++;
	else if (keycode == ARROWOPEN)
		data->model--;
	else if (keycode == ARROWCLOSE)
		data->model++;
	else if (data->fractal == 3)
		tree_hooks(keycode, data);
	else if (keycode == PLUS)
		data->iterations += 10;
	else if (keycode == MINUS)
		data->iterations -= 10;
	else
	{
		mv_hooks(keycode, data, 0);
		zoom_hooks(keycode, data, 0);
	}
	return (1);
}
