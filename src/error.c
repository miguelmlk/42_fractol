/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:41:46 by mimalek           #+#    #+#             */
/*   Updated: 2024/12/13 12:24:56 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	help_msg(t_fractol *fract)
{
	ft_printf("Usage ./fractol <fractal> [options]\n");
	ft_printf("Fractals:\n");
	ft_printf("M	-	Mandelbrot set (no options available)\n");
	ft_printf("J	-	Julia Set (use option available)\n");
	ft_printf("Options for Julia set:\n");
	ft_printf("<real> <imag> Specify the real and imaginary parts of c\n");
	free(fract);
	exit (1);
}

int	is_number(char *num)
{
	int	digit;
	int	dot;

	digit = 0;
	dot = 0;
	if (!num || *num == '\0')
		return (0);
	while (*num == ' ')
		num++;
	if (*num == '+' || *num == '-')
		num++;
	while (*num && ((*num == '.' && !dot) || ft_isdigit((unsigned char)*num)))
	{
		if (*num == '.')
			dot = 1;
		else
			digit = 1;
		num++;
	}
	return (*num == '\0' && digit);
}

double	convert_double(char *num)
{
	double	result;
	double	decimal_place;
	int		sign;

	result = 0.0;
	decimal_place = 1.0;
	sign = 1;
	if (!num || *num == '\0')
		return (0.0);
	while (*num == ' ')
		num++;
	if (*num == '+' || *num == '-')
		sign = (*num++ == '-') * (-2) + 1;
	while (*num && ft_isdigit((unsigned char)*num))
		result = result * 10 + (*num++ - '0');
	if (*num == '.')
	{
		num++;
		while (*num && ft_isdigit((unsigned char)*num))
		{
			decimal_place *= 10;
			result = result + (*num++ - '0') / (decimal_place);
		}
	}
	return (result * sign);
}

void	input_check(int count, char **input, t_fractol *fract)
{
	if (ft_strncmp(input[1], "M", 1) == 0)
	{
		if (count != 2)
			help_msg(fract);
	}
	else if (ft_strncmp(input[1], "J", 1) == 0)
	{
		if (count != 4 || !is_number(input[2]) || !is_number(input[3]))
			help_msg(fract);
		else
		{
			fract->c_real = convert_double(input[2]);
			fract->c_imag = convert_double(input[3]);
		}
	}
	else
		help_msg(fract);
}
