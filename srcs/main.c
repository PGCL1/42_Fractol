/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:27:51 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/28 17:34:22 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "G's Fractol");

	img.width_x = 1920;
	img.height_y = 1080;
	img.img = mlx_new_image(mlx, img.width_x, img.height_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int y = 0 ; y <img.height_y; y++) 
	{
		for (int x = 0; x < img.width_x; x+=100)
			my_mlx_pixel_put(&img, x, y, F_RED);
	}
	for (int y = 0 ; y <img.height_y; y+=100) 
	{
		for (int x = 0; x < img.width_x; x++)
			my_mlx_pixel_put(&img, x, y, F_RED);
	}
	my_mlx_pixel_put(&img, img.width_x/2, img.height_y/2, F_ORANGE);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_string_put(mlx, mlx_win, img.width_x/2, img.height_y/2, F_ORANGE, "Middle");
	mlx_key_hook(mlx_win, key_hook, (void *)0);
	mlx_mouse_hook(mlx_win, mouse_hook, (void *)0);
	
	mlx_loop(mlx);
}