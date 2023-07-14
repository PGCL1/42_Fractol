/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/14 18:44:42 by glacroix         ###   ########.fr       */
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
		var->fractal.MinIm -= (var->fractal.MinIm * (var->fractal.Im_factor * 20));
		var->fractal.MaxIm -= (var->fractal.MaxIm * (var->fractal.Im_factor * 20));
	}
	else if (keycode == S || keycode == DOWN)
	{
		var->fractal.MaxIm += (var->fractal.MaxIm * (var->fractal.Im_factor * 20));
		var->fractal.MinIm += (var->fractal.MinIm * (var->fractal.Im_factor * 20));
	}
	else if (keycode == A || keycode == LEFT)
	{
		var->fractal.MinRe -= (var->fractal.MinRe * (8 * var->fractal.Re_factor)); 
		var->fractal.MaxRe -= (var->fractal.MaxRe * (8 * var->fractal.Re_factor));
	}
	else if (keycode == D || keycode == RIGHT)
	{
		var->fractal.MinRe += (var->fractal.MinRe * (8 * var->fractal.Re_factor));
		var->fractal.MaxRe += (var->fractal.MaxRe * (8 * var->fractal.Re_factor));
	}
	else if (keycode == PLUS)
	{
//		printf("Iterations are %d\n", var->fractal.MaxIterations);
		var->fractal.MaxIterations += 10;
		if (var->fractal.MaxIterations == 310)
			var->fractal.MaxIterations = 10;
	}
	else if (keycode == MINUS)
	{
//		printf("Iterations are %d\n", var->fractal.MaxIterations);
		var->fractal.MaxIterations -= 10;
		if (var->fractal.MaxIterations == 0)
			var->fractal.MaxIterations = 10;
	}
	else if (keycode == C)
	{
		int array[5] = {F_RED, F_BLUE, F_ORANGE, F_PURPLE, F_GREEN};
		if (var->fractal.test == 5)
			var->fractal.test = 0;
		var->fractal.color = array[var->fractal.test++];
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
	//printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	(void)y;
	(void)x;
	if (button == 4)
	{
		//normally -= Refactor
		//printf("zooming in\n");
		//formula is (y0 - y)/(x0-x);
/* 		printf("x/1000 is %f\n", (double)x/1000);
		var->fractal.Re_factor -= (var->fractal.MaxRe - var->fractal.MinRe - (double)x/1000) *0.05;
		var->fractal.Im_factor -= (0 - (double)y/1000) *0.05;
		
		printf("ReFactor is%f | ImFactor is %f\n", var->fractal.Re_factor, var->fractal.Im_factor); */
		var->fractal.Re_factor -= var->fractal.Re_factor * 0.05;
		var->fractal.Im_factor -= var->fractal.Im_factor * 0.05;
	}
	else if (button == 5)
	{
//		printf("zooming out\n");
		var->fractal.Re_factor += var->fractal.Re_factor * 0.05;
		var->fractal.Im_factor += var->fractal.Im_factor * 0.05;
//		printf("Re_factor is %f | Im_factor is %f\n", var->fractal.Re_factor, var->fractal.Im_factor);
	}
	return (0);
}
