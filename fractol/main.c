/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:23 by akroll            #+#    #+#             */
/*   Updated: 2022/09/21 18:12:36 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	write_info_keybindings();
	mlx_loop_hook(i.mlx, &key_actions_functional, &i);
	mlx_loop_hook(i.mlx, &key_actions_fractal, &i);
	mlx_loop_hook(i.mlx, &calc_put_pixels, &i);
	mlx_scroll_hook(i.mlx, &zoom, &i.fract);
	mlx_loop(i.mlx);
	mlx_delete_image(i.mlx, i.img);
	mlx_terminate(i.mlx);
	return (0);
}
