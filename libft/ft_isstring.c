/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:43:28 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/19 19:01:26 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstring(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}