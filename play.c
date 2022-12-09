#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "MLX42/MLX42.h"
#define WIDTH 720
#define HEIGHT 480

static void ft_hook(void* param)
{
	const mlx_t* mlx;

	mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int main ()
{
	mlx_t *mlx;
	mlx_image_t *img;
	mlx = mlx_init(WIDTH, HEIGHT, "play", true);
	if (!mlx)
		return(EXIT_FAILURE);
	img = mlx_new_image(mlx, 200, 200);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	mlx_put_pixel(img, 0, 0, 0x0000FF);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}