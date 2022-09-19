/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:52:50 by akroll            #+#    #+#             */
/*   Updated: 2022/09/19 16:17:02 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H_
#define FRACTOL_H_
#include "MLX42.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
// #include <math.h>
#define WIDTH 700
#define HEIGHT 600

typedef struct s_complex {
	double	re;
	double	im;
} t_complex;

typedef struct s_fractal {
	double			Im_min;
	double			Im_max;
	double			Re_min;
	double			Re_max;
	unsigned int	iter_max;
	bool			julia;
	t_complex		K;
	bool			mandel;
	t_complex		Z;
	t_complex		c;
} t_fractal;

typedef struct s_info {
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractal	fract;
} t_info;

#endif
