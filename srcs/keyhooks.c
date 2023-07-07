/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/07 14:36:10 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_data *var)
{
	printf("Keycode is %d\n", keycode);
	if (keycode == ESC)
		ft_exit(var);
	else if (keycode == W || keycode == UP)
	{
		var->fractal.MaxIm -= 0.01;
		var->fractal.MinIm -= 0.01;
	}
	else if (keycode == S || keycode == DOWN)
	{
		var->fractal.MaxIm += 0.01;
		var->fractal.MinIm += 0.01;
	}
	else if (keycode == A || keycode == LEFT)
	{
		var->fractal.MinRe += 0.01; 
		var->fractal.MaxRe += 0.01;
	}
	else if (keycode == D || keycode == RIGHT)
	{
		var->fractal.MinRe -= 0.01; 
		var->fractal.MaxRe -= 0.01;
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
