/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:27:51 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/29 16:35:46 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

//drawing the fractal shape for Julia set
int juliaFractal(int x, int y) 
{
	t_complex z;
	t_complex c;
	t_complex temp;
	int iter = 0;
	double zx, zy;

	z.real = 0.0;
	z.imag = 0.0;
	c.real = x;
	c.imag = y;

	while (iter < MAX_ITER) 
	{
	    zx = z.real * z.real - z.imag * z.imag + c.real;
	    zy = 2 * z.real * z.imag + c.imag;
	    temp.real = zx;
	    temp.imag = zy;
	    if ((temp.real * temp.real + temp.imag * temp.imag) > 4.0)
	        break;
	    z = temp;
	    iter++;
	}
	return (iter);
}

void generateJuliaFractal(double startX, double startY, double endX, double endY, t_data *img) 
{
    double dx = (endX - startX) / img->width_x;
	printf("value of dx is %f\n", dx);
    double dy = (endY - startY) / img->height_y;
	printf("value of dy is %f\n", dy);
    double x, y;
    int i, j;
    
    for (j = 0, y = startY; j < img->height_y; j++, y += dy) 
	{
        for (i = 0, x = startX; i < img->width_x; i++, x += dx) 
		{
            my_mlx_pixel_put(img, x, y, F_ORANGE);
            // Map value to colors or shading and display the pixel
            // Here, you can implement your own code to visualize the fractal
        }
    }
}

void	drawing_image(void *mlx, void *mlx_win, t_data *img)
{
	img->width_x = 1920;
	img->height_y = 1080;
	img->img = mlx_new_image(mlx, img->width_x, img->height_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	
	for (int x = 0; x < img->width_x; x++)
			my_mlx_pixel_put(img, x, img->height_y/2, F_RED);
	for (int y = 0; y < img->height_y; y++)
		my_mlx_pixel_put(img, img->width_x/2, y, F_RED);
	my_mlx_pixel_put(img, img->width_x, img->height_y/2, F_ORANGE);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_string_put(mlx, mlx_win, img->width_x/2, img->height_y/2, F_ORANGE, "0,0");
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	double startX = -2.0;
    double startY = -2.0;
    double endX = 2.0;
    double endY = 2.0;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "G's Fractol");

	drawing_image(mlx, mlx_win, &img);
	//drawing the two axis
	
/* 	generateJuliaFractal(0, 0, img.width_x, img.height_y, &img); */
	
	//keyhooks for different events
	mlx_hook(mlx_win, 2, 0, key_hook, &img);
	mlx_hook(mlx_win, 9, 0, zoom_in, &img);
	mlx_mouse_hook(mlx_win, mouse_hook, (void *)0);
	mlx_hook(mlx_win, 17, 0, ft_exit, &img);
	
	mlx_loop(mlx);
}

	/*

int main() {
   
    
    generateJuliaFractal(startX, startY, endX, endY);
    
    return 0;
}

	*/
	