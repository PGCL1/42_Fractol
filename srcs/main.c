/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/04 18:27:09 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int main(int argc, char **argv)
{
	t_data var;
	t_complex num;

	//initialization of structure
	ft_memset(&var, 0, sizeof(var));
	
	//initializing API connection and window
	var.mlx.ptr = mlx_init();
	var.mlx.win = mlx_new_window(var.mlx.ptr, 1366, 768, "G's Fractol");
	
	//initializing img dimensions and address
	var.img.img = mlx_new_image(var.mlx.ptr, 1366, 768);
	var.img.addr = mlx_get_data_addr(var.img.img, &var.img.bits_per_pixel, &var.img.line_length, &var.img.endian);

	//parameters of fractal
	double MinRe, MaxRe, MinIm, MaxIm;
	
	MinRe = -2.0;
	MaxRe = 1.0;
	MinIm = -1.2;
	MaxIm = MinIm+(MaxRe-MinRe)*768/1366;
	
	//selection of the fractal
	if (argc >= 1)
	{
		if (!*(argv + 1) || fractal_name(*(argv+1)) == 0)
		{
			ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1) Mandelbrot\n\t- 2) Julia\nHere's the prototype: ./fractol <fractal-name> || ./fractol <fractal-number>\n", 1);
			exit(EXIT_FAILURE);
		}
		else if (*(argv + 1) && fractal_name(*(argv+1)) == 1)
			generate_mandelbrot();
/* 		else if (*(argv + 1) && fractal_name(*(argv+1)) == 2)
			generate_julia(); */
	}
	
	//exit program through cross and ESC
	mlx_hook(var.mlx.win, 17, 0, ft_exit, &var);
	mlx_hook(var.mlx.win, 2, 0, key_hook, &var);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx.win, mouse_hook, (void *)0);
	
	mlx_loop(var.mlx.ptr);
}
