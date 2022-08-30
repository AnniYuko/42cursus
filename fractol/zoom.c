/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:27:20 by akroll            #+#    #+#             */
/*   Updated: 2022/08/30 16:58:50 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#define WIDTH 500
#define HEIGHT 500
#define BLACK 0
#define BPP sizeof(int)

typedef struct screen_coord {
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int scale;
	int offset;
} screen_coord;

screen_coord	screen;

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
	int zoom = 10;
	(void)xdelta;
	(void)param;

	if (ydelta > 0)
	{
		puts("Zoom out");
	}
	else
	{
		puts("Zoom in");
		screen.x_start += zoom;
		screen.x_end -= zoom;

		// screen.scale = (screen.x_end - screen.x_start) / (screen.y_end - screen.y_start);
		// screen.offset = 0;
		screen.y_start += zoom;
		screen.y_end -= zoom;
	}
}

void	draw_square(int x_start, int y_start, int size, mlx_image_t *img)
{
	int	x;
	int	y;

	y = screen.y_start;
	while (y < screen.y_end)
	{
		x = screen.x_start;
		while (x < screen.x_end)
		{
			if (y >= y_start && y < y_start + size
				&& x >= x_start && x < x_start + size)
			{
				mlx_put_pixel(img, x, y, BLACK);
			}
			x++;
		}
		y++;
	}
}

void	hook(void *param)
{
	mlx_image_t	*img;

	img = param;
	memset(img->pixels, 255, img->width * img->height * BPP);
	draw_square(0, 0, 30, img);
	draw_square(100, 50, 10, img);
	draw_square(200, 200, 35, img);
	draw_square(400, 400, 40, img);
}

int main()
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	screen.x_start = 0;
	screen.y_start = 0;
	screen.x_end = 500;
	screen.y_end = 500;
	// screen.scale = 1;
	// screen.offset = 0;
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
	mlx_loop_hook(mlx, &hook, img);
	mlx_scroll_hook(mlx, &zoom_hook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
