/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:58:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/04 18:11:32 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_islower(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int	fractal_name(char *str)
{
	ft_islower(str);
	if (!ft_strncmp(str, "mandelbrot", ft_strlen(str))
		|| !ft_strncmp(str, "1", 2))
		return (1);
	else if (!ft_strncmp(str, "julia", ft_strlen(str))
		|| !ft_strncmp(str, "2", 2))
		return (2);
	/*else if add other fractals*/
	return (0);
}
