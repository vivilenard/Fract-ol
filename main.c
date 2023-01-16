/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:30:31 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/16 14:30:43 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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
