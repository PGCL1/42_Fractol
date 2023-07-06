/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/06 17:49:31 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_data *var)
{
	printf("Keycode is %d\n", keycode);
	if (keycode == ESC)
	{
		ft_exit(var);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 126)
	{
		var->fractal.MaxIm -= 0.1;
		var->fractal.MinIm -= 0.1;
	}
	return (0);
}

int ft_exit(t_data *img)
{
	(void)img;
	ft_putstr_fd("Exited G's Fractol\n", 1);
	exit(EXIT_SUCCESS);
}

int mouse_hook(int button, int x, int y)
{
	printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	
	return (0);
}

/*
//add 0.01 to go the left, substract 0.01 to go to the right
var->fractal.MinRe = -(var->img.width_x/1000);
var->fractal.MaxRe = (var->img.width_x/1000);
//add 0.01 to go down, substract 0.01 to go up
var->fractal.MinIm = -(var->img.height_y/1000);
var->fractal.MaxIm = (var->img.height_y/1000);


W = 13
up = 126

S = 1
down = 125

A = 0
left = 123

D = 2
right = 124
*/