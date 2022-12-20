#include "fractal.h"
#include "MLX42/MLX42.h"
#include "libft/libft.h"


void ft_esc(point_t *p)
{
	mlx_terminate(p->mlx);
	exit(EXIT_SUCCESS);
}

void ft_options()
{
	ft_printf("Please type: ./fractol and choose one type of fractal afterwards. \n");
	ft_printf("Options: Mandelbrot - Crazybrot - Echse - Julia\n");
	ft_printf("For Julia you also need to choose two starting points: e.g -0.7 0.27015 \n");
}

void ft_initializedata(point_t *p, mlx_t *mlx, mlx_image_t *img)
{
	p->radius = 2;
	p->mlx = mlx;
	p->img = img;
	p->movex = 0;
	p->movey = 0;
	p->z = 1;
}

int ft_init(char *fractal)
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

int main (int argc, char **argv)
{
	char str[] = "hi";
	argv[1] = str;
	if (argc < 2 || argc > 5)
	{
		ft_options();
		return(0);
	}
	ft_init(*argv);
	return (0);
}

