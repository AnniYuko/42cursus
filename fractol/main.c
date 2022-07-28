/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/07/28 11:15:29 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define WIDTH 600
#define HEIGHT 500

mlx_image_t	*g_img;

int	get_color(unsigned n, unsigned MaxIterations)
{
	int	color;

	if (n == MaxIterations)
		color = 0x000000FF;
	else if (n > MaxIterations*9/10)
		color = 0xE6ECFFFF;
	else if (n > MaxIterations*8/10)
		color = 0x849DFFFF;
	else if (n > MaxIterations*7/10)
		color = 0x3D64FFFF;
	else if (n > MaxIterations*6/10)
		color = 0x5E7EFFFF;
	else if (n > MaxIterations*5/10)
		color = 0x0033FFFF;
	else if (n > MaxIterations*4/10)
		color = 0x0024B5FF;
	else if (n > MaxIterations*3/10)
		color = 0x0013C3FF;
	else if (n > MaxIterations*2/10)
		color = 0x0026BFFF;
	else if (n > MaxIterations*1/10)
		color = 0x001C8EFF;
	else if (n <= MaxIterations*1/10 && n > 1)
		color = 0x001465FF;
	else if (n == 1)
		color = 0x000C3CFF;
	else
		color = 0x000000FF;
	return (color);
}

void	hook(void *param)
{
	unsigned	x;
	unsigned	y;
	double		c_im;
	double		c_re;
	double		MinIm = -1.2;
	double		MinRe = -2.0;
	double		MaxRe = 1.0;
	double		MaxIm = MinIm+(MaxRe-MinRe)*g_img->height/g_img->width;
	double		Re_factor = (MaxRe-MinRe)/g_img->width;
	double		Im_factor = (MaxIm-MinIm)/g_img->height;
	double		Z_re;
	double		Z_im;
	double		Z_im2;
	unsigned	n;
	unsigned MaxIterations = 40;
	mlx_t	*mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	y = 0;
	while (y < g_img->height)
	{
		c_im = MaxIm - y * Im_factor;
		x = 0;
		while (x < g_img->width)
		{
			c_re = MinRe + x * Re_factor;

			// Set Z = c
			Z_re = c_re;
			Z_im = c_im;
			// Check if Z is part of the set
			// bool isInside = true;
			n = 0;
			while (n < MaxIterations)
			{
				// optimization & important to save value for calculating Z
				Z_im2 = Z_im*Z_im;
				if ((Z_re * Z_re + Z_im2) > 4)
					break ;
				// calculate Z = Z * Z + c
				Z_im = 2 * Z_re * Z_im + c_im;
				Z_re = (Z_re * Z_re) - Z_im2 + c_re;
				n++;
			}
				mlx_put_pixel(g_img, x, y, get_color(n, MaxIterations));
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
	// image width and height
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
