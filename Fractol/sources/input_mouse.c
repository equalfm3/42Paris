/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:31:35 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:12:36 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_move_th1(int x, int y, t_data *data)
{
	if (x > 0 && x <= W_WIDTH && y > 0 && y <= W_HEIGHT &&
		data->mouse_mod1 == 1 && (*data->fractol == 1 || *data->fractol == 2))
	{
		data->mouse_y = ((double)(y - W_HEIGHT / 2) / W_HEIGHT);
		data->mouse_x = ((double)(x - W_WIDTH / 2) / W_WIDTH);
		fractal_displayer(&(*data), 1);
	}
	return (0);
}

int			mouse_zoom_th1(int g, int x, int y, t_data *data)
{
	double	t1;
	double	t2;

	if (g == 5 || g == 4)
	{
		if ((g == 4 && data->zoom_th1 && data->zoom_th1 < ZOOM_MAX) ||
		(g == 5 && data->zoom_th1 > 0.5))
		{
			t1 = *data->mx;
			t2 = *data->my;
			*data->mx += new_ri(&*data, x, 1, *data->mx);
			*data->my += new_ri(&*data, y, 2, *data->my);
			if (g == 4 && data->zoom_th1 && data->zoom_th1 < ZOOM_MAX)
				data->zoom_th1 += 0.1 * (data->zoom_th1);
			if (g == 5 && data->zoom_th1 > 0.5)
				data->zoom_th1 -= 0.1 * (data->zoom_th1);
			*data->mx -= new_ri(&*data, x, 1, t1);
			*data->my -= new_ri(&*data, y, 2, t2);
			fractal_displayer(&(*data), 1);
		}
	}
	return (1);
}

int			mouse_zoom_th2(int g, int x, int y, t_data *data)
{
	double	t1;
	double	t2;

	if (g == 5 || g == 4)
	{
		if ((g == 4 && data->zoom_th2 && data->zoom_th2 < ZOOM_MAX) ||
		(g == 5 && data->zoom_th2 > 0.5))
		{
			t1 = *data->mx;
			t2 = *data->my;
			*data->mx += new_ri(&*data, x, 1, *data->mx);
			*data->my += new_ri(&*data, y, 2, *data->my);
			if (g == 4 && data->zoom_th2 && data->zoom_th2 < ZOOM_MAX)
				data->zoom_th2 += 0.1 * (data->zoom_th2);
			if (g == 5 && data->zoom_th2 > 0.5)
				data->zoom_th2 -= 0.1 * (data->zoom_th2);
			*data->mx -= new_ri(&*data, x, 1, t1);
			*data->my -= new_ri(&*data, y, 2, t2);
			fractal_displayer(&(*data), 2);
		}
	}
	return (1);
}

int			mouse_move_th2(int x, int y, t_data *data)
{
	if (x > 0 && x <= W_WIDTH && y > 0 && y <= W_HEIGHT &&
	data->mouse_mod2 == 1 && (*data->fractol == 1 || *data->fractol == 2))
	{
		data->mouse_y = ((double)(y - W_HEIGHT / 2) / W_HEIGHT);
		data->mouse_x = ((double)(x - W_WIDTH / 2) / W_WIDTH);
		fractal_displayer(&(*data), 2);
	}
	return (0);
}
