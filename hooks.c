/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:56:08 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/20 14:37:31 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	point_t *p;
	
	(void) xdelta;
	p = (point_t *)param;
	if (ydelta < 0)
	{
		p->radius *= 0.8;
		mlx_get_mouse_pos(p->mlx, &p->mousex, &p->mousey);
		p->movex = p->movex + (((double)p->mousex/WIDTH) * (2 * p->radius) - p->radius);
		p->movey = p->movey + (p->radius - ((double)p->mousey/HEIGHT) * (2 * p->radius));
		ft_draw(p->img, *p);
	}
	else if (ydelta > 0)	
	{
		p->radius *= 1.2;
		mlx_get_mouse_pos(p->mlx, &p->mousex, &p->mousey);
		p->movex = p->movex + (((double)p->mousex/WIDTH) * (2 * p->radius) - p->radius);
		p->movey = p->movey + (p->radius - ((double)p->mousey/HEIGHT) * (2 * p->radius));
		ft_draw(p->img, *p);
	}
}

void mouse_bindings(void *param)
{
	point_t *p;
	p = (point_t *)param;
	if (mlx_is_mouse_down(p->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(p->mlx, &p->mousex, &p->mousey);
		p->movex = p->movex + (((double)p->mousex/WIDTH) * (2 * p->radius) - p->radius);
		p->movey = p->movey + (p->radius - ((double)p->mousey/HEIGHT) * (2 * p->radius));
		ft_draw(p->img, *p);
	}
}

void key_bindings(void *param)
{
	point_t *p;
	p = (point_t *)param;

	mouse_bindings(p);
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		ft_exit(p);	
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
	{
		p->movey += (p->radius * 0.1);
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
	{
		p->movey -= (p->radius * 0.1);
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
	{
		p->movex -= (p->radius * 0.1);
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
	{
		p->movex += (p->radius * 0.1);
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_1))
	{
		p->z -= 230;
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_2))
	{
		p->z += 230;
		ft_draw(p->img, *p);
	}
}