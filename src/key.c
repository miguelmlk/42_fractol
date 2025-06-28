/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:00:25 by mimalek           #+#    #+#             */
/*   Updated: 2024/12/13 12:47:46 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_fractol *fract)
{
	if (keycode == 53)
	{
		ft_printf("Close the program..\n");
		free_fractol(fract);
	}
	exit(EXIT_SUCCESS);
}

int	close_window(void *fract)
{
	ft_printf("Close the programm..\n");
	free_fractol(fract);
	exit(EXIT_SUCCESS);
}

void	zoom(t_fractol *f, double zoom_factor, int m_x, int m_y)
{
	double	m_real;
	double	m_imag;

	m_real = (m_x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->o_x;
	m_imag = (m_y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->o_y;
	f->zoom *= zoom_factor;
	f->o_x = m_real - (m_real - f->o_x) / zoom_factor;
	f->o_y = m_imag - (m_imag - f->o_y) / zoom_factor;
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *fract)
{
	if (mousecode == 4)
		zoom(fract, 1.1, x, y);
	else if (mousecode == 5)
		zoom(fract, 0.9, x, y);
	pixels(fract, fract->type);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	return (0);
}
