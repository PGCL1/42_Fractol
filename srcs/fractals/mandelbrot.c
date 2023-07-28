/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:11:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 17:43:43 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	mandelbrot_in_or_out(t_data *var, t_complex *Z, int *x, int *y)
{
	double Z_re2;
    double Z_im2;
	int i = 0;
	int n = 0;
	while (++n < var->fract.MaxIterations)
    {
		Z_re2 = Z->real * Z->real;
		Z_im2 = Z->imag * Z->imag;
        if(Z_re2 + Z_im2 > 4)
        {
            i = 1;
            break;
        }
        Z->imag = 2*Z->real*Z->imag + var->fract.c.imag;
        Z->real = Z_re2 - Z_im2 + var->fract.c.real;
    }
	my_mlx_pixel_put(&var->img, *x, *y, var->fract.color * n);
	if (i == 0)
		my_mlx_pixel_put(&var->img, *x, *y, F_BLACK);
}


int generate_mandelbrot(t_data *var)
{	
	//x, y are the starting points from which the image is drawn
	int y;
	int x;
	t_complex Z;

	y = 0;
	while (++y < var->img.height_y - 1)
	{
		var->fract.c.imag = var->fract.MaxIm - y * var->fract.Im_factor;
		x = 0;
    	while (++x < var->img.width_x - 1)
    	{
    	    var->fract.c.real = var->fract.MinRe + x * var->fract.Re_factor;
    	    Z.real = var->fract.c.real;
			Z.imag = var->fract.c.imag;
    	    mandelbrot_in_or_out(var, &Z, &x, &y);
    	}
	}
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
	print_iterations(var);
	return (0);
}