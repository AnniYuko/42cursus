/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:52:50 by akroll            #+#    #+#             */
/*   Updated: 2022/08/05 17:35:52 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H_
#define FRACTOL_H_
#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <math.h>

typedef struct s_complex {
	double	re;
	double	im;
	double	re2;
	double	im2;
} t_complex;

typedef struct s_mandelbrot {
	double	Im_min;
	double	Im_max;
	double	Re_min;
	double	Re_max;
	t_complex	Z;
	t_complex	c;
	unsigned int	iter_max;
} t_mandelbrot;

typedef struct s_info {
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_mandelbrot	*mb;
} t_info;

#endif
