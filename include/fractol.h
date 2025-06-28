/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:27:58 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/20 17:11:07 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# define HEIGHT 1200
# define WIDTH 1200
# define MAX_ITER 42

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*image_data;
	char	*type;
	int		bpp;
	int		size_line;
	int		endian;
	double	c_real;
	double	c_imag;
	int		x;
	int		y;
	double	zoom;
	double	o_x;
	double	o_y;
}				t_fractol;

//main.c//
void	init_my_mlx(t_fractol *fract);

// error.c //
void	help_msg(t_fractol *fract);
int		is_number(char *num);
double	convert_double(char *num);
void	input_check(int count, char **input, t_fractol *fract);

//key.c//
int		key_hook(int keycode, t_fractol *fract);
int		close_window(void *fract);
void	zoom(t_fractol *f, double zoom_factor, int m_x, int m_y);
int		mouse_hook(int mousecode, int x, int y, t_fractol *fract);

//fractals.c//
void	free_fractol(t_fractol *fract);
void	pixels(t_fractol *fract, char *type);
void	draw_mandelbrot(t_fractol *fract, double real, double imag);
void	draw_julia(t_fractol *fract, double real, double imag);
#endif
