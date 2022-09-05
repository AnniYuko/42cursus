/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:27:20 by akroll            #+#    #+#             */
/*   Updated: 2022/09/05 12:39:42 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#define WIDTH 400
#define HEIGHT 400
#define BLACK 0
#define BPP sizeof(int)

typedef struct screen_coord {
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	double scale;
	int x_offset;
	int y_offset;
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
	int zoom = 10 * screen.scale;
	(void)xdelta;
	(void)param;

	if (ydelta > 0)
	{
		puts("Zoom out");
		screen.x_offset -= zoom;
		screen.y_offset -= zoom;

		screen.x_start -= zoom;
		screen.x_end += zoom;
		screen.scale = (float)(screen.x_end - screen.x_start) / (float)(screen.y_end - screen.y_start);
		printf("%f\n", screen.scale);
		screen.y_start -= zoom;
		screen.y_end += zoom;
	}
	else
	{
		puts("Zoom in");
		screen.x_offset += zoom;
		screen.y_offset += zoom;

		screen.x_start += zoom;
		screen.x_end -= zoom;
		// scale (or pixel size?) = new width / old width
		screen.scale = (float)(screen.x_end - screen.x_start) / (float)(screen.y_end - screen.y_start);
		screen.scale = 1.0f/screen.scale;
		printf("%f\n", screen.scale);
		screen.y_start += zoom;
		screen.y_end -= zoom;
	}
}

bool	is_inside_square(int x_start, int y_start, double size, int x, int y)
{

	if (y >= y_start && y < y_start + size
		&& x >= x_start && x < x_start + size)
	{
		return true;
	}
	return false;
}

void	draw_hook(void *param)
{
	mlx_image_t	*img;
	int			x, y, world_space_x, world_space_y;

	img = param;
	memset(img->pixels, 255, img->width * img->height * BPP);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// check if this pixel should be coloured
			// => convert coordinate to world space
			world_space_x = x + screen.x_offset;
			world_space_y = y + screen.y_offset;

			if (is_inside_square(200, 200, 20 * screen.scale, world_space_x, world_space_y))
				mlx_put_pixel(img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int main()
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	screen.x_start = 0;
	screen.y_start = 0;
	screen.x_end = 500;
	screen.y_end = 500;
	screen.scale = 1;
	screen.x_offset = 0;
	screen.y_offset = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// image width and height
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// put image at position x, y
	mlx_image_to_window(mlx, img, 0, 0);
	// white background
	memset(img->pixels, 255, img->width * img->height * BPP);
	// add draw_hook function to main loop
	mlx_loop_hook(mlx, &detect_keys, mlx);
	mlx_loop_hook(mlx, &draw_hook, img);
	mlx_scroll_hook(mlx, &zoom_hook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
