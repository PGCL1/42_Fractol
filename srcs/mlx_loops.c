/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:35:35 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/24 16:36:32 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void mlx_loops(t_data *var)
{
		//exit program through cross and ESC
	mlx_hook(var->mlx.win, 17, 0, ft_exit, var);
	mlx_hook(var->mlx.win, 2, 0, key_hook, var);
	//printing position of mouse and button pressed
	mlx_mouse_hook(var->mlx.win, mouse_hook, var);
	mlx_loop(var->mlx.ptr);
}
