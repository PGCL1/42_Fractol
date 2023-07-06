/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:05:47 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/06 17:13:50 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;

	s = NULL;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (s);
	s = (unsigned char *)malloc(count * size);
	if (s == 0)
		return (0);
	ft_bzero(s, count * size);
	return (s);
}
