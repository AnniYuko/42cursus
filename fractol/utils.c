/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:02:47 by akroll            #+#    #+#             */
/*   Updated: 2022/09/22 11:21:49 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	initialize_mlx(t_info *i)
{
	i->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!i->mlx)
		return (1);
	i->img = mlx_new_image(i->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(i->mlx, i->img, 0, 0);
	return (0);
}

void	output_help_message(void)
{
	write(1, "Please choose Mandelbrot or Julia set\nexample:\n", 47);
	write(1, "\t./fractol mandel\n\t./fractol julia [A-C]\n", 41);
}

void	write_info_keybindings(void)
{
	write(1, "Use:\nMouse wheel to zoom,\nArrow keys to move\n", 45);
	write(1, "Numpad + and - to adjust rendering\n", 35);
	write(1, "a, b, c keys to select a julia preset\n", 38);
	write(1, "m or j switch between julia and mandelbrot\n", 43);
	write(1, "space to reset the view\n", 24);
}

int	get_color(unsigned n, unsigned max_iterations)
{
	int	blue_palette[] = {0x000000FF, 0x060D28FF, 0x0D1535FF, 0x141D40FF, \
		0x011B81FF, 0x001F9BFF, 0x0D30BCFF, 0x294DDBFF, 0x00A6D7FF, 0x30E7EDFF, \
		0x33F9ECFF, 0x86FAF2FF, 0xB5F9F4FF, 0xFFFFFFFF, 0x000000FF};
	return (blue_palette[(int)((float)n/(float)max_iterations * 14)]);
}
