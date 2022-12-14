#include "fractal.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *) b)[i] = c ;
		i++;
	}
	return (b);
}

void ft_initializedata(point_t *p)
{
	p->radius = 2;
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	point_t *p;
	p = (point_t *)param;
	xdelta = 5;
	if (ydelta > 0)
		p->radius = p->radius * 0.8;
	else if (ydelta < 0)
		puts("Down!");
}

int ft_init()
{
    mlx_t *mlx;
    mlx_image_t *img;
	point_t *p;
	p = malloc(sizeof(point_t));
    mlx = mlx_init(WIDTH, HEIGHT, "fractals", true);
    if (!mlx)
        return (1);
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img)
        return (1);
    mlx_image_to_window(mlx, img, 0, 0);
    //ft_memset(img->pixels, 0x00000000, img->width * img->height * 4);
	ft_initializedata(p);
    ft_draw(img, *p);
	mlx_scroll_hook(mlx, &my_scrollhook, p);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}

int main ()
{
    ft_init();
    return (0);
}

