/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/07/05 12:07:21 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define WIDTH 400
#define HEIGHT 400

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// image width and height 100
	img = mlx_new_image(mlx, 100, 100);
	// all pixel channels to 255 (white)
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	// image position x = 50, y = 50
	mlx_image_to_window(mlx, img, 50, 50);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
