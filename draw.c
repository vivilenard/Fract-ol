#include "fractal.h"
#include "MLX42/MLX42.h"

point_t ft_pixeltocoordinate(point_t p)
{
		//printf("WIDTH:%d, p.col: %f, p.row: %f, radius: %d\n", WIDTH, p.col, p.row, radius);
	p.Cx = (p.col/WIDTH) * (2 * p.radius) - p.radius + p.movex;
	p.Cy = p.radius - (p.row/HEIGHT) * (2 * p.radius) + p.movey;
	return (p);
}


int ft_mandelbrot(point_t p, int maxiter, mlx_image_t *img)
{
	double xbuf;
	int n;
	
	p.x = p.Cx;
	p.y = p.Cy;
	n = 0;
	while (n < maxiter && ((p.x * p.x) + (p.y * p.y) <=  4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.Cx;
		p.y = 2 * p.y * xbuf + p.Cy;
		n++;
	}
	ft_colorme(p, img, n, maxiter);
	return (n);
}
void ft_draw(mlx_image_t *img, point_t p)
{
	int		maxiter;

	p.row = 0;
	maxiter = 255;
	while (p.row < HEIGHT)
	{
		p.col = 0;
		while (p.col < WIDTH)
		{
			p = ft_pixeltocoordinate(p);
			ft_mandelbrot(p, maxiter, img);
			p.col++;
		}
		p.row++;
	} 
}







