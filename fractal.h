#ifndef FRACTAL_H_
#define FRACTAL_H_

#include "MLX42/MLX42.h"
#include "stdio.h"

#define WIDTH 1000
#define HEIGHT 1000
#define COLOR 0xffffffff

typedef struct point_s
{
	double x;
	double y;
	double Cx;
	double Cy;
} point_t;

void ft_draw(mlx_image_t *img);



#endif