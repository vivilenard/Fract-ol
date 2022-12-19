#include "fractal.h"
#include "MLX42/MLX42.h"

point_t ft_pixeltocoordinate(point_t p)
{
	p.x = (p.col/WIDTH) * (2 * p.radius) - p.radius + p.movex;
	p.y = p.radius - (p.row/HEIGHT) * (2 * p.radius) + p.movey;
	return (p);
}


int ft_mandelbrot(point_t p, int maxiter, mlx_image_t *img)
{
	double xbuf;
	int n;
	
	p.Cx = p.x;
	p.Cy = p.y;
	n = 0;
	while (n < maxiter && ((p.x * p.x) + (p.y * p.y) <=  4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.Cx;
		p.y = 2 * p.y * xbuf + p.Cy;
		n++;
	}
	ft_colormepink(p, img, n, maxiter);
	return (n);
}

// int ft_sierpinskitriangle
int ft_julia(point_t p, int maxiter, mlx_image_t *img)
{
	double xbuf;
	int n;
	
	p.Cx = -0.7;
	p.Cy = 0.27015;
	n = 0;
	while (n < maxiter && ((p.x * p.x) + (p.y * p.y) <=  4))
	{
		xbuf = p.x;
		p.x = p.x * p.x - p.y * p.y + p.Cx;
		p.y = 2 * p.y * xbuf + p.Cy;
		n++;
	}
	ft_colormepink(p, img, n, maxiter);
	return (n);
}
void ft_draw(mlx_image_t *img, point_t p)
{
	int		maxiter;

	p.row = 0;
	maxiter = 200;
	while (p.row < HEIGHT)
	{
		p.col = 0;
		while (p.col < WIDTH)
		{
			p = ft_pixeltocoordinate(p);
			ft_julia(p, maxiter, img);
			p.col++;
		}
		p.row++;
	} 
}







