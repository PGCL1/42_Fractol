/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 22:16:59 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_leaks(void)
{
	system("leaks -q fractol");
	/* atexit(ft_leaks); */
}

int error_check(int argc, char **argv, t_data *var)
{
	int i;
	int j;

	i = 3;
	j = 0;
	if (var->fract.type == 0)
		return (1);
	if (argc > 2)
	{
		while (argv[2][j] != '\0')
		{
			if (!(argv[2][j] >= '0' && argv[2][j] <= '9'))
				return (1);
			j++;
		}
		while (argv[i] != NULL)
		{
			if (ft_isnumber(argv[i]) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	var;
	
	atexit(ft_leaks);
	ft_memset(&var, 0, sizeof(var));
	init_all(&var, argc, argv);
	if (argc == 1)
		error_and_exit(argc, argv, &var);
	var.fract.type = fractal_name(*(argv + 1), &var);
	if (argc == 2 && error_check(argc, argv, &var) == 0)
	{
		if (var.fract.type == 2)
		{
			var.fract.c.real = 0.285;
			var.fract.c.imag = 0;
		}
		mlx_loop_hook(var.mlx.ptr, generate_fractal, &var);
	}
	else if (argc == 3 && !error_check(argc, argv, &var))
	{
		if (var.fract.type != 0)
		{
			var.fract.MaxIterations = ft_atoi(argv[2]);
			if (var.fract.MaxIterations < 10)
				exit(EXIT_FAILURE);
		}	
		if (var.fract.type == 2)
		{
			var.fract.c.real = 0.285;
			var.fract.c.imag = 0;
		}
		mlx_loop_hook(var.mlx.ptr, generate_fractal, &var);
	}
	else if (argc == 5 && !error_check(argc, argv, &var) && var.fract.type == 2)
	{
		var.fract.c.real = ft_atof(*(argv + 3));
		var.fract.c.imag = ft_atof(*(argv + 4));
		if (var.fract.c.imag > 1.0 || var.fract.c.imag < -1.0 || var.fract.c.real > 2.0 || var.fract.c.real < -2.0)
			error_and_exit(argc, argv, &var);
		mlx_loop_hook(var.mlx.ptr, generate_julia, &var);
	}
	else if (!*(argv + 1) || var.fract.type == 0 || error_check(argc, argv, &var) == 1)
		error_and_exit(argc, argv, &var);
	else
		error_and_exit(argc, argv, &var);
	//exit program through cross and ESC
	mlx_hook(var.mlx.win, 17, 0, ft_exit, &var);
	mlx_hook(var.mlx.win, 2, 0, key_hook, &var);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx.win, mouse_hook, &var);
	mlx_loop(var.mlx.ptr);
}
