/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/20 21:53:35 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_data *var)
{
	//printf("Keycode is %d\n", keycode);
	var->fractal.Im_center = var->fractal.MinIm - var->fractal.MaxIm;
	var->fractal.Re_center = var->fractal.MinRe - var->fractal.MaxRe;
	if (keycode == ESC)
		ft_exit(var);
	else if (keycode == W || keycode == UP)
	{
		var->fractal.MinIm += var->fractal.Im_center * (var->fractal.Im_factor * 20);
		var->fractal.MaxIm += var->fractal.Im_center * (var->fractal.Im_factor * 20);
	}
	else if (keycode == S || keycode == DOWN)
	{
		var->fractal.MaxIm -= var->fractal.Im_center * (var->fractal.Im_factor * 20);
		var->fractal.MinIm -= var->fractal.Im_center * (var->fractal.Im_factor * 20);
	}
	else if (keycode == A || keycode == LEFT)
	{
		var->fractal.MinRe -= var->fractal.Re_center * (var->fractal.Re_factor * 8); 
		var->fractal.MaxRe -= var->fractal.Re_center * (var->fractal.Re_factor * 8);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		var->fractal.MinRe += var->fractal.Re_center * (var->fractal.Re_factor * 8);
		var->fractal.MaxRe += var->fractal.Re_center * (var->fractal.Re_factor * 8);
	}
	else if (keycode == PLUS)
	{
		var->fractal.MaxIterations += 10;
		if (var->fractal.MaxIterations == 310)
			var->fractal.MaxIterations = 10;
	}
	else if (keycode == MINUS)
	{
		var->fractal.MaxIterations -= 10;
		if (var->fractal.MaxIterations == 0)
			var->fractal.MaxIterations = 10;
	}
	else if (keycode == C)
	{
		int array[5] = {F_WHITE, F_BLUE, F_ORANGE, F_PURPLE, F_GREEN};
		if (var->fractal.test == 5)
			var->fractal.test = 0;
		var->fractal.color = array[var->fractal.test++];
	}
	else if (keycode == F && var->fractal.type == 2)
	{
		if (var->fractal.index == 8)
			var->fractal.index = 1;
		var->fractal.index++;
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
	(void)x;
	(void)y;
	if (button == 5)
	{
		var->fractal.MaxIm -= y * (1 - ZOOM) * var->fractal.Im_factor;
		var->fractal.MinRe += x * (1 - ZOOM) * var->fractal.Re_factor;
		var->fractal.Im_factor *= ZOOM;
		var->fractal.Re_factor *= ZOOM;
	}
	else if (button == 4)
	{
		var->fractal.MaxIm -= y * (1 - 1/ZOOM) * var->fractal.Im_factor;
		var->fractal.MinRe += x * (1 - 1/ZOOM) * var->fractal.Re_factor;
		var->fractal.Re_factor /= ZOOM;
		var->fractal.Im_factor /= ZOOM;
	}
	return (0);
}
