/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:56:10 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/05 16:02:47 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <math.h>
#include <string.h>
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
# define F_BLACK			0X000000
# define F_WHITE			0XFFFFFF

/*------------------------------Shortcuts-------------------------------------*/
# define ESC				53
# define MAX_ITERATION		50


/*-----------------------------Structures-------------------------------------*/
typedef struct t_complex {
    double real;
    double imag;
}				t_complex;

typedef struct t_mlx {
	void	*ptr;
	void	*win;
	int		width_x;
	int		height_y;
}				t_mlx;

typedef struct t_img {
	void	*img;
	double	height_y;
	double	width_x;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	t_data {
	t_mlx		mlx;
	t_img		img;
	t_complex 	c;
}				t_data;

/*--------------------------Fractol Functions---------------------------------*/

/*-1) Keyhooks----------------------------------------------------------------*/
int		key_hook(int keycode, t_data *var);
int		ft_exit(t_data *img);
int		mouse_hook(int button, int x, int y);

/*-2) Fractal Selection-------------------------------------------------------*/
void	ft_islower(char *str);
int		fractal_name(char *str);

/*-2) Pixel Print-------------------------------------------------------------*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	generate_mandelbrot(t_data *var);

#endif