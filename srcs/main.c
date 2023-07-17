/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/17 23:13:22 by glacroix         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_data	var;
	ft_memset(&var, 0, sizeof(var));
	init_all(&var);
	//selection of the fractal
	if (argc >= 1)
	{
		if (!*(argv + 1) || fractal_name(*(argv+1)) == 0)
		{
			ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1) Mandelbrot\n\t- 2) Julia\nHere's the prototype: ./fractol <fractal-name> || ./fractol <fractal-number>\n", 1);
			exit(EXIT_FAILURE);
		}
		else if (*(argv + 1) && fractal_name(*(argv+1)) == 1)
			mlx_loop_hook(var.mlx.ptr, generate_mandelbrot, &var);
		else if (*(argv + 1) && fractal_name(*(argv+1)) == 2)
			mlx_loop_hook(var.mlx.ptr, generate_julia, &var);
		else if (*(argv + 1) && fractal_name(*(argv+1)) == 3)
			mlx_loop_hook(var.mlx.ptr, generate_multibrot, &var);
	}
	//exit program through cross and ESC
	mlx_hook(var.mlx.win, 17, 0, ft_exit, &var);
	mlx_hook(var.mlx.win, 2, 0, key_hook, &var);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx.win, mouse_hook, &var);
	mlx_loop(var.mlx.ptr);
}
