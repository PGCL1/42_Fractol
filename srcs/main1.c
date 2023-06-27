/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:56:08 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/27 17:26:34 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		ft_putstr_fd("Exited G's Fractol\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int mouse_hook(int button, int x, int y)
{
	printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	return (0);
}

int main()
{
	void	*mlx_ptr;
	t_win	window;
	
	ft_memset(&window, 0, sizeof(t_win));
	
	//INITIALIZING THE CONNECTION BETWEEN GRAPHICAL FRAMEWORK AND SOFTWARE
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	window.size_x = 1920;//width
	window.size_y = 1080;//height
	
	//INITIALIZING THE WINDOWN WHERE THE FRACTAL WILL BE DRAWN
	window.ptr = mlx_new_window(mlx_ptr, window.size_y, window.size_x, "G's Fractol");
	
	//DRAWING WITHIN THE WINDOWN
	for (int y = 250; y < (window.size_y/4)*3; y++)
	{
		for (int x = 250; x < (window.size_x/4)*3; x++)
		{
			//mlx_pixel_put(mlx_ptr, window.ptr, x/2 + 40, y/2 + 40, F_PURPLE);
			mlx_pixel_put(mlx_ptr, window.ptr, x, y, F_RED);
			/* mlx_put_image_to_window(mlx_ptr, window.ptr, im) */
			//mlx_pixel_put(mlx_ptr, window.ptr, x, y, 230);
		}
	}
	mlx_key_hook(window.ptr, key_hook, (void *)0);
	mlx_mouse_hook(window.ptr, mouse_hook, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}