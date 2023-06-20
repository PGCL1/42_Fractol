/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:56:08 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/20 18:12:43 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int a;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 700, "test");
	for (int x = 0; x < 700; x++)
	{
			mlx_pixel_put(mlx_ptr, win_ptr, x, 700, 120);
	}
	mlx_loop(mlx_ptr);
	return (0);
}