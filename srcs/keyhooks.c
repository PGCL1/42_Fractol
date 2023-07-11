/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/11 15:28:19 by glacroix         ###   ########.fr       */
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
		var->fractal.MaxIm -= var->fractal.MaxIm * 0.01;
		var->fractal.MinIm -= var->fractal.MaxIm * 0.01;
	}
	else if (keycode == S || keycode == DOWN)
	{
		var->fractal.MaxIm += var->fractal.MaxIm * 0.01;
		var->fractal.MinIm += var->fractal.MinIm * 0.01;
	}
	else if (keycode == A || keycode == LEFT)
	{
		var->fractal.MinRe -= var->fractal.MinRe * 0.01; 
		var->fractal.MaxRe -= var->fractal.MaxRe * 0.01;
	}
	else if (keycode == D || keycode == RIGHT)
	{
		var->fractal.MinRe += var->fractal.MinRe * 0.01; 
		var->fractal.MaxRe += var->fractal.MaxRe * 0.01;
	}
	else if (keycode == PLUS)
	{
		printf("Iterations are %d\n", var->fractal.MaxIterations);
		var->fractal.MaxIterations += 10;
		if (var->fractal.MaxIterations == 310)
			var->fractal.MaxIterations = 10;
	}
	else if (keycode == MINUS)
	{
		printf("Iterations are %d\n", var->fractal.MaxIterations);
		var->fractal.MaxIterations -= 10;
		if (var->fractal.MaxIterations == 0)
			var->fractal.MaxIterations = 10;
	}
	return (0);
}

int ft_exit(t_data *img)
{
	(void)img;
	ft_putstr_fd("Exited G's Fractol\n", 1);
	exit(EXIT_SUCCESS);
}

int mouse_hook(int button, int x, int y, t_data *var)
{
	//find values to keep center
	printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	if (button == 4)
	{
		printf("zooming in\n");
		var->fractal.Re_factor -= var->fractal.Re_factor * 0.05;
		var->fractal.Im_factor -= var->fractal.Im_factor * 0.05;
		printf("Re_factor is %f | Im_factor is %f\n", var->fractal.Re_factor, var->fractal.Im_factor);
	}
	else if (button == 5)
	{
		printf("zooming out\n");
		var->fractal.Re_factor += var->fractal.Re_factor * 0.05;
		var->fractal.Im_factor += var->fractal.Im_factor * 0.05;
		printf("Re_factor is %f | Im_factor is %f\n", var->fractal.Re_factor, var->fractal.Im_factor);
	}
/* 	else if (button == 1)
	{
		
	} */
	return (0);
}
