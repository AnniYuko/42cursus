/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:15:30 by akroll            #+#    #+#             */
/*   Updated: 2022/09/21 14:55:54 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// move the view (according to arrow keys)
void	panning(t_fractal *f, int direction)
{
	double	fraction;
	double	*max;
	double	*min;

	if (direction == UP || direction == DOWN)
	{
	max = &f->Im_max;
	min = &f->Im_min;
	}
	else
	{
		max = &f->Re_max;
		min = &f->Re_min;
	}
	fraction = fabs((*max - *min) * 0.05);
	if (direction == DOWN || direction == LEFT)
		fraction *= -1;
	*max += fraction;
	*min += fraction;
}

void	key_actions_functional(void *param)
{
	t_info	*i;

	i = param;
	if (mlx_is_key_down(i->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(i->mlx);
	if (mlx_is_key_down(i->mlx, MLX_KEY_KP_ADD) && i->fract.iter_max < 450)
			i->fract.iter_max += 25;
	else if (mlx_is_key_down(i->mlx, MLX_KEY_KP_SUBTRACT) && i->fract.iter_max >= 75)
			i->fract.iter_max -= 25;
	if (mlx_is_key_down(i->mlx, MLX_KEY_UP))
		panning(&i->fract, UP);
	if (mlx_is_key_down(i->mlx, MLX_KEY_DOWN))
		panning(&i->fract, DOWN);
	if (mlx_is_key_down(i->mlx, MLX_KEY_LEFT))
		panning(&i->fract, LEFT);
	if (mlx_is_key_down(i->mlx, MLX_KEY_RIGHT))
		panning(&i->fract, RIGHT);
	else if (mlx_is_key_down(i->mlx, MLX_KEY_SPACE))
		set_starting_view(&i->fract, 0);
}

void	key_actions_fractal(void *param)
{
	t_info	*i;

	i = param;
	if (mlx_is_key_down(i->mlx, MLX_KEY_J) && !(i->fract.julia))
		set_starting_view(&i->fract, JULIA);
	else if (mlx_is_key_down(i->mlx, MLX_KEY_M) && !(i->fract.mandel))
		set_starting_view(&i->fract, MANDEL);
	if (mlx_is_key_down(i->mlx, MLX_KEY_A))
	{
		set_starting_view(&i->fract, JULIA);
		select_julia_preset(&i->fract, 'A');
	}
	if (mlx_is_key_down(i->mlx, MLX_KEY_B))
	{
		set_starting_view(&i->fract, JULIA);
		select_julia_preset(&i->fract, 'B');
	}
	if (mlx_is_key_down(i->mlx, MLX_KEY_C))
	{
		set_starting_view(&i->fract, JULIA);
		select_julia_preset(&i->fract, 'C');
	}
}

// if ydelta > 0 zoom out; else zoom in
void zoom_hook(double xdelta, double ydelta, void* param)
{
	t_fractal	*f;
	double	part_Re;
	double	part_Im;
	(void)xdelta;

	f = param;
	part_Re = (f->Re_max - f->Re_min) * 0.05;
	part_Im = (f->Im_max - f->Im_min) * 0.05;
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
