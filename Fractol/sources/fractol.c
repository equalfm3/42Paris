/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:30:13 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:08:50 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		window_creator(t_data *data)
{
	data->mlx_ptr = mlx_init();
	(*data).iter = 50;
	data->img_ptr_menu = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->idata_ptr_menu = (int*)mlx_get_data_addr(data->img_ptr_menu,
		&data->bpp, &data->size_line, &data->endian);
	menu_displayer(&(*data));
	key_array_initiator(&(*data));
	if (data->fractol_th1 != 0)
	{
		data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "1");
		data->img_ptr = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->idata_ptr = (int*)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
		hook_and_display_th1(&*data);
	}
	if (data->fractol_th2 != 0)
	{
		data->win_ptr2 = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "2");
		data->img_ptr2 = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->idata_ptr2 = (int*)mlx_get_data_addr(data->img_ptr2, &data->bpp,
			&data->size_line, &data->endian);
		hook_and_display_th2(&*data);
	}
	mlx_loop(data->mlx_ptr);
}

int			fractal_data_setter(t_data *data, char *av)
{
	if (!av[1] && av[0] >= '1' && av[0] <= '9')
	{
		if (data->fractol_th1 == 0)
			data->fractol_th1 = ft_atoi(av);
		else if (data->fractol_th2 == 0)
			data->fractol_th2 = ft_atoi(av);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

void		thread_initiator(t_data *data)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;

	ft_bzero(&thread1, sizeof(thread1));
	ft_bzero(&thread2, sizeof(thread2));
	ft_bzero(&thread3, sizeof(thread3));
	ft_bzero(&thread4, sizeof(thread4));
	data->thread[0].thread = thread1;
	data->thread[1].thread = thread2;
	data->thread[2].thread = thread3;
	data->thread[3].thread = thread4;
}

void		fractal_displayer(t_data *data, int win)
{
	if (win == 1)
	{
		data->zoom = &data->zoom_th1;
		data->mx = &data->movex_th1;
		data->my = &data->movey_th1;
		data->fractol = &data->fractol_th1;
		data->win_thread = data->win_thread1;
	}
	else if (win == 2)
	{
		data->zoom = &data->zoom_th2;
		data->mx = &data->movex_th2;
		data->my = &data->movey_th2;
		data->fractol = &data->fractol_th2;
		data->win_thread = data->win_thread2;
	}
	thread_creator((void*)main_cycle, &(*data), (*data).win_thread);
}

int			main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	data.zoom_th1 = 0.5;
	data.t_rgb.r = 64;
	data.t_rgb.g = 32;
	data.t_rgb.b = 16;
	data.zoom_th2 = 0.5;
	input_validator(ac, av, &data);
	if (W_WIDTH < 300 || W_WIDTH < W_HEIGHT)
		usage_displayer();
	thread_initiator(&data);
	window_creator(&data);
	return (1);
}
