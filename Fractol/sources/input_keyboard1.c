/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:30:44 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:10:08 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_press_th1(int keycode, t_data *data)
{
	if (keycode < 128 && data->key_array[keycode])
	{
		key_processer_th1(keycode, &*data);
		fractal_displayer(&(*data), 1);
	}
	return (1);
}

int			key_press_th2(int keycode, t_data *data)
{
	if (keycode < 128 && data->key_array[keycode])
	{
		key_processer_th2(keycode, &*data);
		fractal_displayer(&(*data), 2);
	}
	return (1);
}

void		key_array_initiator(t_data *data)
{
	ft_bzero(&data->key_array, sizeof(data->key_array));
	data->key_array[116] = 1;
	data->key_array[121] = 1;
	data->key_array[126] = 1;
	data->key_array[125] = 1;
	data->key_array[123] = 1;
	data->key_array[124] = 1;
	data->key_array[69] = 1;
	data->key_array[78] = 1;
	data->key_array[37] = 1;
	data->key_array[46] = 1;
	data->key_array[8] = 1;
	data->key_array[89] = 1;
	data->key_array[91] = 1;
	data->key_array[92] = 1;
	data->key_array[86] = 1;
	data->key_array[87] = 1;
	data->key_array[88] = 1;
	data->key_array[49] = 1;
	data->key_array[53] = 1;
}

void		hook_and_display_th1(t_data *data)
{
	fractal_processer(&(*data), &data->win_thread1, &data->idata_ptr);
	mlx_hook(data->win_ptr, 6, (1L << 6), mouse_move_th1, &(*data));
	mlx_hook(data->win_ptr, 4, (1L << 2), mouse_zoom_th1, &(*data));
	mlx_hook(data->win_ptr, 2, 0, key_press_th1, &(*data));
	mlx_hook(data->win_ptr, 17, (1L << 17), ft_exit, 0);
	fractal_displayer(&(*data), 1);
}

void		hook_and_display_th2(t_data *data)
{
	fractal_processer(&(*data), &data->win_thread2, &data->idata_ptr2);
	mlx_hook(data->win_ptr2, 6, (1L << 6), mouse_move_th2, &(*data));
	mlx_hook(data->win_ptr2, 4, (1L << 2), mouse_zoom_th2, &(*data));
	mlx_hook(data->win_ptr2, 2, 0, key_press_th2, &(*data));
	mlx_hook(data->win_ptr2, 17, (1L << 17), ft_exit, 0);
	fractal_displayer(&(*data), 2);
}
