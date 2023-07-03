#include "../include/fractol.h"


void my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, t_data *img)
{
	if (keycode == ESC)
	{
		ft_exit(img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int ft_exit(t_data *img)
{
	(void)img;
/* 	ft_putstr_fd("Exited G's Fractol\n", 1); */
	exit(EXIT_SUCCESS);
}

int mouse_hook(int button, int x, int y)
{
	printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	
	return (0);
}

int main()
{
	t_var	var;
	t_data	img;

	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, 1920, 1080, "Test");

	img.width_x = 1920;
	img.height_y = 1080;
	img.img = mlx_new_image(var.mlx, img.width_x, img.height_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	draw_mandelbrot_set(&var, &img);
/* 
	//ESC hook
	mlx_hook(var.mlx_win, 2, 0, key_hook, &img);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var.mlx_win, mouse_hook, (void *)0);
	//exit program through the cross
	mlx_hook(var.mlx_win, 17, 0, ft_exit, &img);
	 */
	mlx_loop(var.mlx);
	return (0);
}
  
// Driver code
int main()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm, errorcode;
  
  
    // setting the left, top, xside and yside
    // for the screen and image to be displayed
    float left, top, xside, yside;
    left = -1.75;
    top = -0.25;
    xside = 0.25;
    yside = 0.45;
    char driver[] = "";