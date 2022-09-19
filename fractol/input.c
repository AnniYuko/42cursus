/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:15:30 by akroll            #+#    #+#             */
/*   Updated: 2022/09/19 17:11:27 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	panning_vert(t_fractal *f, int direction)
{
	double	fraction;
	double	*max;
	double	*min;

	max = &f->Im_max;
	min = &f->Im_min;
	fraction = fabs((*max - *min) * 0.05);
	if (direction == DOWN)
		fraction *= -1;
	*max += fraction;
	*min += fraction;
}

void	detect_keys(void *param)
{
	t_info	*i = param;
	if (mlx_is_key_down(i->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(i->mlx);
	if (mlx_is_key_down(i->mlx, MLX_KEY_KP_ADD) && i->fract.iter_max < 450)
			i->fract.iter_max += 25;
	else if (mlx_is_key_down(i->mlx, MLX_KEY_KP_SUBTRACT) && i->fract.iter_max >= 75)
			i->fract.iter_max -= 25;
	if (mlx_is_key_down(i->mlx, MLX_KEY_J) && !(i->fract.julia))
	{
		i->fract.mandel = false;
		i->fract.julia = true;
	}
	else if (mlx_is_key_down(i->mlx, MLX_KEY_M) && !(i->fract.mandel))
	{
		i->fract.julia = false;
		i->fract.mandel = true;
	}
	if (mlx_is_key_down(i->mlx, MLX_KEY_UP))
		panning_vert(&i->fract, UP);
	else if (mlx_is_key_down(i->mlx, MLX_KEY_DOWN))
		panning_vert(&i->fract, DOWN);
}

void zoom_hook(double xdelta, double ydelta, void* param)
{
	t_fractal	*f;
	double	zoom = 0.05;
	double	part_Re;
	double	part_Im;
	(void)xdelta;

	f = param;
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
