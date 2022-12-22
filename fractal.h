/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:04:47 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/22 14:08:57 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000
# define COLOR 0xffffffff

typedef struct s_point
{
	double		x;
	double		y;
	double		cx;
	double		cy;
	double		col;
	double		row;
	double		radius;
	double		movex;
	double		movey;
	int			mousex;
	int			mousey;
	int			z;
	int			fractaltype;
	int			maxiter;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_point;

void	ft_draw(mlx_image_t *img, t_point p);
int		ft_torgbt(int r, int g, int b, int t);
void	ft_colormepink(t_point p, mlx_image_t *img, int n);
void	my_scrollhook(double xdelta, double ydelta, void *param);
void	mouse_bindings(void *param);
void	key_bindings(void *param);
void	ft_esc(t_point *p);
void	ft_colormespacey(t_point p, mlx_image_t *img, int n);
void	ft_colormerainbow(t_point p, mlx_image_t *img, int n);
void	ft_colormered(t_point p, mlx_image_t *img, int n);
int		ft_mandelbrot(t_point p, mlx_image_t *img);
int		ft_crazybrot(t_point p, mlx_image_t *img);
int		ft_roastedchicken(t_point p, mlx_image_t *img);
int		ft_julia(t_point p, mlx_image_t *img);

#endif
