/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:17:47 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/11 20:52:14 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				amplitude_controller(int key, t_fdf *f)
{
	if (key == 121 && f->amplitude > 0.1)
		f->amplitude -= 0.1;
	else if (key == 116 && f->amplitude < 10.0)
		f->amplitude += 0.1;
	fdf_runner(f);
	return (0);
}

int				translator(int key, t_fdf *f)
{
	if (key == 126)
		f->y0 -= 8;
	else if (key == 125)
		f->y0 += 8;
	else if (key == 123)
		f->x0 -= 8;
	else if (key == 124)
		f->x0 += 8;
	fdf_runner(f);
	return (0);
}

static int		color_palette_selector_bis(int key, t_fdf *f)
{
	if (key == 21)
	{
		f->colors[0] = VEGETA1;
		f->colors[1] = VEGETA2;
		f->theme = "VEGETA";
	}
	else if (key == 23)
	{
		f->colors[0] = PICCOLO2;
		f->colors[1] = PICCOLO1;
		f->theme = "PICCOLO";
	}
	else if (key == 22)
	{
		f->colors[0] = BOO1;
		f->colors[1] = BOO2;
		f->theme = "BOO";
	}
	return (0);
}

int				color_palette_selector(int key, t_fdf *f)
{
	if (key == 18)
	{
		f->colors[0] = DARK_GRAY;
		f->colors[1] = WHITE;
		f->theme = "42";
	}
	else if (key == 20)
	{
		f->colors[0] = FRIEZA1;
		f->colors[1] = FRIEZA2;
		f->theme = "FRIEZA";
	}
	else if (key == 19)
	{
		f->colors[0] = GOKU1;
		f->colors[1] = GOKU2;
		f->theme = "GOKU";
	}
	else
		color_palette_selector_bis(key, f);
	fdf_runner(f);
	return (0);
}
