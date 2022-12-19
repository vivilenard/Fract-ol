/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:43:24 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/19 15:34:28 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int ft_torgbt(int r, int g, int b, int t)
{
	unsigned long int color;
	color = (r << 24) + (g << 16) + (b << 8) + t;
	return (color);
}

void ft_colormepink(point_t p, mlx_image_t *img, int n, int maxiter)
{
	if (n == maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	 else	
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 30, 100, n + 20));
}