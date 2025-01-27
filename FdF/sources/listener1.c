/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:49:15 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 00:40:29 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				key_listener(int ky, t_fdf *f)
{
	if (ky == 53)
		fdf_terminator(f);
	else if (ky == 71)
	{
		view_resetter(f);
		fdf_runner(f);
	}
	else if (ky == 36 || ky == 76 || ky == 51 || ky == 48 || ky == 89
		|| ky == 91 || ky == 92 || ky == 86 || ky == 88 || ky == 84 || ky == 82)
		view_switcher(f, ky);
	else if (ky == 126 || ky == 125 || ky == 123 || ky == 124)
		translator(ky, f);
	else if (ky == 27 || ky == 78 || ky == 24 || ky == 69)
		zoom_controller(ky, f);
	else if (ky == 0 || ky == 2 || ky == 13 || ky == 7 || ky == 12 || ky == 14)
		rotator(ky, f);
	else if (ky == 116 || ky == 121)
		amplitude_controller(ky, f);
	else if (ky == 18 || ky == 19 || ky == 20 || ky == 21
		|| ky == 23 || ky == 22)
		color_palette_selector(ky, f);
	else if (ky == 119 || ky == 115)
		fluidity_controller(ky, f);
	return (0);
}

int				view_switcher(t_fdf *f, int key)
{
	if (key == 48)
		f->is_menu_displayed = (f->is_menu_displayed == 1) ? 0 : 1;
	else if (key == 91)
		f->view = (f->view == 5) ? 2 : 5;
	else if (key == 84)
		f->view = (f->view == 6) ? 2 : 6;
	else if (key == 88)
		f->view = (f->view == 7) ? 2 : 7;
	else if (key == 86)
		f->view = (f->view == 8) ? 2 : 8;
	else if (key == 92)
		f->view = (f->view == 9) ? 2 : 9;
	else if (key == 89)
		f->view = (f->view == 10) ? 2 : 10;
	else if (key == 82)
		f->view = (f->view == 11) ? 2 : 11;
	else if (f->view == 0 || f->view == 2)
		f->view = 1;
	else
		f->view = 0;
	fdf_runner(f);
	return (0);
}

int				zoom_controller(int key, t_fdf *f)
{
	if (key == 27 || key == 78)
		(f->zoom > 1) ? f->zoom-- : 0;
	else if (key == 24 || key == 69)
		f->zoom++;
	fdf_runner(f);
	return (0);
}

int				fluidity_controller(int key, t_fdf *f)
{
	if (key == 115 && f->fluidity < 15)
		f->fluidity = f->fluidity + 1;
	else if (key == 119 && f->fluidity > 1)
		f->fluidity = f->fluidity - 1;
	fdf_runner(f);
	return (0);
}

int				rotator(int key, t_fdf *f)
{
	if (key == 13)
		f->alpha -= 2 * f->fluidity;
	else if (key == 7)
		f->alpha += 2 * f->fluidity;
	else if (key == 2)
		f->beta += 2 * f->fluidity;
	else if (key == 0)
		f->beta -= 2 * f->fluidity;
	else if (key == 14)
		f->gamma += 2 * f->fluidity;
	else if (key == 12)
		f->gamma -= 2 * f->fluidity;
	if (f->view == 0)
		f->view = 2;
	else if (f->view == 1)
		f->view = 3;
	fdf_runner(f);
	return (0);
}
