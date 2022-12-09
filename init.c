#include "fractal.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct point_s
{
    int x;
    int y;  
} point_t;

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

void ft_drawline(mlx_image_t *img, point_t p1, point_t p2)
{
    //if either x is the same or y is the same draw a straight line

    //else draw a queer line
}

void ft_draw(mlx_image_t *img)
{
    point_t p1 = {5, 500};
    point_t p2 = {500, 500};
    ft_drawline (img);
    mlx_put_pixel (img, p1.x, p1.y, 0xFFFFFFFF);
    mlx_put_pixel (img, p2.x, p2.y, 0xFFFFFFFF);
}

int ft_init()
{
    mlx_t *mlx;
    mlx_image_t *img;

    mlx = mlx_init(WIDTH, HEIGHT, "fractals", true);
    if (!mlx)
        return (1);
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img)
        return (1);
    mlx_image_to_window(mlx, img, 0, 0);
    ft_memset(img->pixels, 50, img->width * img->height * 4);
    ft_draw(img);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}

int main ()
{
    ft_init();
    return (0);
}

