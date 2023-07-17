/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:59:03 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/17 18:37:53 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	multibrot_in_or_out(t_data *var, t_complex *Z, t_complex *c, int *x, int *y)
{
	double Z_re_k;
    double Z_im_k;
	int i = 0;
	int n = 0;
	while (++n < var->fractal.MaxIterations)
    {
		Z_re_k = Z->real*Z->real*Z->real*Z->real;
		Z_im_k = Z->imag*Z->imag*Z->imag*Z->imag;
        if(Z_re_k + Z_im_k > 4)
        {
            i = 1;
            break;
        }
        Z->real = Z_re_k - 6*(Z->real*Z->real)*(Z->imag*Z->imag) + Z_im_k + c->real;
        Z->imag = (4*Z_re_k*Z->imag - 4*Z->real*Z_im_k) * c->imag;
    }
	my_mlx_pixel_put(&var->img, *x, *y, var->fractal.color * n);
	if (i == 0)
		my_mlx_pixel_put(&var->img, *x, *y, F_BLACK);
}

//(a + i)3 = a3 + 3a2i + 3ai2 + i3

int generate_multibrot(t_data *var)
{	
	//x, y are the starting points from which the image is drawn
	int y;
	int x;
	t_complex Z;
	t_complex c;

	y = 0;
	while (++y < var->img.height_y - 1)
	{
		c.imag = var->fractal.MaxIm - y * var->fractal.Im_factor;
		x = 0;
    	while (++x < var->img.width_x - 1)
    	{
    	    c.real = var->fractal.MinRe + x * var->fractal.Re_factor;
    	    Z.real = c.real;
			Z.imag = c.imag;
    	    multibrot_in_or_out(var, &Z, &c, &x, &y);
    	}
	}
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->img.img, 0, 0);
	print_iterations(var);
	return (0);
}
