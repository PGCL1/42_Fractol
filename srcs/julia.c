/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:17:43 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/17 20:57:19 by glacroix         ###   ########.fr       */
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

static double julia_set_im(t_complex *c, int i)
{
	if (i == 1)
		c->imag = 0;
	else if (i == 2)
		c->imag = 0.01;
	else if (i == 3)
		c->imag = 0.1428;
	else if (i == 4)
		c->imag = -.3842;
	else if (i == 5)
		c->imag = -.2321;
	else if (i == 6)
		c->imag = -.2321;
	else if (i == 7)
		c->imag = 0.1889;
	else
		c->imag = 0.8;
	return (c->imag);	
}
static double julia_set_re(t_complex *c, int i)
{
	if (i == 1)
		c->real = 0.285;
	else if (i == 2)
		c->real = 0.285;
	else if (i == 3)
		c->real = 0.45;
	else if (i == 4)
		c->real = -0.70176;
	else if (i == 5)
		c->real = -0.8;
	else if (i == 6)
		c->real = -0.835;
	else if (i == 7)
		c->real = -0.7269;
	else
		c->real = 0;
	return (c->real);	
}

int generate_julia(t_data *var)
{
	int y;
	int x;
	t_complex Z;
	t_complex c;

	y = 0;
	while (++y < var->img.height_y - 1)
	{
		c.imag = julia_set_im(&c, var->fractal.index);
		x = 0;
    	while (++x < var->img.width_x - 1)
    	{
    	    c.real = julia_set_re(&c, var->fractal.index);
    	    Z.real = var->fractal.MinRe + x * var->fractal.Re_factor;
			Z.imag = var->fractal.MaxIm - y * var->fractal.Im_factor;
    	    julia_in_or_out(var, &Z, &c, &x, &y);
    	}
	}
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
	print_iterations(var);
	return (0);
}

