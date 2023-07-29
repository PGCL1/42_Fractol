/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:03:08 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/29 17:45:46 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_leaks(void)
{
	system("leaks -q fractol");
	//atexit(ft_leaks);
}

int error_args(int argc, char **argv, t_data *var)
{
	int i;
	int j;

	i = 3;
	j = 0;
	if (isfractal(*(argv+1), var) == FALSE)
		return (TRUE);
	if (argc > 2)
	{
		while (argv[2][j] != '\0')
		{
			if (!(argv[2][j] >= '0' && argv[2][j] <= '9'))
				return (TRUE);
			j++;
		}
		while (argv[i] != NULL)
		{
			if (ft_isnumber(argv[i]) == FALSE)
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

void	instructions(void)
{
	ft_putstr_fd(GREEN"INSTRUCTIONS:\n"RESET, 1);
	ft_putstr_fd("Choose from the following fractals:\n\t- 1)", 1);
	ft_putstr_fd(GREEN" Mandelbrot\n"RESET, 1);
	ft_putstr_fd("\t- 2)", 1);
	ft_putstr_fd(GREEN" Julia\n"RESET, 1);
	ft_putstr_fd("\t- 3)", 1);
	ft_putstr_fd(GREEN" Multibrot\n\n"RESET, 1);
	ft_putstr_fd(ORANGE"usage:"RESET, 1);
	ft_putstr_fd(" ./fractol [fractal-name or number] [iterations]\n\n", 1);
	ft_putstr_fd("ONLY the Julia set can have 5 params:\n\n", 1);
	ft_putstr_fd(ORANGE"usage:"RESET, 1);
	ft_putstr_fd("./fractol [fractal-name or number] [iterations] [real] [imag]\n", 1);
	ft_putstr_fd("Here's an example: ./fractol 2 40 .285 0\n", 1);
	exit(EXIT_FAILURE);
}
