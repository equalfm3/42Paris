/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:20:21 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 00:51:19 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			x_rotator(t_fdf *f, int *y, double *z)
{
	double		old_y;
	double		new_y;

	old_y = *y;
	new_y = old_y * cos(PI / 180 * f->alpha) + *z * sin(PI / 180 * f->alpha);
	*z = -old_y * sin(PI / 180 * f->alpha) + *z * cos(PI / 180 * f->alpha);
	*y = new_y;
}

void			y_rotator(t_fdf *f, int *x, double *z)
{
	double		old_x;
	double		new_x;

	old_x = *x;
	new_x = old_x * cos(PI / 180 * f->beta) + *z * sin(PI / 180 * f->beta);
	*z = -old_x * sin(PI / 180 * f->beta) + *z * cos(PI / 180 * f->beta);
	*x = new_x;
}

void			z_rotator(t_fdf *f, int *x, int *y)
{
	double		old_x;
	double		old_y;
	double		new_x;
	double		new_y;

	old_x = *x;
	old_y = *y;
	new_x = old_x * cos(PI / 180 * f->gamma) - old_y * sin(PI / 180 * f->gamma);
	new_y = old_x * sin(PI / 180 * f->gamma) + old_y * cos(PI / 180 * f->gamma);
	*x = new_x;
	*y = new_y;
}

void			grid_rotator(t_fdf *f)
{
	int		y;
	int		x;
	double	tmp_altitude;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			f->grid[y][x].x = (x - f->w / 2) * f->zoom;
			f->grid[y][x].y = (y - f->h / 2) * f->zoom;
			tmp_altitude = f->grid[y][x].z * f->zoom * f->amplitude;
			x_rotator(f, &f->grid[y][x].y, &tmp_altitude);
			y_rotator(f, &f->grid[y][x].x, &tmp_altitude);
			z_rotator(f, &f->grid[y][x].x, &f->grid[y][x].y);
			f->grid[y][x].x += f->x0;
			f->grid[y][x].y += f->y0;
			x++;
		}
		y++;
	}
}
