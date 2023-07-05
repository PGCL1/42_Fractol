/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:11:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/05 19:21:58 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void generate_mandelbrot(t_data *var)
{
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*var->img.height_y/var->img.width_x;
	
	double Re_factor = (MaxRe-MinRe)/(var->img.width_x-1);
	double Im_factor = (MaxIm-MinIm)/(var->img.height_y-1);
	int MaxIterations = 150;
	int i = 0;

	//x, y are the starting points from which the image is drawn
	int y;
	int x;
	
	for(y=0; y< var->img.height_y-1; ++y)
	{
    	double c_im = MaxIm - y*Im_factor;
    	for(x=0; x<var->img.width_x-1; ++x)
    	{
    	    double c_re = MinRe + x*Re_factor;
    	    double Z_re = c_re, Z_im = c_im;
    	    i = 0;
    	    for(int n=0; n<MaxIterations; ++n)
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
			{
				// mlx_pixel_put(var->mlx.ptr, var->mlx.win, x, y, F_RED);
				my_mlx_pixel_put(&var->img, x, y, F_RED);
			} 
			else
				my_mlx_pixel_put(&var->img, x, y, F_ORANGE);
				//mlx_pixel_put(var->mlx.ptr, var->mlx.win, x, y, F_ORANGE);
    	}
	}
	printf("width: %d | height: %d\n", x, y);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
}


/*
my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
*/