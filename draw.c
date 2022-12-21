/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:41:00 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/21 18:02:57 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

point_t	ft_pixeltocoordinate(point_t p)
{
	p.x = (p.col / WIDTH) * (2 * p.radius) - p.radius + p.movex;
	p.y = p.radius - (p.row / HEIGHT) * (2 * p.radius) + p.movey;
	return (p);
}

void	ft_draw(mlx_image_t *img, point_t p)
{
	p.row = 0;
	while (p.row < HEIGHT)
	{
		p.col = 0;
		while (p.col < WIDTH)
		{
			p = ft_pixeltocoordinate(p);
			if (p.fractaltype == 1)
				ft_mandelbrot(p, img);
			else if (p.fractaltype == 2)
				ft_crazybrot(p, img);
			else if (p.fractaltype == 3)
				ft_roastedchicken(p, img);
			else if (p.fractaltype == 4)
				ft_julia(p, img);
			p.col++;
		}
		p.row++;
	}
}
