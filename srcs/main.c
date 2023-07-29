/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/29 17:50:12 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	error_param2(char **argv, t_data *var)
{
	if (isfractal(*(argv + 1), var) == FALSE)
	{
		ft_putstr_fd(RED"ERROR: Fractal name is wrong\n"RESET, 2);
		return (1);
	}
	return (0);
}

static int	error_param3(char **argv, t_data *var)
{
	error_param2(argv, var);
	if (var->fract.MaxIterations < 10)
	{
		ft_putstr_fd(RED"ERROR: Rendering params are wrong (min iterations are >= 10)\n", 2);
		return (1);
	}
	return (0);
}

static int	error_param5(char **argv, t_data *var)
{
	error_param2(argv, var);
	error_param3(argv, var);
	if (var->fract.type != 2)
	{
		ft_putstr_fd(RED"ERROR: Only the Julia set can hold 5 params\n"RESET, 2);
		return (1);
	}
	if (var->fract.c.imag > 1 || var->fract.c.imag < -1 || var->fract.c.real > 2 || var->fract.c.real < -2)
	{
		ft_putstr_fd(RED"ERROR: Complex numbers are above their limits\n\tA complex number's real part is between -2 <= x <= 2\n\tA complex number's imaginary part is between -1 <= y <= 1\n"RESET, 2);
		return (1);
	}
	return (0);
}

static void	create_fractal(int argc, char **argv, t_data *var)
{
	if (argc == 2)
	{
		if (error_param2(argv, var) == TRUE)
			exit(EXIT_FAILURE);
		if (var->fract.type == 2 && argc == 2)
			julia_setup(argc, argv, var);
		mlx_loop_hook(var->mlx.ptr, generate_fractal, var);
	}
	else if (argc == 3)
	{
		var->fract.MaxIterations = ft_atoi(argv[2]);
		if (error_param3(argv, var) == TRUE)
			exit(EXIT_FAILURE);
		else if (var->fract.type == 2)
			julia_setup(argc, argv, var);
		mlx_loop_hook(var->mlx.ptr, generate_fractal, var);
	}
	else if (argc == 5)
	{
		julia_setup(argc, argv, var);
		if (error_param5(argv, var) == TRUE)
			exit(EXIT_FAILURE);
		mlx_loop_hook(var->mlx.ptr, generate_julia, var);
	}
}

int	main(int argc, char **argv)
{
	t_data	var;

	ft_memset(&var, 0, sizeof(var));
	init_all(&var);
	if (argc == 2 || argc == 3 || argc == 5)
		create_fractal(argc, argv, &var);
	else
	{
		if (argc == 4)
			ft_putstr_fd(RED"ERROR: program doesn't work with 4 params\n"RESET, 2);
		else if (argc >= 5)
			ft_putstr_fd(RED"ERRPR: program doesn't accept more than 5 params\n"RESET, 2);
		instructions();
		exit(EXIT_FAILURE);
	}
	mlx_loops(&var);
	return (0);
}
