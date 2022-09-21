/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:27:20 by akroll            #+#    #+#             */
/*   Updated: 2022/09/21 17:21:01 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#define BLACK 0
#define BPP sizeof(int)

typedef struct screen_coord {
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
}

void zoom_hook(double xdelta, double ydelta, void* param)
{
	(void)xdelta;
	(void)param;

	if (ydelta > 0)
	{
		puts("Zoom in");
		screen.scale *= 1.05f;
		// screen.x_offset += ;
		// screen.y_offset += ;
	}
	else
	{
		puts("Zoom out");
		screen.scale *= 0.95f;
		// screen.x_offset -= ;
		// screen.y_offset -= ;
	}
}

bool	is_inside_square(int x_start, int y_start, double size, int x, int y)
{
	return (y >= y_start && y < y_start + size
		&& x >= x_start && x < x_start + size);
}

void	draw_hook(void *param)
{
	mlx_image_t	*img;
	int			x, y, world_space_x, world_space_y;

	img = param;
	memset(img->pixels, 255, img->width * img->height * BPP);
	// screen space
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// screen to world
			world_space_x = (float)x / screen.scale + screen.x_offset;
			world_space_y = (float)y / screen.scale + screen.y_offset;

			if (is_inside_square(0, 0, 20, world_space_x, world_space_y))
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

	screen.scale = 1.0f;
	screen.x_offset = 0;
	screen.y_offset = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// put image at position x, y
	mlx_image_to_window(mlx, img, 0, 0);
	// loop hook means add func to main loop
	mlx_loop_hook(mlx, &detect_keys, mlx);
	mlx_loop_hook(mlx, &draw_hook, img);
	mlx_scroll_hook(mlx, &zoom_hook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
