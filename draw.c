/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:41:00 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/10 14:06:10 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_point	ft_pixeltocoordinate(t_point p)
{
	p.x = (p.col / WIDTH) * (2 * p.radius) - p.radius + p.movex;
	p.y = p.radius - (p.row / HEIGHT) * (2 * p.radius) + p.movey;
	return (p);
}

void	ft_draw(mlx_image_t *img, t_point p)
{
	p.row = 0;
	while (p.row < HEIGHT)
	{
		p.col = 0;
		while (p.col < WIDTH)
		{
			p = ft_pixeltocoordinate(p);
			if (p.fractaltype == 1)
			{
				p.maxiter = 300;
				ft_mandelbrot(p, img);
			}
			else if (p.fractaltype == 2)
				ft_crazybrot(p, img);
			else if (p.fractaltype == 3)
				ft_roastedchicken(p, img);
			else if (p.fractaltype == 4)
			{
				p.maxiter = 400;
				ft_julia(p, img);
			}
			p.col++;
		}
		p.row++;
	}
}
