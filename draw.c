#include "fractal.h"
#include "MLX42/MLX42.h"

point_t ft_pixeltocoordinate(point_t p)
{
	p.x = (p.col/WIDTH) * (2 * p.radius) - p.radius + p.movex;
	p.y = p.radius - (p.row/HEIGHT) * (2 * p.radius) + p.movey;
	return (p);
}

void ft_draw(mlx_image_t *img, point_t p)
{
	p.row = 0;
	// ft_bzero(img->pixels, HEIGHT * WIDTH * 4);
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
				ft_burnedchicken(p, img);
			else if (p.fractaltype == 4)
				ft_julia(p, img);
			p.col++;
		}
		p.row++;
	} 
}







