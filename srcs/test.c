/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:59:20 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/13 15:45:18 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int ft_exit(t_data *img)
{
	(void)img;
	ft_putstr_fd("Exited G's Fractol\n", 1);
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	t_data test;
	ft_memset(&test, 0, sizeof(test));
	//initializing connection with API and window
	test.mlx.ptr = mlx_init();
	test.mlx.height_y = 768;
	test.mlx.width_x = 1366;
	test.mlx.win = mlx_new_window(test.mlx.ptr, test.mlx.width_x, test.mlx.height_y, "Test");
	
	//initializing img dimensions and address
	test.img.height_y = test.mlx.height_y;
	test.img.width_x = test.mlx.width_x;
	test.img.img = mlx_new_image(test.mlx.ptr, test.img.width_x, test.img.width_x);
	test.img.addr = mlx_get_data_addr(test.img.img, &test.img.bits_per_pixel, &test.img.line_length, &test.img.endian);

	//testing color shift in image
	for (int y = 0; y < test.img.height_y - 1; ++y)
	{
		for (int x = 0; x < test.img.width_x - 1; ++x)
		{
			my_mlx_pixel_put(&test.img, x, y, F_RED>>3);
		}
	}
	mlx_put_image_to_window(test.mlx.ptr, test.mlx.win, test.img.img, 0, 0);
	mlx_hook(test.mlx.win, 17, 0, ft_exit, &test);
	//loop for continuous rendering
	mlx_loop(test.mlx.ptr);
	return (0);
}