/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:31:13 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:12:11 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		color_resetter(t_data *data)
{
	data->t_rgb.r = 64;
	data->t_rgb.g = 32;
	data->t_rgb.b = 16;
}

void		color_cycler(int keycode, t_data *data)
{
	(keycode == 89 && data->t_rgb.r < 253) ? data->t_rgb.r += 1 : 0;
	(keycode == 91 && data->t_rgb.g < 253) ? data->t_rgb.g += 1 : 0;
	(keycode == 92 && data->t_rgb.b < 253) ? data->t_rgb.b += 1 : 0;
	(keycode == 86 && data->t_rgb.r > 0) ? data->t_rgb.r -= 1 : 0;
	(keycode == 87 && data->t_rgb.g > 0) ? data->t_rgb.g -= 1 : 0;
	(keycode == 88 && data->t_rgb.b > 0) ? data->t_rgb.b -= 1 : 0;
	(keycode == 53) ? ft_exit() : 0;
}

void		key_processer_th1(int keycode, t_data *data)
{
	if (keycode == 69 && data->zoom_th1 < ZOOM_MAX)
		data->zoom_th1 += 0.1 * (data->zoom_th1);
	else if ((keycode == 78) && data->zoom_th1 > 0.5)
		data->zoom_th1 -= 0.1 * (data->zoom_th1);
	else if (keycode == 126 && data->movey_th1 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_th1 -= 0.1 / (data->zoom_th1);
	else if (keycode == 125 && data->movey_th1 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_th1 += 0.1 / (data->zoom_th1);
	else if (keycode == 123 && data->movex_th1 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_th1 -= 0.1 / (data->zoom_th1);
	else if (keycode == 124 && data->movex_th1 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_th1 += 0.1 / (data->zoom_th1);
	else if (keycode == 37)
		data->mouse_mod1 = (data->mouse_mod1 == 1) ? 0 : 1;
	else if (keycode == 46)
		data->menu_show1 = (data->menu_show1 == 1) ? 0 : 1;
	(keycode == 121 && data->iter > 10) ? data->iter -= 1 : 0;
	(keycode == 116 && data->iter < 200) ? data->iter += 1 : 0;
	(keycode == 49) ? resetter_th1(&(*data)) : 0;
	(keycode == 8) ? color_resetter(&(*data)) : 0;
	color_cycler(keycode, &(*data));
}

void		key_processer_th2(int keycode, t_data *data)
{
	if (keycode == 69 && data->zoom_th2 < ZOOM_MAX)
		data->zoom_th2 += 0.1 * (data->zoom_th2);
	else if ((keycode == 78) && data->zoom_th2 > 0.5)
		data->zoom_th2 -= 0.1 * (data->zoom_th2);
	else if (keycode == 126 && data->movey_th2 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_th2 -= 0.1 / (data->zoom_th2);
	else if (keycode == 125 && data->movey_th2 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movey_th2 += 0.1 / (data->zoom_th2);
	else if (keycode == 123 && data->movex_th2 > -((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_th2 -= 0.1 / (data->zoom_th2);
	else if (keycode == 124 && data->movex_th2 < ((W_WIDTH / W_HEIGHT) * 1.5))
		data->movex_th2 += 0.1 / (data->zoom_th2);
	else if (keycode == 37)
		data->mouse_mod2 = (data->mouse_mod2 == 1) ? 0 : 1;
	else if (keycode == 46)
		data->menu_show2 = (data->menu_show2 == 1) ? 0 : 1;
	(keycode == 121 && data->iter > 10) ? data->iter -= 1 : 0;
	(keycode == 116 && data->iter < 200) ? data->iter += 1 : 0;
	(keycode == 49) ? resetter_th2(&(*data)) : 0;
	(keycode == 8) ? color_resetter(&(*data)) : 0;
	color_cycler(keycode, &(*data));
}
