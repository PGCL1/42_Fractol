/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/05 19:15:23 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	t_data var;

	//initialization of structure
	ft_memset(&var, 0, sizeof(var));
	
	//initializing API connection and window
	var.mlx.ptr = mlx_init();
	var.mlx.height_y = 1080;
	var.mlx.width_x = 1920;
	var.img.height_y = var.mlx.height_y;
	//we do var.mlx.width_x - var.mlx.width_x/3 to have it centered later will find better solution
	var.img.width_x = var.mlx.width_x;
	var.mlx.win = mlx_new_window(var.mlx.ptr, var.mlx.width_x, var.mlx.height_y, "G's Fractol");
	
	//initializing img dimensions and address
	var.img.img = mlx_new_image(var.mlx.ptr, var.img.width_x, var.img.height_y);
	printf("pointer is %p\n", var.img.img);
	var.img.addr = mlx_get_data_addr(var.img.img, &var.img.bits_per_pixel, &var.img.line_length, &var.img.endian);

	//selection of the fractal
	if (argc >= 1)
	{
		if (!*(argv + 1) || fractal_name(*(argv+1)) == 0)
		{
			ft_putstr_fd("You need to precise the fractal you wish to see\n\t- 1) Mandelbrot\n\t- 2) Julia\nHere's the prototype: ./fractol <fractal-name> || ./fractol <fractal-number>\n", 1);
			exit(EXIT_FAILURE);
		}
		else if (*(argv + 1) && fractal_name(*(argv+1)) == 1)
			generate_mandelbrot(&var);
		//else if (*(argv + 1) && fractal_name(*(argv+1)) == 2)
		//	generate_julia();
	}
	
	//exit program through cross and ESC
	mlx_hook(var.mlx.win, 17, 0, ft_exit, &var);
	mlx_hook(var.mlx.win, 2, 0, key_hook, &var);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx.win, mouse_hook, (void *)0);
	
	mlx_loop(var.mlx.ptr);
}
