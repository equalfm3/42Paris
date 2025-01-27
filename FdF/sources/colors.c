/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:51:01 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 01:38:14 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			grad_computer(int minima, int maxima, double ratio)
{
	int		grad;

	grad = (int)((1 - ratio) * minima + ratio * maxima);
	return (grad);
}

double		ratio_computer(int current, int minima, int maxima)
{
	double		ratio;
	double		range;
	double		diff_value;

	range = maxima - minima;
	diff_value = current - minima;
	ratio = (range == 0) ? 1.0 : (diff_value / range);
	if (ratio < 0.0)
		ratio = 0.0;
	return (ratio);
}

int			pixel_color_computer(struct s_vec v)
{
	double		ratio;
	int			rgb[3];

	if (v.dx > v.dy)
		ratio = ratio_computer(v.x, v.src, v.dst);
	else
		ratio = ratio_computer(v.y, v.src, v.dst);
	rgb[0] = grad_computer((v.src_color >> 16) & 0xFF,
							(v.dst_color >> 16) & 0xFF, ratio);
	rgb[1] = grad_computer((v.src_color >> 8) & 0xFF,
							(v.dst_color >> 8) & 0xFF, ratio);
	rgb[2] = grad_computer(v.src_color & 0xFF, v.dst_color & 0xFF, ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int			vpoint_color_computer(t_fdf *f, int altitude)
{
	int			rgb[3];
	double		ratio;

	ratio = ratio_computer(altitude, f->minima, f->maxima);
	rgb[0] = grad_computer((f->colors[0] >> 16) & 0xFF,
							(f->colors[1] >> 16) & 0xFF, ratio);
	rgb[1] = grad_computer((f->colors[0] >> 8) & 0xFF,
							(f->colors[1] >> 8) & 0xFF, ratio);
	rgb[2] = grad_computer(f->colors[0] & 0xFF, f->colors[1] & 0xFF, ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void		vpoint_color(t_fdf *f)
{
	int			y;
	int			x;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			f->grid[y][x].color = vpoint_color_computer(f, f->grid[y][x].z);
			x++;
		}
		y++;
	}
}
