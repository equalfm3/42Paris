/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:33:23 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:25:31 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	resetter_th1(t_data *data)
{
	data->zoom_th1 = 0.5;
	data->movey_th1 = 0;
	data->movex_th1 = 0;
	data->mouse_y = 0;
	data->mouse_x = 0;
	data->iter = 50;
}

void	resetter_th2(t_data *data)
{
	data->zoom_th2 = 0.5;
	data->movey_th2 = 0;
	data->movex_th2 = 0;
	data->mouse_y = 0;
	data->mouse_x = 0;
	data->iter = 50;
}
