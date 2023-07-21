/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:03:08 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 22:36:08 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	error_print(int argc, char **argv, t_data *var)
{
	if (argc >= 1 && error_check(argc, argv, var) == 1)
	{
		if (var->fract.type == 0)
			ft_putstr_fd(RED"ERROR: Fractal name is missing/wrong\n", 2);
		ft_putstr_fd("ERROR: Rendering parameters are missing/wrong\n"RESET, 2);
	}
	if (var->fract.c.imag > 1 || var->fract.c.imag < -1
		|| var->fract.c.real > 2 || var->fract.c.real < -2)
		ft_putstr_fd(RED"ERROR: Complex numbers are above the limits\n", 2);
	if (var->fract.MaxIterations < 10)
		ft_putstr_fd(RED"ERROR: Number of iterations is below the limits\n", 2);
	return (1);
}

void	error_and_exit(int argc, char **argv, t_data *var)
{
	if (error_print(argc, argv, var) == 1)
		ft_putchar_fd('\n', 1);
	ft_putstr_fd(GREEN"INSTRUCTIONS:\n"RESET, 1);
	ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1)", 1);
	ft_putstr_fd(GREEN" Mandelbrot\n"RESET, 1);
	ft_putstr_fd("\t- 2)", 1);
	ft_putstr_fd(GREEN" Julia\n"RESET, 1);
	ft_putstr_fd("\t- 3)", 1);
	ft_putstr_fd(GREEN" Multibrot\n\n"RESET, 1);
	ft_putstr_fd(ORANGE"usage:"RESET, 1);
	ft_putstr_fd(" ./fractol <fractal-name> || <fractal-number>\n\n", 1);
	ft_putstr_fd("Add parameters as rendering options for a fractal.\n", 1);
	ft_putstr_fd("./fractol <fractal-name || fractal-num> <iterations>\n\n", 1);
	ft_putstr_fd("For the Julia set (2):\n", 1);
	ft_putstr_fd("./fractol <fractal> <iterations> <real> <imag>\n\t\t", 1);
	ft_putstr_fd("or\n./fractol <fractal> <iterations> <real> <imag>\n", 1);
	ft_putstr_fd("Here's an example: ./fractol 2 40 .285 0\n", 1);
	exit(EXIT_FAILURE);
}
