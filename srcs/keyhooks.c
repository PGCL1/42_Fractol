/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:33:37 by glacroix          #+#    #+#             */
/*   Updated: 2023/07/21 18:34:42 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int key_hook(int keycode, t_data *var)
{
	var->fract.Im_center = var->fract.MinIm - var->fract.MaxIm;
	var->fract.Re_center = var->fract.MinRe - var->fract.MaxRe;
	if (keycode == ESC)
		ft_exit(var);
	movements(keycode, var);
	iterations(keycode, var);	
	colors_and_types(keycode, var);
	return (0);
}


int mouse_hook(int button, int x, int y, t_data *var)
{
	if (button == 5) //zoom in
	{
		var->fract.MaxIm -= y * (1 - ZOOM) * var->fract.Im_factor;
		var->fract.MinRe += x * (1 - ZOOM) * var->fract.Re_factor;
		var->fract.Im_factor *= ZOOM;
		var->fract.Re_factor *= ZOOM;
	}
	else if (button == 4) // zoom out
	{
		var->fract.MaxIm -= y * (1 - 1/ZOOM) * var->fract.Im_factor;
		var->fract.MinRe += x * (1 - 1/ZOOM) * var->fract.Re_factor;
		var->fract.Re_factor /= ZOOM;
		var->fract.Im_factor /= ZOOM;
	}
	return (0);
}
