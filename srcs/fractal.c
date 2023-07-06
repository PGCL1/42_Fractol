/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:11:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/06 17:53:56 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int generate_mandelbrot(t_data *var)
{
	//defining the position of the fractal -- could be optimized to define a center
	//add 0.01 to go the left, substract 0.01 to go to the right
	var->fractal.MinRe = -(var->img.width_x/1000);
	var->fractal.MaxRe = (var->img.width_x/1000);
	//add 0.01 to go down, substract 0.01 to go up
	var->fractal.MinIm = -(var->img.height_y/1000);
	var->fractal.MaxIm = (var->img.height_y/1000);
	
	var->fractal.Re_factor = (var->fractal.MaxRe - var->fractal.MinRe)/(var->img.width_x-1);
	var->fractal.Im_factor = (var->fractal.MaxIm - var->fractal.MinIm)/(var->img.height_y-1);
	var->fractal.MaxIterations = 400;

	int i = 0;

	//x, y are the starting points from which the image is drawn
	int y;
	int x;
	
	for(y = 0; y < var->img.height_y - 1; ++y)
	{
    	double c_im = var->fractal.MaxIm - y*var->fractal.Im_factor;
    	for(x = 0; x < var->img.width_x - 1; ++x)
    	{
    	    double c_re = var->fractal.MinRe + x*var->fractal.Re_factor;
    	    double Z_re = c_re, Z_im = c_im;
    	    i = 0;
    	    for(int n=0; n<var->fractal.MaxIterations; ++n)
    	    {
    	        double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
    	        if(Z_re2 + Z_im2 > 4)
    	        {
    	            i = 1;
    	            break;
    	        }
    	        Z_im = 2*Z_re*Z_im + c_im;
    	        Z_re = Z_re2 - Z_im2 + c_re;
    	    }
    	    if (i == 0)
				my_mlx_pixel_put(&var->img, x, y, F_RED);
			else
				my_mlx_pixel_put(&var->img, x, y, F_ORANGE);
    	}
	}
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
	return (0);
}


/*
z is the number 
we square z + constant


my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
*/