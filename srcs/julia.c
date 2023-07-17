/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:17:43 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/17 17:35:00 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	julia_in_or_out(t_data *var, t_complex *Z, t_complex *c, int *x, int *y)
{
	double Z_re2;
    double Z_im2;
	int i = 0;
	int n = 0;
	while (++n < var->fractal.MaxIterations)
    {
		Z_re2 = Z->real * Z->real;
		Z_im2 = Z->imag * Z->imag;
        if(Z_re2 + Z_im2 > 4)
        {
            i = 1;
            break;
        }
        Z->imag = 2*Z->real*Z->imag + c->imag;
        Z->real = Z_re2 - Z_im2 + c->real;
    }
	my_mlx_pixel_put(&var->img, *x, *y, var->fractal.color * n);
	if (i == 0)
		my_mlx_pixel_put(&var->img, *x, *y, F_BLACK);
}

/* t_complex *julia_sets(t_complex *c)
{
	// c = 0.285 + 0
	//  0.285 + 0.01
	//c = 0.45 + 0.1428
	//c = −0.70176 − 0.3842
	//c = −0.835 − 0.2321
	//c = −0.8 + 0.156i
	//c = −0.7269 + 0.1889
	//c = 0.8i
	c->imag = 0;	
	c->real = 0;
	return (c);	
} */

int generate_julia(t_data *var)
{
	int y;
	int x;
	t_complex Z;
	t_complex c;

	y = 0;
	while (++y < var->img.height_y - 1)
	{
		c.imag = 0;
		x = 0;
    	while (++x < var->img.width_x - 1)
    	{
    	    c.real = 0.285;
    	    Z.real = var->fractal.MinRe + x * var->fractal.Re_factor;
			Z.imag = var->fractal.MaxIm - y * var->fractal.Im_factor;
    	    julia_in_or_out(var, &Z, &c, &x, &y);
    	}
	}
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
	print_iterations(var);
	return (0);
}

