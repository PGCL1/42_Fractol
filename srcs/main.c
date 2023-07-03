/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:27:51 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/03 18:34:15 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}


//drawing the fractal shape for Julia set
void	drawing_image(t_var *var, t_data *img)
{
	img->width_x = 1920;
	img->height_y = 1080;
	img->img = mlx_new_image(var->mlx, img->width_x, img->height_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	
	for (int x = 0; x < img->width_x; x++)
			my_mlx_pixel_put(img, x, img->height_y/2, F_RED);
	for (int y = 0; y < img->height_y; y++)
		my_mlx_pixel_put(img, img->width_x/2, y, F_RED);
	my_mlx_pixel_put(img, img->width_x, img->height_y/2, F_ORANGE);
	mlx_put_image_to_window(var->mlx, var->mlx_win, img->img, 0, 0);
	mlx_string_put(var->mlx, var->mlx_win, img->width_x/2, img->height_y/2, F_ORANGE, "0,0");
}


int main(int argc, char **argv)
{
	t_var	var;
	t_data	img;
	
 	float left, top, xside, yside;
    
	left = -1.75;
    top = -0.25;
    xside = 0.25;
    yside = 0.45;

	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, 1920, 1080, "G's Fractol");

	if (argc >= 1)
	{
 		if (*(argv+1) && ft_strncmp("Julia", *(argv + 1), 6))
			draw_julia_set(&var, &img);
		//create function for selection of arguments (.. see progress)
		else if (*(argv+1) && ft_strncmp("Mandelbrot", *(argv + 1), 11))
			draw_mandelbrot_set(&var, &img, left, top, xside, yside);
		else
		{
			ft_putstr_fd("You need to precise which fractal you wish to see:\n\t- Mandelbrot\n\t- Julia\n", 1);
			exit(EXIT_FAILURE);
		}
	} 
	//drawing the two axis
	drawing_image(&var, &img);


 	//ESC hook
	mlx_hook(var.mlx_win, 2, 0, key_hook, &img);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx_win, mouse_hook, (void *)0);
	//exit program through the cross
	mlx_hook(var.mlx_win, 17, 0, ft_exit, &img);
	
	mlx_loop(var.mlx);
}

	