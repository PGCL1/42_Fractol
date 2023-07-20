/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/20 17:56:02 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_data *var)
{
	printf("Keycode is %d\n", keycode);
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
	else if (keycode == F)
	{
		if (var->fractal.index == 7)
			var->fractal.index = 1;
		printf("keyhook index is %d\n", var->fractal.index);
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
	//printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	(void)y;
	(void)x;
	if (button == 4)
	{
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


/*
void	mouse_zoom(t_data *data, double zoom, int x, int y)
{
	double	normalized_radius_re;
	double	normalized_radius_im;
	double	delta_x;
	double	delta_y;

	data->norm_x = data->max_re + ((double)(WIDTH - x) *(data->min_re
				- data->max_re) / WIDTH);
	data->norm_y = data->max_im + ((double)y * (data->min_im
				- data->max_im) / HEIGHT);
	data->center_im = ((data->max_im - data->min_im) / 2) + data->min_im;
	data->center_re = ((data->max_re - data->min_re) / 2) + data->min_re;
	normalized_radius_re = data->max_re - data->center_re;
	normalized_radius_im = data->max_im - data->center_im;
	delta_x = (data->norm_x - data->center_re);
	delta_y = (data->norm_y - data->center_im);
	normalized_radius_re *= zoom;
	normalized_radius_im *= zoom;
	delta_x *= zoom;
	delta_y *= zoom;
	data->center_re = data->norm_x - delta_x;
	data->center_im = data->norm_y - delta_y;
	data->max_re = normalized_radius_re + data->center_re;
	data->min_re = data->center_re - normalized_radius_re;
	data->max_im = normalized_radius_im + data->center_im;
	data->min_im = data->center_im - normalized_radius_im;
}

*/