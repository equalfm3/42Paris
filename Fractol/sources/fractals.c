/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:29:44 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:08:16 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mandelbrot_definer(t_data *data, t_fractals *fr, int i)
{
	fr->cim = fr->im;
	fr->cre = fr->re;
	fr->re = 0;
	fr->oldim = 0;
	fr->oldre = 0;
	fr->im = 0;
	while (i < data->iter)
	{
		fr->oldre = fr->re;
		fr->oldim = fr->im;
		fr->re = fr->oldre * fr->oldre - fr->oldim * fr->oldim + fr->cre;
		fr->im = 2 * fr->oldre * fr->oldim + fr->cim;
		i++;
		if (*data->fractol == 4)
		{
			if ((fr->re * fr->re * fr->im * fr->im) >= 4)
				break ;
		}
		else
		{
			if ((fr->re * fr->re + fr->im * fr->im) > 4)
				break ;
		}
	}
	return ((i < data->iter) ? color_getter(i, (*data)) : 0x000000);
}

int			burningship_definer(t_data *data, t_fractals *fr, int i)
{
	fr->cim = fr->im;
	fr->cre = fr->re;
	fr->re = 0;
	fr->oldim = 0;
	fr->oldre = 0;
	fr->im = 0;
	while (i < data->iter)
	{
		fr->oldre = fabs(fr->re);
		fr->oldim = fabs(fr->im);
		fr->re = fr->oldre * fr->oldre - fr->oldim * fr->oldim + fr->cre;
		fr->im = 2 * fr->oldre * fr->oldim + fr->cim;
		i++;
		if (*data->fractol == 6)
		{
			if ((fr->re * fr->re * fr->im * fr->im) >= 4)
				break ;
		}
		else
		{
			if ((fr->re * fr->re + fr->im * fr->im) > 4)
				break ;
		}
	}
	return ((i < data->iter) ? color_getter(i, (*data)) : 0x000000);
}

int			julia_definer(t_data *data, t_fractals *fr, int i)
{
	while (i < data->iter)
	{
		fr->oldre = fr->re;
		fr->oldim = fr->im;
		fr->re = fr->oldre * fr->oldre - fr->oldim * fr->oldim + fr->cre;
		fr->im = 2 * fr->oldre * fr->oldim + fr->cim;
		i++;
		if (*data->fractol == 2)
		{
			if ((fr->re * fr->re * fr->im * fr->im) >= 4)
				break ;
		}
		else
		{
			if ((fr->re * fr->re + fr->im * fr->im) >= 4)
				break ;
		}
	}
	return ((i < data->iter) ? color_getter(i, (*data)) : 0x000000);
}

int			newton_definer(t_data *data, t_fractals *fr, int i)
{
	_Complex double	z;
	_Complex double	r[3];

	z = fr->im + fr->re * I;
	r[0] = 1 + 0 * I;
	r[1] = -0.5 + sin(2 * M_PI / 3) * I;
	r[2] = -0.5 - sin(2 * M_PI / 3) * I;
	while (i < data->iter)
	{
		if (min_double(cabs((z - r[0])),
				min_double(cabs((z - r[1])), cabs((z - r[2])))) < 0.001)
			break ;
		i++;
		z = z - (z * z * z - 1.0) / (z * z * 3.0);
		if (*data->fractol == 8)
			z = z - (z * z * z - 1.0) / (z * z + 19);
		if (*data->fractol == 9)
			z = z - (z * z * z - 1.0) / (z * z * i / 3.0);
	}
	return (color_rgba_iter(i, (int)cabs(z - r[0]),
			(int)cabs(z - r[1]), (int)cabs(z - r[2])));
}

void		fractal_processer(t_data *data, t_thread **thread, int **img)
{
	int			x;
	int			ntr;
	t_thread	*tmp;

	ntr = 4;
	x = ntr + 1;
	while (--x)
	{
		if (x == ntr)
			pos_initiator(&*data, &(*thread), &*img, x);
		else
		{
			tmp = (*thread);
			while (tmp->next)
				tmp = tmp->next;
			pos_data_setter(&*data, &*tmp, &*img, x);
		}
	}
}
