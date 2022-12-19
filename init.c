#include "fractal.h"
#include "MLX42/MLX42.h"


void ft_exit(point_t *p)
{
	mlx_terminate(p->mlx);
	exit(EXIT_SUCCESS);
}
void ft_initializedata(point_t *p, mlx_t *mlx, mlx_image_t *img)
{
	p->radius = 2;
	p->mlx = mlx;
	p->img = img;
	p->movex = 0;
	p->movey = 0;
}

int ft_init()
{
    mlx_t		*mlx;
    mlx_image_t *img;
	point_t		p;

    mlx = mlx_init(WIDTH, HEIGHT, "fractals", true);
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img || !mlx)
        return (1);
    mlx_image_to_window(mlx, img, 0, 0);
	ft_initializedata(&p, mlx, img);
    ft_draw(img, p);
	mlx_scroll_hook(mlx, &my_scrollhook, &p);
	mlx_loop_hook(mlx, &key_bindings, &p);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}

int main ()
{
    ft_init();
    return (0);
}

