/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:47:14 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/27 17:32:12 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libft/libft.h"
#include <mlx.h>
#include <stdio.h>

/*--------------------------Makefile Colors-----------------------------------*/
# define RESET  		"\x1B[0m"
# define RED  			"\x1B[31m"
# define GREEN	  		"\x1B[32m"
# define YELLOW  		"\x1B[33m"
# define BLUE 			"\x1B[34m"
# define MAGENTA 		"\x1B[35m"
# define CAYN  			"\x1B[36m"
# define WHITE  		"\x1B[37m"

/*---------------------------Fractol Colors-----------------------------------*/
# define F_PURPLE			0X6600CC
# define F_ORANGE			0XFF8000
# define F_RED				0X990000
# define F_LIGHT_GREEN		0XCCFFCC
 
typedef struct t_win {
	int		size_x;
	int		size_y;
	void	*ptr;
}				t_win;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif