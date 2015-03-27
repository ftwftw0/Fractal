/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_paletmaker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 02:47:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 15:47:48 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	getcolorscoefs(double **rgb, unsigned int c1, unsigned int c2, int size)
{
	(*rgb)[0] = (c1 & 0xff0000) >> 16;
	(*rgb)[0] -= ((c2 & 0xff0000) >> 16);
	(*rgb)[0] /= size;
	(*rgb)[1] = (c1 & 0x00ff00) >> 8;
	(*rgb)[1] -= ((c2 & 0x00ff00) >> 8);
	(*rgb)[1] /= size;
	(*rgb)[2] = (c1 & 0x0000ff);
	(*rgb)[2] -= (c2 & 0x0000ff);
	(*rgb)[2] /= size;
}

void	filltab(int *tab, double *rgb, unsigned int c1, int size)
{
	double	color[3];
	int		i;

	i = 0;
	color[0] = (c1 & 0xff0000) >> 16;
	color[1] = (c1 & 0x00ff00) >> 8;
	color[2] = (c1 & 0x0000ff);
	while (i++ < size)
	{
		color[0] -= rgb[0];
		color[1] -= rgb[1];
		color[2] -= rgb[2];
		tab[i] = ((int)color[0] << 16) + ((int)color[1] << 8) + (int)color[2];
	}
}

t_palet	mlx_paletmaker(unsigned int c1, unsigned int c2,
						unsigned int c3, int size)
{
	t_palet	palet;
	int		tmp;
	int		i;
	double	*rgb;

	tmp = size / 3;
	i = 0;
	if (!(rgb = (double *)malloc(sizeof(double) * 3)))
		exit(0);
	palet.size = size;
	palet.tab = (int *)malloc(sizeof(int) * size);
	palet.tab[i] = c1;
	getcolorscoefs(&rgb, c1, c2, tmp);
	filltab(palet.tab, rgb, c1, tmp);
	getcolorscoefs(&rgb, c2, c3, tmp);
	filltab(&(palet.tab[tmp]), rgb, c2, tmp);
	getcolorscoefs(&rgb, c3, c1, tmp);
	filltab(&(palet.tab[tmp * 2]), rgb, c3, tmp);
	return (palet);
}
