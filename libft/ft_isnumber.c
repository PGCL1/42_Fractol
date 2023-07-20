/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:02:24 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/20 17:16:02 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	size_t	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] && str[i] != '\0')
	{
		if (i == 0 && str[i] == '.' && ft_isdigit(str[i + 1]) == 1)
			i++;
		else if (i == 0 && ft_isdigit(str[i]) == 1 && str[i + 1] == '.')
			i += 2;
		else if (str[i] && ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}
