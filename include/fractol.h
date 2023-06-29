/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:47:14 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/29 16:33:25 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*--------------------------Makefile Colors-----------------------------------*/
# define RESET  		"\x1B[0m"
# define RED  			"\x1B[31m"
# define GREEN	  		"\x1B[32m"
# define YELLOW  		"\x1B[33m"
# define BLUE 			"\x1B[34m"
# define MAGENTA 		"\x1B[35m"
# define CAYN  			"\x1B[36m"
# define WHITE  		"\x1B[37m"

/*---------------------------Fractol Elements---------------------------------*/
# define F_PURPLE			0X6600CC
# define F_ORANGE			0XFF8000
# define F_RED				0X990000
# define F_LIGHT_GREEN		0XCCFFCC

#define MAX_ITER			1000

/*---------------------------Keys Keyboard------------------------------------*/
# define ESC				53

typedef struct t_complex {
    double real;
    double imag;
}				t_complex;

typedef struct t_win {
	int		size_x;
	int		size_y;
	void	*ptr;
}				t_win;

typedef struct	s_data {
	void	*img;
	double	height_y;
	double	width_x;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*--------------------------Fractol Functions---------------------------------*/
int		juliaFractal(int x, int y);
void	generateJuliaFractal(double startX, double startY, double endX, double endY, t_data *img);
void	drawing_image(void *mlx, void *mlx_win, t_data *img);
void	resize_window(t_data *img, int *x, int *y, void **mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


/*--------------------------Keyhook Functions---------------------------------*/
int		key_hook(int keycode, t_data *img);
int 	mouse_hook(int button, int x, int y);
int		zoom_in(int mouse, int x, int y, t_data *img, void **mlx);
int		ft_exit(t_data *img);

#endif