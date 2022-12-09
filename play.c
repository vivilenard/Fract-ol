#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "MLX42/MLX42.h"
#define WIDTH 1000
#define HEIGHT 1000
#define BPP sizeof(int32_t)

/*static void ft_hook(void* param)
{
	const mlx_t* mlx;

	mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
*/

int main ()
{
	mlx_t *mlx;
	mlx_image_t *img;
	mlx = mlx_init(WIDTH, HEIGHT, "play", true);
	if (!mlx)
		return(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	//if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	//	return (EXIT_FAILURE);
	mlx_image_to_window(mlx, img, 5, 5);
	memset(img->pixels, 75, img->width * img->height * BPP);
	mlx_put_pixel(img, 500, 500, 0xFFFFFFFF);
	//mlx_loop_hook(mlx, ft_hook, mlx); */
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
