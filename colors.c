/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:43:24 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/20 12:44:44 by vlenard          ###   ########.fr       */
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

void ft_colormespacey(point_t p, mlx_image_t *img, int n, int maxiter)
{
	if (n == maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else if (n > 0.8 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 40, 100, 200));
	else if (n > 0.6 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 60, 100, 200));
	else if (n > 0.4 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 90, 100, 200));
	else if (n > 0.2 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 130, 100, 200));
	else if (n > 0.1 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 150, 100, 200));
	else if (n > 0.075 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 40, 90, 200));
	else
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(n * n, n * 2, 50, 150 - n * n));
}

void ft_colormered(point_t p, mlx_image_t *img, int n, int maxiter)
{
	if (n == maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else if (n > 0.8 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 40, 100, 200));
	else if (n > 0.6 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 60, 100, 200));
	else if (n > 0.4 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 90, 100, 200));
	else if (n > 0.2 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 130, 100, 200));
	else if (n > 0.1 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 150, 100, 200));
	else if (n > 0.075 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 40, 90, 200));
	else
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(250 - n * 8, 25, 70 + n * 2, 150 - n * n));
}

void ft_colormerainbow(point_t p, mlx_image_t *img, int n, int maxiter)
{
	if (n == maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else if (n > 0.8 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 40, 100, 200));
	else if (n > 0.6 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 60, 100, 200));
	else if (n > 0.4 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 90, 100, 200));
	else if (n > 0.2 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 130, 100, 200));
	else if (n > 0.1 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 150, 100, 200));
	else if (n > 0.075 * maxiter)
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 40, 90, 200));
	else
	 	mlx_put_pixel(img, p.col, p.row, ft_torgbt(250 - n * 8, 25, 70 + n * 2, 150 - n * n));
}