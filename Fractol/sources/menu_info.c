/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:33:00 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:25:09 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		menu_displayer(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = 0;
		while (++x < W_WIDTH)
			data->idata_ptr_menu[x + (y * ((W_WIDTH - W_HEIGHT) + W_HEIGHT))] =
		color_rgba(255 / 100 * (x / (W_WIDTH / 100)), 0, 0, 0);
	}
}

void		info_displayer_th1(t_data *data)
{
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr,
		(*data).img_ptr_menu, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, 0xffffff, "INFO");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 50,
		0xffffff, "7/8/9      :     R/G/B COLOR CYCLICAL ACCENTUATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 80,
		0xffffff, "4/5/6      :     R/G/B COLOR CYCLICAL DEACCENTUATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 110,
		0xffffff, "+/-        :     ZOOM");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 140,
		0xffffff, "MOUSE WHEEL:     ZOOM ON CURSOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 170,
		0xffffff, "ARROWS     :     TRANSLATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 200,
		0xffffff, "C          :     RESET COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 230,
		0xffffff, "PgUp/PgDn  :     CHANGE ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 260,
		0xffffff, "SPACE      :     RESET POSITION, ZOOM AND ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 290,
		0xffffff, "L          :     LOCK VIEW (ONLY JULIA)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 320,
		0xffffff, "M          :     SHOW/HIDE KEY/DATA");
}

void		info_displayer_th2(t_data *data)
{
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr2,
		(*data).img_ptr_menu, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 20, 0xffffff, "INFO");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 50,
		0xffffff, "7/8/9      :     R/G/B COLOR CYCLICAL ACCENTUATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 80,
		0xffffff, "4/5/6      :     R/G/B COLOR CYCLICAL DEACCENTUATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 110,
		0xffffff, "+/-        :     ZOOM");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 140,
		0xffffff, "MOUSE WHEEL:     ZOOM ON CURSOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 170,
		0xffffff, "ARROWS     :     TRANSLATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 200,
		0xffffff, "C          :     RESET COLOR");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 230,
		0xffffff, "PgUp/PgDn  :     CHANGE ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 260,
		0xffffff, "SPACE      :     RESET POSITION, ZOOM AND ITERATION");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 290,
		0xffffff, "L          :     LOCK VIEW (ONLY JULIA)");
	mlx_string_put(data->mlx_ptr, data->win_ptr2, 20, 320,
		0xffffff, "M          :     SHOW/HIDE KEY/DATA");
}

void		merge_all(t_data *data, t_thread *tr)
{
	if (data->win_thread1 == tr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr,
			(*data).img_ptr, 0, 0);
		if (data->menu_show1 == 1)
			menu_displayer_th1(&(*data));
		else
			mlx_string_put(data->mlx_ptr, data->win_ptr,
				W_WIDTH - 140, W_HEIGHT - 40, 0xffffff, "M - KEY/DATA");
	}
	else
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr2);
		mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr2,
			(*data).img_ptr2, 0, 0);
		if (data->menu_show2 == 1)
			menu_displayer_th2(&(*data));
		else
			mlx_string_put(data->mlx_ptr, data->win_ptr2,
				W_WIDTH - 140, W_HEIGHT - 40, 0xffffff, "M - KEY/DATA");
	}
}
