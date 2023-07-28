/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 21:57:42 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	movements(int keycode, t_data *var)
{
	if (keycode == W || keycode == UP)
	{
		var->fract.MinIm += var->fract.Im_center * (var->fract.Im_factor * 20);
		var->fract.MaxIm += var->fract.Im_center * (var->fract.Im_factor * 20);
	}
	else if (keycode == S || keycode == DOWN)
	{
		var->fract.MaxIm -= var->fract.Im_center * (var->fract.Im_factor * 20);
		var->fract.MinIm -= var->fract.Im_center * (var->fract.Im_factor * 20);
	}
	else if (keycode == A || keycode == LEFT)
	{
		var->fract.MinRe -= var->fract.Re_center * (var->fract.Re_factor * 8); 
		var->fract.MaxRe -= var->fract.Re_center * (var->fract.Re_factor * 8);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		var->fract.MinRe += var->fract.Re_center * (var->fract.Re_factor * 8);
		var->fract.MaxRe += var->fract.Re_center * (var->fract.Re_factor * 8);
	}
}

void iterations(int keycode, t_data *var)
{
	if (var->fract.MaxIterations > 310)
		var->fract.MaxIterations = 10;
	if (keycode == PLUS)
	{
		var->fract.MaxIterations += 10;
		if (var->fract.MaxIterations == 310)
			var->fract.MaxIterations = 10;
	}
	else if (keycode == MINUS)
	{
		var->fract.MaxIterations -= 10;
		if (var->fract.MaxIterations == 0)
			var->fract.MaxIterations = 10;
	}
}

void colors_and_types(int keycode, t_data *var)
{
	if (keycode == C)
	{
		int array[5] = {F_WHITE, F_BLUE, F_ORANGE, F_PURPLE, F_GREEN};
		if (var->fract.color_index == 5)
			var->fract.color_index = 0;
		var->fract.color = array[var->fract.color_index++];
	}
	else if (keycode == F && var->fract.type == 2)
	{
		if (var->fract.index == 8)
			var->fract.index = 1;
		var->fract.index++;
	}
}

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
