/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:42:42 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/20 17:15:02 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_skip_sign(char **str)
{
	double	sign;

	sign = 1.0;
	while (ft_isspace(**str) == 1)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1.0;
		(*str)++;
	}
	return (sign);
}

double	ft_atof(char *str)
{
	int		j;
	double	re;
	double	decimal;
	double	sign;

	j = 0;
	re = 0.0;
	decimal = 0.0;
	sign = ft_skip_sign(&str);
	while (ft_isdigit(*str) == 1 && *str != '.')
		re = (*(str++) - '0') + (re * 10.0);
	if (*str == '.')
		++str;
	while (ft_isdigit(*str) == 1 && *str != '.')
	{
		decimal = (*(str++) - '0') + (decimal * 10.0);
		j++;
	}
	decimal /= ft_pow(10, j);
	return ((re + decimal) * sign);
}
