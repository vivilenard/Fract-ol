/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:57:43 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/10 13:56:17 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_options(void)
{
	ft_printf("Please type: ./fractol and choose");
	ft_printf(" one type of fractal afterwards. \n");
	ft_printf("Options: Mandelbrot - Crazybrot - Roastedchicken - Julia\n");
	ft_printf("For Julia you also need to choose two");
	ft_printf(" starting points, e.g:\n");
	ft_printf("-	-0.7	0.27015 \n");
	ft_printf("-	-0.4	0.6 \n");
	ft_printf("-	0.45	0.1428\n");
	ft_printf("-	0	-0.8\n");
	ft_printf("-	-0.835	-0.2321\n");
	ft_printf("For example: ./fractol Julia -0.835 -0.2321\n");
}

t_point	ft_initializedata(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		p;

	mlx = mlx_init(WIDTH, HEIGHT, "fractals", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || !mlx)
		exit(0);
	mlx_image_to_window(mlx, img, 0, 0);
	p.radius = 2;
	p.maxiter = 100;
	p.mlx = mlx;
	p.img = img;
	p.movex = 0;
	p.movey = 0;
	p.z = 1;
	return (p);
}

int	ft_wrongarguments(char **argv)
{
	int	i;

	i = 0;
	while (argv[2][i])
	{
		while (argv[2][i] == '+' || argv[2][i] == '-' || argv[2][i] == '.')
			i++;
		if (ft_isdigit(argv[2][i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (argv[3][i])
	{
		while (argv[3][i] == '+' || argv[3][i] == '-' || argv[3][i] == '.')
			i++;
		if (ft_isdigit(argv[3][i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_input(t_point *p, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		p->fractaltype = 1;
	else if (ft_strcmp(argv[1], "Crazybrot") == 0 && argc == 2)
		p->fractaltype = 2;
	else if (ft_strcmp(argv[1], "Roastedchicken") == 0 && argc == 2)
		p->fractaltype = 3;
	else if (ft_strcmp(argv[1], "Julia") == 0 && argc == 4)
	{
		if (ft_wrongarguments(argv) == 0)
		{
			ft_options();
			mlx_terminate(p->mlx);
			exit(EXIT_FAILURE);
		}
		p->fractaltype = 4;
		p->cx = ft_atodouble(argv[2]);
		p->cy = ft_atodouble(argv[3]);
	}
	else
	{
		ft_options();
		mlx_terminate(p->mlx);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_point	p;

	p = ft_initializedata();
	if (argc < 2 || argc > 5)
		return (ft_options(), 0);
	ft_input(&p, argc, argv);
	ft_draw(p.img, p);
	mlx_scroll_hook(p.mlx, &my_scrollhook, &p);
	mlx_loop_hook(p.mlx, &key_bindings, &p);
	mlx_loop(p.mlx);
	mlx_terminate(p.mlx);
	return (0);
}
