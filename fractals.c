/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:14:33 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/22 14:12:07 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_mandelbrot(t_point p, mlx_image_t *img)
{
	double	xbuf;
	int		n;

	p.cx = p.x;
	p.cy = p.y;
	n = 0;
	while (n < p.maxiter && ((p.x * p.x) + (p.y * p.y) <= 4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.cx;
		p.y = 2 * p.y * xbuf + p.cy;
		n++;
	}
	ft_colormered(p, img, n);
	return (n);
}

int	ft_crazybrot(t_point p, mlx_image_t *img)
{
	double	xbuf;
	int		n;

	p.cx = p.x;
	p.cy = p.y;
	n = 0;
	while (n < p.maxiter && (pow(p.x, 2) + pow(p.y, 2) <= 4))
	{
		xbuf = p.x;
		p.x = sin(pow(xbuf, 2) - (pow(p.y, 2))) + p.cx;
		p.y = (2 * xbuf * p.y) + p.cy;
		n++;
	}
	ft_colormespacey(p, img, n);
	return (n);
}

int	ft_roastedchicken(t_point p, mlx_image_t *img)
{
	double	xbuf;
	int		n;

	p.cx = p.x;
	p.cy = p.y;
	n = 0;
	while (n < p.maxiter && (pow(p.x, 2) + pow(p.y, 2) <= 4))
	{
		xbuf = p.x;
		p.x = sin(pow(xbuf, 2) - (pow(p.y, 2))) + p.cx;
		p.y = sin(2 * xbuf * p.y) + p.cy;
		n++;
	}
	ft_colormespacey(p, img, n);
	return (n);
}

int	ft_julia(t_point p, mlx_image_t *img)
{
	double	xbuf;
	int		n;

	n = 0;
	while (n < p.maxiter && ((p.x * p.x) + (p.y * p.y) <= 4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.cx;
		p.y = 2 * p.y * xbuf + p.cy;
		n++;
	}
	ft_colormerainbow(p, img, n);
	return (n);
}
