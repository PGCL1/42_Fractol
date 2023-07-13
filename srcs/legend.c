/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:12:45 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/13 19:13:44 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void print_iterations(t_data *var)
{
	char	*str = ft_itoa(var->fractal.MaxIterations);
	char	*str2 = ft_strjoin("ITERATIONS: ", str);
	mlx_string_put(var->mlx.ptr, var->mlx.win, 20, 20, F_WHITE, str2);
	free(str);
	free(str2);	
}