#include "fractal.h"

void ft_drawlinehorizontal(mlx_image_t *img, int xa, int xb, int y)
{
    while (xa != xb)
    {
        mlx_put_pixel(img, xa, y, COLOR);
        xa++;
    }
}

void ft_drawline(mlx_image_t *img, point_t p1, point_t p2)
{
    //if either x is the same or y is the same draw a straight line
    if (p1.y == p2.y)  // horizontal
    {
        if (p1.x < p2.x)
            ft_drawlinehorizontal(img, p1.x, p2.x, p1.y);
        else if (p2.x < p1.x)
            ft_drawlinehorizontal(img, p2.x, p1.x, p1.y);
    }
    /*if (p1.x == p2.x)
    {
        if (p1.y < p2.y)
            ft_drawlinevertical(img, p1.y, p2.y, p1.x);
        else if (p2.y < p1.y)
            ft_drawlinevertical(img, p2.y, p1.y, p1.x);
    } */
    //else draw a queer line
}

void ft_draw(mlx_image_t *img)
{
    point_t p1 = {5, 500};
    point_t p2 = {500, 500};
    ft_drawline (img, p1, p2);
    mlx_put_pixel (img, p1.x, p1.y, COLOR);
    mlx_put_pixel (img, p2.x, p2.y, COLOR);
}