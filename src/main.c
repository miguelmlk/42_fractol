/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:28:24 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/24 11:26:02 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_my_mlx(t_fractol *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "MIMALEK FRACT-OL");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->image_data = mlx_get_data_addr(fract->img, &fract->bpp,
			&fract->size_line, &fract->endian);
	fract->zoom = 1.0;
	fract->o_x = 0.0;
	fract->o_y = 0.0;
}

int	main(int argc, char **argv)
{
	t_fractol	*fract;

	fract = malloc(sizeof(t_fractol));
	if (fract == NULL)
		return (0);
	if (argc != 2 && argc != 4)
		help_msg(fract);
	input_check(argc, argv, fract);
	init_my_mlx(fract);
	fract->type = argv[1];
	pixels(fract, argv[1]);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	mlx_hook(fract->win, 2, 1L << 1, key_hook, fract);
	mlx_hook(fract->win, 17, 0, close_window, fract);
	mlx_mouse_hook(fract->win, mouse_hook, fract);
	mlx_loop(fract->mlx);
	free_fractol(fract);
	return (0);
}
