/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/09/17 14:18:12 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define WIDTH 700
#define HEIGHT 600

void	initialize(t_mandelbrot *mb)
{
	// f->mb->iter_max = 40;
	mb->Re_min = -2.0;
	mb->Re_max = 0.9;
	mb->Im_min = -1.3;
	mb->Im_max = 1.3;
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
	double	zoom = 0.05;
	double	part_Re;
	double	part_Im;
	(void)xdelta;

	part_Re = (mb->Re_max - mb->Re_min) * zoom;
	part_Im = (mb->Im_max - mb->Im_min) * zoom;
	// if ydelta > 0 zoom out; else zoom in
	if (ydelta > 0)
	{
		part_Im *= -1;
		part_Re *= -1;
	}
		mb->Re_min = mb->Re_min + part_Re;
		mb->Re_max = mb->Re_max - part_Re;
		mb->Im_min = mb->Im_min + part_Im;
		mb->Im_max = mb->Im_max - part_Im;
}

int	get_color(unsigned n, unsigned MaxIterations)
{
	int	blue_palette[] = {0x000000FF, 0x060D28FF, 0x0D1535FF, 0x141D40FF, \
		0x011B81FF, 0x001F9BFF, 0x0D30BCFF, 0x294DDBFF, 0x00A6D7FF, 0x30E7EDFF, \
		0x33F9ECFF, 0x86FAF2FF, 0xB5F9F4FF, 0xFFFFFFFF, 0x000000FF};
	return (blue_palette[(int)((float)n/(float)MaxIterations * 14)]);
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
			c.re = f->mb->Re_min + x * (f->mb->Re_max-f->mb->Re_min)/(float)WIDTH;
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

int main()
{
	t_info	f;

	f.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!f.mlx)
		exit(EXIT_FAILURE);
	initialize(f.mb);
	// image width and height
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	// put image at position x, y
	mlx_image_to_window(f.mlx, f.img, 0, 0);
	// add hook function to main loop
	mlx_loop_hook(f.mlx, &detect_keys, f.mlx);
	mlx_scroll_hook(f.mlx, &zoom_hook, f.mb);
	mlx_loop_hook(f.mlx, &hook, &f);
	mlx_loop(f.mlx);
	mlx_delete_image(f.mlx, f.img);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
