/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/19 20:38:12 by glacroix         ###   ########.fr       */
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
/* 	atexit(ft_leaks); */
}

static int error_check(char **argv, t_data *var)
{
	int i;

	i = 2;
	if (var->fractal.type == 0)
		return (1);
	while (argv[i] != NULL)
	{
		if (ft_isnumber(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	var;
	
	ft_memset(&var, 0, sizeof(var));
	init_all(&var);
	if (argc == 1)
	{
		ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1) Mandelbrot\n\t- 2) Julia\nHere's the prototype: ./fractol <fractal-name> || ./fractol <fractal-number>\n", 1);
		exit(EXIT_FAILURE);
	}
	var.fractal.type = fractal_name(*(argv + 1), &var);
	if (argc == 2 && !error_check(argv, &var))
		mlx_loop_hook(var.mlx.ptr, generate_fractal, &var);
	if (argc == 3 && !error_check(argv, &var))
	{
		if (var.fractal.type != 0)
			var.fractal.MaxIterations = ft_atoi(*(argv+2));
		mlx_loop_hook(var.mlx.ptr, generate_fractal, &var);
	}
	else if (argc == 5 && !error_check(argv, &var))
	{
		if (var.fractal.type == 2)
		{
			var.fractal.c.real = ft_atoi(*(argv + 3));
			var.fractal.c.imag = ft_atoi(*(argv + 4));
		}
		mlx_loop_hook(var.mlx.ptr, generate_julia, &var);
	}
	else if (!*(argv + 1) || var.fractal.type == 0 || error_check(argv, &var) == 1)
	{
		ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1) Mandelbrot\n\t- 2) Julia\nHere's the prototype: ./fractol <fractal-name> || ./fractol <fractal-number>\n", 1);
		exit(EXIT_FAILURE);
	}
	printf("here\n");
	
	//exit program through cross and ESC
	mlx_hook(var.mlx.win, 17, 0, ft_exit, &var);
	mlx_hook(var.mlx.win, 2, 0, key_hook, &var);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx.win, mouse_hook, &var);
	mlx_loop(var.mlx.ptr);
}
