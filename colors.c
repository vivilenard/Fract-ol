/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:43:24 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/22 19:48:45 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_torgbt(int r, int g, int b, int t)
{
	unsigned long int	color;

	color = (r << 24) + (g << 16) + (b << 8) + t;
	return (color);
}

void	ft_colormepink(t_point p, mlx_image_t *img, int n)
{
	if (n == p.maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 30, 100, n + 20));
}

void	ft_colormespacey(t_point p, mlx_image_t *img, int n)
{
	if (n == p.maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else if (n > 0.8 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 40, 100, 200 * p.z));
	else if (n > 0.6 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 60, 100 * p.z, 200));
	else if (n > 0.4 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 90, 100 * p.z, 200));
	else if (n > 0.2 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 130, 100, 200));
	else if (n > 0.1 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 150, 100, 200));
	else if (n > 0.075 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 40, 90, 200));
	else
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(n * n * p.z, n * 2, 50, 150 - n * n));
}

void	ft_colormered(t_point p, mlx_image_t *img, int n)
{
	if (n == p.maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else if (n > 0.8 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 40 * p.z, 100, 200));
	else if (n > 0.6 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 60, 100 * p.z, 200));
	else if (n > 0.4 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 90, 100, 200 * p.z));
	else if (n > 0.2 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(0, 130, 100, 200));
	else if (n > 0.1 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(200, 150 * p.z, 100, 200));
	else if (n > 0.075 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(200 * p.z, 40, 90, 200));
	else
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(250 - n * 8, 25, 70 + n * 2 * p.z, 150 - n * n * p.z));
}

void	ft_colormerainbow(t_point p, mlx_image_t *img, int n)
{
	if (n == p.maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	else if (n > 0.6 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row, ft_torgbt(255 * p.z, 0, 0, 255));
	else if (n > 0.4 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(255 * p.z, 140 * p.z, 0, 255));
	else if (n > 0.3 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(255 * p.z, 255, 140 * p.z, 255));
	else if (n > 0.2 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(128 * p.z, 200 * p.z, 0, 255));
	else if (n > 0.1 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(0, 139 * p.z, 139 * p.z, 255));
	else if (n > 0.075 * p.maxiter)
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(140 * p.z, 0, 140 * p.z, 255));
	else
		mlx_put_pixel(img, p.col, p.row,
			ft_torgbt(0 + n * n, 140 + n * n, 150
				- n * 2 + p.z, 150 - n * n + p.z));
}
