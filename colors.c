/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:43:24 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/14 15:43:51 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int ft_torgbt(int r, int g, int b, int t)
{
	unsigned long int color;
	color = (r << 24) + (g << 16) + (b << 8) + t;
	return (color);
}

void ft_colorme(point_t p, mlx_image_t *img, int n, int maxiter)
{
	int	i;
	int	t[255];

	i = 1;
	t[0] = 10;
	while (i < 253)
	{
		t[i] = 10 + i;
		i++;
	}
	i = 1;
	if (maxiter > 255)
		i = 1 - 255 / maxiter;
	if (n == maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	 else	
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 30, 110, t[n * i]));
}