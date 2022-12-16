#include "fractal.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

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

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	point_t *p;
	
	(void) xdelta;
	p = (point_t *)param;
	if (ydelta < 0)
	{
		p->radius *= 0.8;
		ft_draw(p->img, *p);
	}
	else if (ydelta > 0)	
	{
		p->radius *= 1.2;
		ft_draw(p->img, *p);
	}
}

void mouse_bindings(void *param)
{
	point_t *p;
	p = (point_t *)param;

	mlx_get_mouse_pos(p->mlx, &p->mousex, &p->mousey);
	if (mlx_is_mouse_down(p->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		p->movex += ft_pixeltocoordinate(p->mousex);
		p->movey += p->mousey;
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
		p->movey += 0.2;
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
	{
		p->movey -= 0.2;
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
	{
		p->movex -= 0.2;
		ft_draw(p->img, *p);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
	{
		p->movex += 0.2;
		ft_draw(p->img, *p);
	}
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

