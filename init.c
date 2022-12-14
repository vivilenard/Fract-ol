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

point_t scroll(double xdelta, double ydelta, point_t *p)
{
	if (ydelta > 0)
	{
		ft_zoom()
	}
	else if (ydelta < 0)
		puts("Down!");
	(void)param;
	xdelta = 5;
	return (p);
}

int ft_init()
{
    mlx_t *mlx;
    mlx_image_t *img;
	point_t *p;

    mlx = mlx_init(WIDTH, HEIGHT, "fractals", true);
    if (!mlx)
        return (1);
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img)
        return (1);
    mlx_image_to_window(mlx, img, 0, 0);
    //ft_memset(img->pixels, 0x00000000, img->width * img->height * 4);
	p = mlx_scroll_hook(mlx, &scroll, p);
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

