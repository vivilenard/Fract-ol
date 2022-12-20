#ifndef FRACTAL_H_
#define FRACTAL_H_

#include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"

#define WIDTH 1000
#define HEIGHT 1000
#define COLOR 0xffffffff

typedef struct point_s
{
	double	x;
	double	y;
	double	Cx;
	double	Cy;
	double	col;
	double	row;
	double	radius;
	double	movex;
	double	movey;
	int		mousex;
	int		mousey;
	int		z;
	mlx_t	*mlx;
	mlx_image_t	*img;
} point_t;

typedef struct color_s
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int t;
} color_t;

void ft_draw(mlx_image_t *img, point_t p);
int ft_torgbt(int r, int g, int b, int t);
void ft_colormepink(point_t p, mlx_image_t *img, int n, int maxiter);
void my_scrollhook(double xdelta, double ydelta, void* param);
void mouse_bindings(void *param);
void key_bindings(void *param);
void ft_exit(point_t *p);
void ft_colormespacey(point_t p, mlx_image_t *img, int n, int maxiter);
void ft_colormerainbow(point_t p, mlx_image_t *img, int n, int maxiter);
void ft_colormered(point_t p, mlx_image_t *img, int n, int maxiter);

#endif
