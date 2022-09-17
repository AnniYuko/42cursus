/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/09/17 17:16:51 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define WIDTH 700
#define HEIGHT 600

void	initialize(t_fractal *f)
{
	// f->iter_max = 40;
	f->Re_min = -2.0;
	f->Re_max = 0.9;
	f->Im_min = -1.3;
	f->Im_max = 1.3;
}

void	detect_keys(void *param)
{
	mlx_t	*mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	//* -- segfault if -- *//

	// t_info	*i;
	// i = param;
	// if (mlx_is_key_down(&i->mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(&i->mlx);
	// if (mlx_is_key_down(i->mlx, MLX_KEY_KP_ADD))

}

void zoom_hook(double xdelta, double ydelta, void* param)
{
	t_fractal	*f;
	f = param;
	double	zoom = 0.05;
	double	part_Re;
	double	part_Im;
	(void)xdelta;

	part_Re = (f->Re_max - f->Re_min) * zoom;
	part_Im = (f->Im_max - f->Im_min) * zoom;
	// if ydelta > 0 zoom out; else zoom in
	if (ydelta > 0)
	{
		part_Im *= -1;
		part_Re *= -1;
	}
		f->Re_min = f->Re_min + part_Re;
		f->Re_max = f->Re_max - part_Re;
		f->Im_min = f->Im_min + part_Im;
		f->Im_max = f->Im_max - part_Im;
}

int	get_color(unsigned n, unsigned MaxIterations)
{
	int	blue_palette[] = {0x000000FF, 0x060D28FF, 0x0D1535FF, 0x141D40FF, \
		0x011B81FF, 0x001F9BFF, 0x0D30BCFF, 0x294DDBFF, 0x00A6D7FF, 0x30E7EDFF, \
		0x33F9ECFF, 0x86FAF2FF, 0xB5F9F4FF, 0xFFFFFFFF, 0x000000FF};
	return (blue_palette[(int)((float)n/(float)MaxIterations * 14)]);
}

// int	calculate_mandelbrot(int n, void *param)
// {
// 	double	Z_re2;
// 	double	Z_im2;
// 	t_fractal	*f;

// 	f = param;
// 	// optimization & important to save value for calculating Z
// 	Z_im2 = f->Z.im * f->Z.im;
// 	Z_re2 = f->Z.re * f->Z.re;
// 	/*  Check if Z is part of the set
// 		Z > 4 means it goes to infinity */
// 	if (Z_re2 + Z_im2 > 4)
// 		return (n);
// 	// calculate Z = Z * Z + c
// 	f->Z.im = (f->Z.re + f->Z.re) * f->Z.im + f->c.im;
// 	f->Z.re = Z_re2 - Z_im2 + f->c.re;
// 	n++;
// 	return (n);
// }

void	hook(void *param)
{
	unsigned	x;
	unsigned	y;
	double	Z_re2;
	double	Z_im2;
	unsigned	n;
	unsigned MaxIterations = 40;
	t_info		*i;
	t_fractal 	*f;

	i = param;
	f = &(i->fract);
	y = 0;
	while (y < HEIGHT)
	{
		f->c.im = f->Im_max - y * (f->Im_max-f->Im_min)/(float)HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			f->c.re = f->Re_min + x * (f->Re_max-f->Re_min)/(float)WIDTH;
			// Set Z = c
			f->Z.re = f->c.re;
			f->Z.im = f->c.im;
			n = 0;
			while (n < MaxIterations)
			{
				// optimization & important to save value for calculating Z
				Z_im2 = f->Z.im * f->Z.im;
				Z_re2 = f->Z.re * f->Z.re;
				/*  Check if Z is part of the set
					Z > 4 means it goes to infinity */
				if (Z_re2 + Z_im2 > 4)
					break ;
				// calculate Z = Z * Z + c
				f->Z.im = (f->Z.re + f->Z.re) * f->Z.im + f->c.im;
				f->Z.re = Z_re2 - Z_im2 + f->c.re;
				n++;

				// if (f->mandel == true)
				// 	n = calculate_mandelbrot(n, &f);
				// else if (f->julia == true)
					// calculate_julia();
			}
				mlx_put_pixel(i->img, x, y, get_color(n, MaxIterations));
				x++;
		}
		y++;
	}
}

int main(int argc, char *argv[])
{
	t_info	i;

	if (argc == 2 && strncmp("mandel", argv[1], 6) == 0)
		i.fract.mandel = true;
	else if (argc == 3 && strncmp("julia", argv[1], 5) == 0)
		i.fract.julia = true;

	else
	{
		write(1, "Please choose Mandelbrot or Julia set\nexample:\n", 47);
		write(1, "\t./fractol mandel\n\t./fractol julia [A-C]\n", 41);
		return (1);
	}
	i.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!i.mlx)
		return (1);
	initialize(&i.fract);
	// image width and height
	i.img = mlx_new_image(i.mlx, WIDTH, HEIGHT);
	// put image at position x, y
	mlx_image_to_window(i.mlx, i.img, 0, 0);
	// add hook function to main loop
	mlx_loop_hook(i.mlx, &detect_keys, i.mlx);
	mlx_scroll_hook(i.mlx, &zoom_hook, &i.fract);
	mlx_loop_hook(i.mlx, &hook, &i);
	mlx_loop(i.mlx);
	mlx_delete_image(i.mlx, i.img);
	mlx_terminate(i.mlx);
	return (0);
}
