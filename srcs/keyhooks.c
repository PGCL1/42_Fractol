/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:15:07 by glacroix          #+#    #+#             */
/*   Updated: 2023/06/28 14:41:00 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
	{
		ft_putstr_fd("Exited G's Fractol\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int mouse_hook(int button, int x, int y)
{
	printf("%d | screen(x = %d, y = %d)\n", button, x, y);
	return (0);
}
