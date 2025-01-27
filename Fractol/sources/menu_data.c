/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:32:32 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:19:02 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		data_displayer_th2(t_data *data)
{
	char	*striter;
	char	*strzoom;

	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, W_HEIGHT - 50,
		0xffffff, "I         :");
	striter = ft_itoa(data->iter);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 180, W_HEIGHT - 50,
		0xffffff, striter);
	free(striter);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, W_HEIGHT - 80,
		0xffffff, "ZOOM      :");
	strzoom = ft_itoa((int)data->zoom_th1);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 180, W_HEIGHT - 80,
		0xffffff, strzoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, W_HEIGHT - 110,
		0xffffff, "DATA");
	free(strzoom);
}

void		data_displayer_th1(t_data *data)
{
	char	*striter;
	char	*strzoom;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, W_HEIGHT - 50,
		0xffffff, "I         :");
	striter = ft_itoa(data->iter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 180, W_HEIGHT - 50,
		0xffffff, striter);
	free(striter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, W_HEIGHT - 80,
		0xffffff, "ZOOM      :");
	strzoom = ft_itoa((int)data->zoom_th1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 180, W_HEIGHT - 80,
		0xffffff, strzoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, W_HEIGHT - 110,
		0xffffff, "DATA");
	free(strzoom);
}

void		menu_displayer_th1(t_data *data)
{
	info_displayer_th1(&(*data));
	data_displayer_th1(&*data);
}

void		menu_displayer_th2(t_data *data)
{
	info_displayer_th2(&(*data));
	data_displayer_th2(&*data);
}
