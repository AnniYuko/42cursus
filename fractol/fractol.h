/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:52:50 by akroll            #+#    #+#             */
/*   Updated: 2022/09/22 11:22:47 by akroll           ###   ########.fr       */
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
#include <math.h>
#define WIDTH 600
#define HEIGHT 500
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define JULIA 5
#define MANDEL 6

typedef struct s_complex {
	double	re;
	double	im;
} t_complex;

typedef struct s_fractal {
	double		Im_min;
	double		Im_max;
	double		Re_min;
	double		Re_max;
	int			iter_max;
	bool		julia;
	t_complex	K;
	bool		mandel;
	t_complex	Z;
	t_complex	c;
} t_fractal;

typedef struct s_info {
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractal	fract;
} t_info;

// utils.c
int		initialize_mlx(t_info *i);
void	output_help_message(void);
void	write_info_keybindings(void);
int		get_color(unsigned n, unsigned max_iterations);
// fractals.c
void	set_starting_view(t_fractal *f, int option);
int		calc_fractal(t_fractal *f, int n);
void	calc_put_pixels(void *param);
int		select_julia_preset(t_fractal *fract, char option);
// input.c
int		input_parsing(t_fractal *fract, int argc, char *argv[]);
void	panning(t_fractal *f, int direction);
void	key_actions_functional(void *param);
void	key_actions_fractal(void *param);
void	zoom(double xdelta, double ydelta, void* param);
#endif
