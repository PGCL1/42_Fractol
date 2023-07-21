/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:21:05 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 18:26:19 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mlx(t_data *var)
{
	//initializing API connection and window
	var->mlx.ptr = mlx_init();
	if (!var->mlx.ptr)
		exit(EXIT_FAILURE);
	var->mlx.height_y = 768; //768 | 1080
	var->mlx.width_x = 1366; //1366 | 1920
	var->mlx.win = mlx_new_window(var->mlx.ptr, var->mlx.width_x, var->mlx.height_y, "G's Fractol");
}

void	init_image(t_data *var)
{
	//initializing img dimensions and address
	var->img.height_y = var->mlx.height_y;
	var->img.width_x = var->mlx.width_x;
	var->img.img = mlx_new_image(var->mlx.ptr, var->img.width_x, var->img.height_y);
	if (!var->img.img)
		exit(EXIT_FAILURE);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
}

void	init_fractal(t_data *var)
{
	//fractal dimensions
	var->fract.MinRe = -(var->img.width_x/500);
	var->fract.MaxRe = (var->img.width_x/500);
	var->fract.MinIm = -(var->img.height_y/500);
	var->fract.MaxIm = (var->img.height_y/500);
	//related to zooming and out and probably middle too
	var->fract.Re_factor = (var->fract.MaxRe - var->fract.MinRe)/(var->img.width_x);
	var->fract.Im_factor = (var->fract.MaxIm - var->fract.MinIm)/(var->img.height_y);
	var->fract.color = 265;
	var->fract.MaxIterations = 40;
}

void	init_all(t_data *var)
{
	init_mlx(var);
	init_image(var);
	init_fractal(var);
}
