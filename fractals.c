/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:14:33 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/21 15:41:45 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int ft_mandelbrot(point_t p, mlx_image_t *img)
{
	double xbuf;
	int n;
	
	p.Cx = p.x;
	p.Cy = p.y;
	n = 0;
	while (n < p.maxiter && ((p.x * p.x) + (p.y * p.y) <=  4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.Cx;
		p.y = 2 * p.y * xbuf + p.Cy;
		n++;
	}
	ft_colormered(p, img, n);
	return (n);
}

int ft_crazybrot(point_t p, mlx_image_t *img)
{
	double xbuf;
	int n;
	
	p.Cx = p.x;
	p.Cy = p.y;
	n = 0;
	while (n < p.maxiter && (pow(p.x, 2) + pow(p.y, 2) <=  4))
	{
		xbuf = p.x;
		p.x = sin(pow(xbuf, 2) - (pow(p.y, 2))) + p.Cx;
		p.y = (2 * xbuf * p.y) + p.Cy;
		n++;
	}
	ft_colormespacey(p, img, n);
	return (n);
}

int ft_burnedchicken(point_t p, mlx_image_t *img)
{
	double xbuf;
	int n;
	
	p.Cx = p.x;
	p.Cy = p.y;
	n = 0;
	while (n < p.maxiter && (pow(p.x, 2) + pow(p.y, 2) <=  4))
	{
		xbuf = p.x;
		p.x = sin(pow(xbuf, 2) - (pow(p.y, 2))) + p.Cx;
		p.y = sin(2 * xbuf * p.y) + p.Cy;
		n++;
	}
	ft_colormespacey(p, img, n);
	return (n);
}
int ft_julia(point_t p, mlx_image_t *img)
{
	double xbuf;
	int n;
//cvalues via args
	n = 0;
	while (n < p.maxiter && ((p.x * p.x) + (p.y * p.y) <=  4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.Cx;
		p.y = 2 * p.y * xbuf + p.Cy;
		n++;
	}
	ft_colormerainbow(p, img, n);
	return (n);
}