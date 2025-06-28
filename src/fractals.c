/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:14:34 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/20 16:57:11 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	free_fractol(t_fractol *fract)
{
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	free(fract);
	exit(EXIT_SUCCESS);
}

void	image_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = f->image_data + (y * f->size_line + x * (f->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	pixels(t_fractol *f, char *type)
{
	double	real;
	double	imag;

	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			real = (f->x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->o_x;
			imag = (f->y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->o_y;
			if (ft_strncmp(type, "M", 1) == 0)
				draw_mandelbrot(f, real, imag);
			else if (ft_strncmp(type, "J", 1) == 0)
				draw_julia(f, real, imag);
			f->y++;
		}
		f->x++;
	}
}

void	draw_mandelbrot(t_fractol *fract, double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		iter;
	int		color;

	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (z_real * z_real + z_imag * z_imag <= 4.0 && iter < MAX_ITER)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2.0 * z_real * z_imag + imag;
		z_real = temp;
		iter++;
	}
	if (iter == MAX_ITER)
		color = 0x000000;
	else
		color = ((int)(sin(iter * 0.1) * 127 + 128) << 16) | ((int)
				(sin(iter * 0.2) * 127 + 128) << 8) |((int)
				(sin(iter * 0.3) * 127 + 128));
	image_pixel_put(fract, fract->x, fract->y, color);
}

void	draw_julia(t_fractol *fract, double real, double imag)
{
	double	temp;
	int		iter;
	int		color;

	iter = 0;
	while (real * real + imag * imag <= 4.0 && iter < MAX_ITER)
	{
		temp = real * real - imag * imag + fract->c_real;
		imag = 2.0 * real * imag + fract->c_imag;
		real = temp;
		iter++;
	}
	if (iter == MAX_ITER)
		color = 0x000000;
	else
		color = ((int)(sin(iter * 0.1) * 127 + 128) << 16) | ((int)
				(sin(iter * 0.2) * 127 + 128) << 8) |((int)
				(sin(iter * 0.3) * 127 + 128));
	image_pixel_put(fract, fract->x, fract->y, color);
}
