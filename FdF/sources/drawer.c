/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:18:22 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 00:46:12 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel_drawer(t_fdf *f, struct s_vec v)
{
	int		i;

	if (v.x > 0 && v.x < WIN_W && v.y > 0 && v.y < WIN_H)
	{
		i = v.y * WIN_W + v.x;
		f->imgvec[i] = pixel_color_computer(v);
	}
}

void	vl_drawer(t_fdf *f, struct s_vpt src, struct s_vpt dst, struct s_vec v)
{
	v.dx = dst.x - src.x;
	v.dy = dst.y - src.y;
	v.yi = 1;
	if (v.dy < 0)
	{
		v.yi = -1;
		v.dy = -v.dy;
	}
	v.deriv = 2 * v.dy - v.dx;
	v.y = src.y;
	v.x = src.x;
	while (v.x <= dst.x)
	{
		pixel_drawer(f, v);
		if (v.deriv > 0)
		{
			v.y = v.y + v.yi;
			v.deriv = v.deriv - 2 * v.dx;
		}
		v.deriv = v.deriv + 2 * v.dy;
		v.x++;
	}
}

void	vh_drawer(t_fdf *f, struct s_vpt src, struct s_vpt dst, struct s_vec v)
{
	v.dx = dst.x - src.x;
	v.dy = dst.y - src.y;
	v.xi = 1;
	if (v.dx < 0)
	{
		v.xi = -1;
		v.dx = -v.dx;
	}
	v.deriv = 2 * v.dx - v.dy;
	v.x = src.x;
	v.y = src.y;
	while (v.y <= dst.y)
	{
		pixel_drawer(f, v);
		if (v.deriv > 0)
		{
			v.x += v.xi;
			v.deriv = v.deriv - 2 * v.dy;
		}
		v.deriv = v.deriv + 2 * v.dx;
		v.y++;
	}
}

void	line_drawer(t_fdf *f, struct s_vpt src, struct s_vpt dst)
{
	struct s_vec	v;

	v.src_color = src.color;
	v.dst_color = dst.color;
	if (abs(dst.x - src.x) > abs(dst.y - src.y))
	{
		v.src = src.x;
		v.dst = dst.x;
		if (src.x > dst.x)
			vl_drawer(f, dst, src, v);
		else
			vl_drawer(f, src, dst, v);
	}
	else
	{
		v.src = src.y;
		v.dst = dst.y;
		if (src.y > dst.y)
			vh_drawer(f, dst, src, v);
		else
			vh_drawer(f, src, dst, v);
	}
}

void	grid_drawer(t_fdf *f)
{
	int		x;
	int		y;

	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			if (y + 1 < f->h)
				line_drawer(f, f->grid[y][x], f->grid[y + 1][x]);
			if (x + 1 < f->w)
				line_drawer(f, f->grid[y][x], f->grid[y][x + 1]);
			x++;
		}
		y++;
	}
}
