/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:11:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/11 17:42:55 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int generate_mandelbrot(t_data *var)
{	
	int i = 0;
	//x, y are the starting points from which the image is drawn
	int y = 0;
	int x;
	int n;
	t_complex Z;
	t_complex c;
    double Z_re2;
    double Z_im2;
	while (++y < var->img.height_y - 1)
	{
		c.imag = var->fractal.MaxIm - y * var->fractal.Im_factor;
		x = 0;
    	while (++x < var->img.width_x - 1)
    	{
    	    c.real = var->fractal.MinRe + x * var->fractal.Re_factor;
    	    Z.real = c.real;
			Z.imag = c.imag;
    	    i = 0;
			n = 0;
    	    while (++n < var->fractal.MaxIterations)
    	    {
				Z_re2 = Z.real * Z.real;
				Z_im2 = Z.imag * Z.imag;
    	        if(Z_re2 + Z_im2 > 4)
    	        {
    	            i = 1;
    	            break;
    	        }
    	        Z.imag = 2*Z.real*Z.imag + c.imag;
    	        Z.real = Z_re2 - Z_im2 + c.real;
    	    }
			my_mlx_pixel_put(&var->img, x, y, F_BLACK);
			if (i == 1 && n > 10)
				my_mlx_pixel_put(&var->img, x, y, F_WHITE);
			else if (i == 1 && n > 20)
				my_mlx_pixel_put(&var->img, x, y, F_ORANGE);
    	    else if (i == 0)
				my_mlx_pixel_put(&var->img, x, y, F_RED);
    	}
	}
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
	return (0);
}
