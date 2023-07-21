/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:03:08 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 20:10:30 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_and_exit(int argc, char **argv, t_data *var)
{
	int flag;
	
	flag = 0;
	if (argc > 2 && error_check(argc, argv, var) == 1)
	{
		flag = 1;
		if (var->fract.type == 0)
			ft_putstr_fd(RED"ERROR: Fractal name is missing or wrong\n", 2);
		ft_putstr_fd("ERROR: Rendering parameters are missing or wrong\n"RESET, 2);
	}
	if (flag == 1)
		ft_putchar_fd('\n', 1);
	ft_putstr_fd(GREEN"INSTRUCTIONS:\n"RESET, 1);
	ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1)", 1);
	ft_putstr_fd(GREEN" Mandelbrot\n"RESET, 1);
	ft_putstr_fd("\t- 2)", 1);
	ft_putstr_fd(GREEN" Julia\n"RESET, 1);
	ft_putstr_fd("\t- 3)", 1);
	ft_putstr_fd(GREEN" Multibrot\n\n"RESET, 1);
	ft_putstr_fd("Here's the basic prototype: ./fractol <fractal-name> || ./fractol <fractal-number>\n\nAdd parameters to amplify the rendering options for the fractal of your choice.\nHere's the prototype: ./fractol <fractal-name> <nb of iterations>|| ./fractol <fractal-number> <nb of iterations>\n\nFor the Julia set (2), you can also propose your own complex numbers as such:\n./fractol <fractal-name> <nb of iterations> <real_part> <imaginary part>\n\t\tor\n./fractol <fractal-number> <nb of iterations> <real_part> <imaginary part>\nHere's an example: ./fractol 2 40 .285 0\n", 1);
	exit(EXIT_FAILURE);
}
