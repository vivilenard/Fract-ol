#include "fractal.h"
#include "MLX42/MLX42.h"

point_t ft_pixeltocoordinate(point_t p)
{
	p.radius = 2;
		//printf("WIDTH:%d, p.col: %f, p.row: %f, radius: %d\n", WIDTH, p.col, p.row, radius);
	p.x = (p.col/WIDTH) * 4 - p.radius;
	p.y = p.radius - (p.row/HEIGHT) * 4;
	return (p);
}

void ft_colorme(point_t p, mlx_image_t *img, int n, int maxiter)
{
	unsigned int	color[maxiter - 1];
	int				i;

	i = 0;
	color[i] = 0xCB0F6400;
	i++;
	// while (i < maxiter - 1)
	// {
	// 	color[i] = 
	// 	i++;
	// }

	if (n == 0)
		mlx_put_pixel(img, p.col, p.row, 255);
	if (n == maxiter)
		mlx_put_pixel(img, p.col, p.row, 255);
	 else	
	 	mlx_put_pixel(img, p.col, p.row, color[i]);
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
	ft_colorme(p, img, n, maxiter);
	
	return (n);
}
void ft_draw(mlx_image_t *img)
{
	point_t p;
	int		maxiter;

	p.row = 0;
	maxiter = 100;
	//mlx_put_pixel(img, 500, 500, p.COLOR);
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







