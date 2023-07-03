/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:19:04 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/03 18:41:09 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


//separate in two functions one to see where 
void draw_mandelbrot_set(t_var *var, t_data *img, float left, float top, float xside, float yside)
{
 	float xscale, yscale, zx, zy, cx, tempx, cy;
    int x, y;
    int maxx, maxy, iteration;

	// getting maximum value of x-axis of screen
    maxx = 1920;
  
    // getting maximum value of y-axis of screen
    maxy = 1080;
  
    // setting up the xscale and yscale
    xscale = xside / maxx;
    yscale = yside / maxy;
	
  	for (y = 1; y <= maxy - 1; y++) 
  	{
        for (x = 1; x <= maxx - 1; x++)
        {
            // c_real
            cx = x * xscale + left;
  
            // c_imaginary
            cy = y * yscale + top;
  
            // z_real
            zx = 0;
  
            // z_imaginary
            zy = 0;
            iteration = 0;
		}
	}
	while ((zx * zx + zy * zy < 4) && (iteration < MAX_ITERATION))
    {
        // Calculate Mandelbrot function
        // z = z*z + c where z is a complex number
        // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
        tempx = zx * zx - zy * zy + cx;
        // 2*z_real*z_imaginary + c_imaginary
        zy = 2 * zx * zy + cy;
        // Updating z_real = tempx
        zx = tempx;
        // Increment iteration
        iteration++;
    }
	if (iteration == MAX_ITERATION)
		my_mlx_pixel_put(var->mlx, zx, zy, F_RED);
	mlx_put_image_to_window(var->mlx, var->mlx_win, img->img, 0, 0);
}
