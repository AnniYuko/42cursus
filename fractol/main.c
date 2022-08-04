/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/08/04 14:03:35 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define WIDTH 700
#define HEIGHT 600

int	get_color(unsigned n, unsigned MaxIterations)
{
	int	blue_palette[] = {0x000B37FF, 0x001051FF, 0x001466FF, 0x011B81FF, \
		0x001F9BFF, 0x001B87FF, 0x0058B3FF, 0x00A6D7FF, 0x30E7EDFF, \
		0x86FAF2FF, 0x000000FF};
	return (blue_palette[(int)((float)n/(float)MaxIterations * 10)]);
}

void	detect_keys(void *param)
{
	mlx_t	*mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	hook(void *param)
{
	unsigned	x;
	unsigned	y;
	t_complex	c;
	double		MinIm = -1.2;
	double		MinRe = -2.0;
	double		MaxRe = 1.0;
	double		MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
	double		Re_factor = (MaxRe-MinRe)/WIDTH;
	double		Im_factor = (MaxIm-MinIm)/HEIGHT;
	double		Z_re;
	double		Z_im;
	double		Z_re2;
	double		Z_im2;
	unsigned	n;
	unsigned MaxIterations = 40;
	mlx_image_t	*img = param;

	y = 0;
	while (y < HEIGHT)
	{
		c.im = MaxIm - y * Im_factor;
		x = 0;
		while (x < WIDTH)
		{
			c.re = MinRe + x * Re_factor;

			// Set Z = c
			Z_re = c.re;
			Z_im = c.im;
			n = 0;
			while (n < MaxIterations)
			{
				// optimization & important to save value for calculating Z
				Z_im2 = Z_im * Z_im;
				Z_re2 = Z_re * Z_re;
				/*  Check if Z is part of the set
					Z > 4 means it goes to infinity */
				if (Z_re2 + Z_im2 > 4)
					break ;
				// calculate Z = Z * Z + c
				Z_im = (Z_re + Z_re) * Z_im + c.im;
				Z_re = Z_re2 - Z_im2 + c.re;
				n++;
			}
				mlx_put_pixel(img, x, y, get_color(n, MaxIterations));
				x++;
		}
		y++;
	}
}


int	main(void)
{
	t_info	f;

	f.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!f.mlx)
		exit(EXIT_FAILURE);
	// image width and height
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	// all pixel channels to 255 (white)
	memset(f.img->pixels, 255, f.img->width * f.img->height * sizeof(int));
	// put image at position x, y
	mlx_image_to_window(f.mlx, f.img, 0, 0);
	// add hook function to main loop
	mlx_loop_hook(f.mlx, &detect_keys, f.mlx);
	mlx_loop_hook(f.mlx, &hook, f.img);
	mlx_loop(f.mlx);
	mlx_delete_image(f.mlx, f.img);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
