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

int ft_burningship(point_t p, int maxiter, mlx_image_t *img) //mandelbar
{
	double xbuf;
	int n;
	
	p.Cx = p.x;
	p.Cy = p.y;
	n = 0;
	while (n < maxiter && (pow(p.x, 4) + pow(p.y, 4) <=  4))
	{
		xbuf = p.x;
		p.x = pow(xbuf, 1) - pow(p.y, 1) + p.Cx;
		//p.y = 2 * (4 * p.y * xbuf * xbuf * xbuf) + (6 * xbuf * xbuf * p.y * p.y) + (4 * xbuf * p.y * p.y * p.y) + p.Cy;
		//p.y = 3 * pow(xbuf, 2) * p.y + 3 * pow(p.y, 2) * xbuf + p.Cy;
		p.y = xbuf * p.y + p.Cy;
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
	maxiter = 100;
	while (p.row < HEIGHT)
	{
		p.col = 0;
		while (p.col < WIDTH)
		{
			p = ft_pixeltocoordinate(p);
			ft_burningship(p, maxiter, img);
			p.col++;
		}
		p.row++;
	} 
}







