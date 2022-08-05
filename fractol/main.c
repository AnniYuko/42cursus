/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/08/05 18:29:10 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define WIDTH 700
#define HEIGHT 600

void	initialize(t_mandelbrot *mb)
{
	// f->mb->iter_max = 40;
	mb->Re_min = -2.0;
	mb->Re_max = 1.0;
	mb->Im_min = -1.2;
	mb->Im_max = mb->Im_min+(mb->Re_max - mb->Re_min)*(float)HEIGHT/(float)WIDTH;
}

void	detect_keys(void *param)
{
	mlx_t	*mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void zoom_hook(double xdelta, double ydelta, void* param)
{
	t_mandelbrot	*mb;
	mb = param;
	double	zoomfactor = 2;
	double	delta_Re = mb->Re_max - mb->Re_min;
	double	delta_Im = mb->Im_max - mb->Im_min;

	(void)xdelta;
	if (ydelta > 0)
	{
		puts("Zoom out");
		mb->Re_min = mb->Re_min - (1.0/zoomfactor * delta_Re);
		mb->Re_max = mb->Re_max + (1.0/zoomfactor * delta_Re);
		mb->Im_min = mb->Im_min - (1.0/zoomfactor * delta_Im);
		mb->Im_max = mb->Im_max + (1.0/zoomfactor * delta_Im);
	}
	else if (ydelta < 0)
		puts("Zoom in");
		mb->Re_min = mb->Re_min - (zoomfactor * delta_Re);
		mb->Re_max = mb->Re_max + (zoomfactor * delta_Re);
		mb->Im_min = mb->Im_min - (zoomfactor * delta_Im);
		mb->Im_max = mb->Im_max + (zoomfactor * delta_Im);
}

int	get_color(unsigned n, unsigned MaxIterations)
{
	int	blue_palette[] = {0x000B37FF, 0x001051FF, 0x001466FF, 0x011B81FF, \
		0x001F9BFF, 0x001B87FF, 0x0058B3FF, 0x00A6D7FF, 0x30E7EDFF, \
		0x86FAF2FF, 0x000000FF};
	return (blue_palette[(int)((float)n/(float)MaxIterations * 10)]);
}

void	hook(void *param)
{
	unsigned	x;
	unsigned	y;
	t_complex	c;
	double		Z_re;
	double		Z_im;
	double		Z_re2;
	double		Z_im2;
	unsigned	n;
	unsigned MaxIterations = 40;
	t_info		*f;

	f = param;
	y = 0;
	while (y < HEIGHT)
	{
		c.im = f->mb->Im_max - y * (f->mb->Im_max-f->mb->Im_min)/(float)HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			c.re = f->mb->Re_min + x * (f->mb->Re_max-f->mb->Re_min)/(float)WIDTH; // c = Re_min + (x * PixelSize), Im_max - (y * PixelSize)

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
				mlx_put_pixel(f->img, x, y, get_color(n, MaxIterations));
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
	initialize(f.mb);
	// image width and height
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	// all pixel channels to 255 (white)
	memset(f.img->pixels, 255, f.img->width * f.img->height * sizeof(int));
	// put image at position x, y
	mlx_image_to_window(f.mlx, f.img, 0, 0);
	// add hook function to main loop
	mlx_loop_hook(f.mlx, &detect_keys, f.mlx);
	mlx_loop_hook(f.mlx, &hook, &f);
	mlx_scroll_hook(f.mlx, &zoom_hook, f.mb);
	mlx_loop(f.mlx);
	mlx_delete_image(f.mlx, f.img);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
