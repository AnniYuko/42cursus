/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:58:37 by akroll            #+#    #+#             */
/*   Updated: 2022/09/21 17:05:29 by akroll           ###   ########.fr       */
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

int	calc_fractal(t_fractal *f, int n)
{
	double	Z_re2;
	double	Z_im2;

	while (n < f->iter_max)
	{
		// optimization & important to save value for calculating Z
		Z_im2 = f->Z.im * f->Z.im;
		Z_re2 = f->Z.re * f->Z.re;
		/*  Check if Z is part of the set
			Z > 4 means it goes to infinity */
		if (Z_re2 + Z_im2 > 4)
			break ;
		if (f->mandel)
		{
			// calculate Z = Z * Z + c
			f->Z.im = (f->Z.re + f->Z.re) * f->Z.im + f->c.im;
			f->Z.re = Z_re2 - Z_im2 + f->c.re;
		}
		else if (f->julia)
		{
			// calculate Z = Z * Z + K
			f->Z.im = (f->Z.re + f->Z.re) * f->Z.im + f->K.im;
			f->Z.re = Z_re2 - Z_im2 + f->K.re;
		}
		n++;
	}
	return (n);
}

void	calc_put_pixels(void *param)
{
	t_info		*i;
	t_fractal 	*f;
	unsigned	x;
	unsigned	y;
	int			n;

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
			f->Z.re = f->c.re;
			f->Z.im = f->c.im;
			n = 0;
			n = calc_fractal(f, n);
			mlx_put_pixel(i->img, x, y, get_color(n, f->iter_max));
			x++;
		}
		y++;
	}
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
