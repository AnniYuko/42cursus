/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/07/20 16:36:19 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define WIDTH 500
#define HEIGHT 500

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;
	int		x;
	int		y;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	y = 0;
	while (y < (int)g_img->height)
	{
		x = 0;
		while (x < (int)g_img->width)
		{
			mlx_put_pixel(g_img, x, y, (x*y));
			x++;
		}
		y++;
	}
}

int	main(void)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// image width and height 100
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// all pixel channels to 255 (white)
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	// put image at position x, y
	mlx_image_to_window(mlx, g_img, 0, 0);
	// add hook function to main loop
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
