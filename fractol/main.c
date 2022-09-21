/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/09/21 15:00:55 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_starting_view(t_fractal *f, int option)
{
	f->Im_min = -1.3;
	f->Im_max = 1.3;
	f->Re_min = -2.0;
	f->Re_max = 0.9;
	f->iter_max = 50;
	if (option == JULIA)
	{
		f->julia = true;
		f->mandel = false;
	}
	else if (option == MANDEL)
	{
		f->mandel = true;
		f->julia = false;
	}
}

int	get_color(unsigned n, unsigned max_iterations)
{
	int	blue_palette[] = {0x000000FF, 0x060D28FF, 0x0D1535FF, 0x141D40FF, \
		0x011B81FF, 0x001F9BFF, 0x0D30BCFF, 0x294DDBFF, 0x00A6D7FF, 0x30E7EDFF, \
		0x33F9ECFF, 0x86FAF2FF, 0xB5F9F4FF, 0xFFFFFFFF, 0x000000FF};
	return (blue_palette[(int)((float)n/(float)max_iterations * 14)]);
}

void	hook(void *param)
{
	unsigned		x;
	unsigned		y;
	double			Z_re2;
	double			Z_im2;
	unsigned int	n;
	t_info			*i;
	t_fractal 		*f;

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
			if (f->mandel == true)
			{
			while (n < f->iter_max)
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
			}
			}
			else if (f->julia == true)
			{
				while (n < f->iter_max)
				{
					Z_im2 = f->Z.im * f->Z.im;
					Z_re2 = f->Z.re * f->Z.re;
					if (Z_re2 + Z_im2 > 4)
						break ;
					// calculate Z = Z * Z + K
					f->Z.im = (f->Z.re + f->Z.re) * f->Z.im + f->K.im;
					f->Z.re = Z_re2 - Z_im2 + f->K.re;
					n++;
				}
			}
				mlx_put_pixel(i->img, x, y, get_color(n, f->iter_max));
				x++;
		}
		y++;
	}
}

void	output_help_message(void)
{
	write(1, "Please choose Mandelbrot or Julia set\nexample:\n", 47);
	write(1, "\t./fractol mandel\n\t./fractol julia [A-C]\n", 41);
}

int	select_julia_preset(t_fractal *fract, char option)
{
	if (option == 'A')
		{
			fract->K.re = 0.285;
			fract->K.im = 0.01;
		}
		else if (option == 'B')
		{
			fract->K.re = -0.4;
			fract->K.im = 0.6;
		}
		else if (option == 'C')
		{
			fract->K.re = -0.835;
			fract->K.im = -0.2321;
		}
		else
			return (1);
		return (0);
}

int	input_parsing(t_fractal *fract, int argc, char *argv[])
{
	if (argc == 2 && ft_strncmp("mandel", argv[1], 6) == 0)
		set_starting_view(fract, MANDEL);
	else if (argc == 3 && ft_strncmp("julia", argv[1], 5) == 0)
	{
		if (select_julia_preset(fract, *argv[2]) == 1)
			return 1;
		// if (atof())
		set_starting_view(fract, JULIA);
	}
	else
		return 1;
	return 0;
}

int	initialize_mlx(t_info *i)
{
	i->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!i->mlx)
		return (1);
	i->img = mlx_new_image(i->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(i->mlx, i->img, 0, 0);
	return (0);
}

int main(int argc, char *argv[])
{
	t_info	i;

	if (input_parsing(&i.fract, argc, argv) == 1)
	{
		output_help_message();
		return (1);
	}
	if (initialize_mlx(&i) == 1)
	{
		perror("initialize mlx");
		return (1);
	}
	// main loop
	mlx_loop_hook(i.mlx, &key_actions_functional, &i);
	mlx_loop_hook(i.mlx, &key_actions_fractal, &i);
	mlx_loop_hook(i.mlx, &hook, &i);
	mlx_scroll_hook(i.mlx, &zoom_hook, &i.fract);
	mlx_loop(i.mlx);
	mlx_delete_image(i.mlx, i.img);
	mlx_terminate(i.mlx);
	return (0);
}
