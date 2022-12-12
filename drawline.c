#include "fractal.h"
#include "MLX42/MLX42.h"

point_t ft_pixeltocoordinate(float col, float row)
{
	point_t p;
	int radius = 2;

	//printf("WIDTH:%d, col: %f, row: %f, radius: %d\n", WIDTH, col, row, radius);
	p.x = (col/WIDTH) * 4 - radius;
	p.y = radius - (row/HEIGHT) * 4;

	//printf("p.x: %f\n", p.x);
	//printf("p.y: %f\n", p.y);
	return (p);
}

int ft_mandelbrot(point_t p, int max_iter)
{
	double xbuf;
	int n;
	
	p.Cx = p.x;
	p.Cy = p.y;
	n = 0;
	while (n <= max_iter && ((p.x + p.y) < 16))
	{
		xbuf = p.x;
		p.x = p.x * p.x + p.y * p.y + p.Cx;
		p.y = 2 * p.y * xbuf + p.Cy;
		n++;
	}
	printf("%d\n", n);
	return (n);
}
void ft_draw(mlx_image_t *img)
{
	point_t p;
	float	col;
	int		row;
	int		max_iter;

	row = 0;
	max_iter = 100;
	//mlx_put_pixel(img, 500, 500, COLOR);
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			p = ft_pixeltocoordinate(col, row);
			if (ft_mandelbrot(p, max_iter) >= 100)
			{
				mlx_put_pixel(img, col, row, COLOR);
				printf("hi\n");
			}
			col++;
		}
		row++;
	} 
}







