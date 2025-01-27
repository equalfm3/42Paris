/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:32:03 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:12:54 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		new_ri(t_data *data, int xy, int i, double movexy)
{
	double e;

	if (i == 1)
		e = 1.5 * (xy - W_WIDTH / 2) / (0.5 *
			*data->zoom * W_WIDTH) + movexy + ((*data->fractol >= 3 &&
				*data->fractol <= 6) ? -0.5 : 0);
	else
	{
		e = (xy - W_HEIGHT / 2) / (0.5 *
				*data->zoom * W_HEIGHT) + movexy;
	}
	return (e);
}

void		pos_initiator(t_data *data, t_thread **thread, int **img, int ntr)
{
	int			wd;

	wd = W_WIDTH / ntr;
	(*thread) = (t_thread*)malloc(sizeof(t_thread));
	(*thread)->start_y = 0;
	(*thread)->start_x = wd * (ntr - 1);
	(*thread)->end_y = W_HEIGHT;
	(*thread)->end_x = wd * ntr;
	(*thread)->img = &(*img);
	(*thread)->data = data;
	(*thread)->next = NULL;
}

void		pos_data_setter(t_data *data, t_thread *tmp, int **img, int x)
{
	int			wd;

	wd = W_WIDTH / 4;
	tmp->next = (t_thread*)malloc(sizeof(t_thread));
	tmp->next->start_y = 0;
	tmp->next->start_x = wd * (x - 1);
	tmp->next->end_y = W_HEIGHT;
	tmp->next->end_x = wd * x;
	tmp->next->img = &(*img);
	tmp->next->data = data;
	tmp->next->next = NULL;
}

void		thread_creator(void (*fractal), t_data *data, t_thread *tr)
{
	pthread_create(&(*data).thread[0].thread, NULL,
		fractal, &(tr));
	pthread_create(&(*data).thread[1].thread, NULL,
		fractal, &(tr)->next);
	pthread_create(&(*data).thread[2].thread, NULL,
		fractal, &(tr)->next->next);
	pthread_create(&(*data).thread[3].thread, NULL,
		fractal, &(tr)->next->next->next);
	pthread_join((*data).thread[0].thread, NULL);
	pthread_join((*data).thread[1].thread, NULL);
	pthread_join((*data).thread[2].thread, NULL);
	pthread_join((*data).thread[3].thread, NULL);
	merge_all(&(*data), &*tr);
}

void		main_cycle(t_thread **tr)
{
	int				i[3];
	t_fractals		it;

	it.cre = -0.7 + (*tr)->data->mouse_x;
	it.cim = 0.27015 + (*tr)->data->mouse_y;
	i[0] = (*tr)->start_y - 1;
	while (++i[0] < (*tr)->end_y)
	{
		i[1] = (*tr)->start_x - 1;
		while (++i[1] < (*tr)->end_x)
		{
			it.re = new_ri(&*(*tr)->data, i[1], 1, *(*tr)->data->mx);
			it.im = new_ri(&*(*tr)->data, i[0], 2, *(*tr)->data->my);
			if (*(*tr)->data->fractol == 1 || *(*tr)->data->fractol == 2)
				i[2] = julia_definer(&*(*tr)->data, &it, 0);
			if (*(*tr)->data->fractol == 3 || *(*tr)->data->fractol == 4)
				i[2] = mandelbrot_definer(&*(*tr)->data, &it, 0);
			if (*(*tr)->data->fractol == 5 || *(*tr)->data->fractol == 6)
				i[2] = burningship_definer(&*(*tr)->data, &it, 0);
			if (*(*tr)->data->fractol >= 7 && *(*tr)->data->fractol <= 9)
				i[2] = newton_definer(&*(*tr)->data, &it, 0);
			*(*(*tr)->img + ((i[1]) + (i[0] * ((W_WIDTH - W_HEIGHT) +
			W_HEIGHT)))) = i[2];
		}
	}
}
