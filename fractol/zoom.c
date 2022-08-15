/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:27:20 by akroll            #+#    #+#             */
/*   Updated: 2022/08/15 14:38:28 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#define WIDTH 500
#define HEIGHT 500
#define BPP sizeof(int)


void	detect_keys(void *param)
{
	mlx_t	*mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (mlx_is_mouse_down(mlx, MLX_MOUSE_BUTTON_LEFT))
	// 	puts("click");
}

void zoom_hook(double xdelta, double ydelta, void* param)
{
	(void)param;
	(void)xdelta;
	if (ydelta > 0)
	{
		puts("Zoom out");
	}
	else
	{
		puts("Zoom in");
	}
}

void	draw_line_horizontal(int x_start, int y_start, int size, mlx_image_t *img)
{
	int	x;
	int	y;

	y = y_start;
	while (y < y_start + size)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x > x_start)
			{
				mlx_put_pixel(img, x, y, 0);
			}
			x++;
		}
		y++;
	}
}

void	hook(void *param)
{
	mlx_image_t	*img;
	int			y;
	// float	x_offs = -2;
	// float	y_offs = -2;

	img = param;
	y = 0;
	while (y < HEIGHT)
	{
		draw_line_horizontal(0, y, 3, img);
		y += 10;
	}
}

int main()
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// image width and height
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// put image at position x, y
	mlx_image_to_window(mlx, img, 0, 0);
	// white background
	memset(img->pixels, 255, img->width * img->height * BPP);
	// add hook function to main loop
	mlx_loop_hook(mlx, &detect_keys, mlx);
	mlx_scroll_hook(mlx, &zoom_hook, NULL);
	mlx_loop_hook(mlx, &hook, img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
