/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:15:07 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/29 16:34:22 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_data *img)
{
	if (keycode == ESC)
	{
		ft_exit(img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int ft_exit(t_data *img)
{
	(void)img;
	ft_putstr_fd("Exited G's Fractol\n", 1);
	exit(EXIT_SUCCESS);
}

int zoom_in(int mouse, int x, int y, t_data *img, void **mlx)
{
	if (mouse == 4)
		resize_window(img, &x, &y, &(*mlx));
	return(0);
}

void resize_window(t_data *img, int *x, int *y, void **mlx)
{
	img->width_x -= *x;
	img->height_y -= *y;
	mlx_new_image(mlx, img->width_x, img->height_y);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

int mouse_hook(int button, int x, int y)
{
	printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	if (x == 0 && y == 0 && button == 1)
		exit(EXIT_SUCCESS);
	return (0);
}

