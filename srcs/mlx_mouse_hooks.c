/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 01:57:57 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/27 14:43:50 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		tree_zoom(int button, t_mlxdata *data)
{
	if (button == 4)
	{
		data->leftzoom *= 1.1;
		data->rightzoom *= 1.1;
	}
	else if (button == 5)
	{
		data->leftzoom /= 1.1;
		data->rightzoom /= 1.1;
	}
}

static void	zoom_hooks(t_mlxdata *data, int button, int x, int y)
{
	double tmp;

	if (button == MSCROLLUP)
	{
		tmp = (data->b.x - data->a.x);
		data->a.x = data->a.x + (tmp * x / WIDTH) / 200;
		data->b.x = data->b.x - (tmp * (1 - (double)x / WIDTH)) / 200;
		tmp = (data->b.y - data->a.y);
		data->a.y = data->a.y + (tmp * y / HEIGHT) / 200;
		data->b.y = data->b.y - (tmp * (1 - (double)y / HEIGHT)) / 200;
	}
	else if (button == MSCROLLDOWN)
	{
		tmp = (data->b.x - data->a.x);
		data->a.x = data->a.x - (tmp * (1 - (double)x / WIDTH)) / 100;
		data->b.x = data->b.x + (tmp * x / WIDTH) / 100;
		tmp = (data->b.y - data->a.y);
		data->a.y = data->a.y - (tmp * (1 - (double)y / HEIGHT)) / 100;
		data->b.y = data->b.y + (tmp * y / HEIGHT) / 100;
	}
}

int			mouse_hook(int button, int x, int y, t_mlxdata *data)
{
	if (data->fractal == 3)
		tree_zoom(button, data);
	else if (button == MSLEFTCLICK)
		data->pause = (data->pause) ? 0 : 1;
	else if (button == MSRIGHTCLICK)
		data->palet = data->palet->next;
	else
		zoom_hooks(data, button, x, y);
	return (1);
}

int			cursor_hook(int x, int y, t_mlxdata *data)
{
	if (!data->pause && data->fractal != 3)
	{
		data->c.x = 4. * x / WIDTH - 2.;
		data->c.y = 4. * y / HEIGHT - 2.;
	}
	return (1);
}
