/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:23:49 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 00:10:16 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				rotation_selector(t_fdf *f)
{
	if (f->view == 6)
		f->alpha++;
	if (f->view == 5)
		f->alpha--;
	if (f->view == 7)
		f->beta++;
	if (f->view == 8)
		f->beta--;
	if (f->view == 9)
		f->gamma++;
	if (f->view == 10)
		f->gamma--;
	if (f->view == 11)
	{
		f->alpha = f->alpha + 1;
		f->beta = f->beta + 2;
		f->gamma = f->gamma + 3;
	}
	usleep(1);
	fdf_runner(f);
	return (0);
}

void			iso_par_selector(t_fdf *f)
{
	vpoint_color(f);
	if (f->view == 0)
	{
		f->alpha = -30;
		f->beta = -30;
		f->gamma = 30;
	}
	else if (f->view == 1)
	{
		f->alpha = 0;
		f->beta = 0;
		f->gamma = 0;
	}
	grid_rotator(f);
}

void			view_resetter(t_fdf *f)
{
	f->x0 = WIN_W / 2;
	f->y0 = WIN_H / 2;
	if (f->w > f->h)
		f->zoom = WIN_W / 2 / f->w;
	else
		f->zoom = WIN_H / 2 / f->h;
	if (f->zoom < 1)
		f->zoom = 1;
	f->amplitude = 0.1;
	f->view = 0;
	f->colors[0] = DARK_GRAY;
	f->colors[1] = WHITE;
	f->theme = "42";
	f->fluidity = 1;
}
