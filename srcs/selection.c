/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:58:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/20 20:58:37 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_islower(char *str)
{
	char *temp;

	temp = str;
	while (*temp != '\0')
	{
		if (*temp >= 'A' && *temp <= 'Z')
			*temp += 32;
		temp++;
	}
}

int	fractal_name(char *str, t_data *var)
{
	ft_islower(str);
	if (!ft_strncmp(str, "mandelbrot", ft_strlen(str) + 1)
		|| !ft_strncmp(str, "1", 2))
		var->fractal.type = 1;
	else if (!ft_strncmp(str, "julia", ft_strlen(str) + 1)
		|| !ft_strncmp(str, "2", 2))
		var->fractal.type = 2;
	else if (!ft_strncmp(str, "multibrot", ft_strlen(str) + 1)
		|| !ft_strncmp(str, "3", 2))
		var->fractal.type = 3;
	else
		var->fractal.type = 0;
	return (var->fractal.type);
}

int	generate_fractal(t_data *var)
{
	if (var->fractal.type == 1)
		generate_mandelbrot(var);
	else if (var->fractal.type == 2)
		generate_julia(var);
	else if (var->fractal.type == 3)
		generate_multibrot(var);
	return (0);
}
