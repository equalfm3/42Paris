/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:29:26 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 16:34:08 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			color_getter(unsigned int i, t_data data)
{
	unsigned int color;
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int a;

	r = (i * data.t_rgb.r) % 255;
	g = (i * data.t_rgb.g) % 255;
	b = (i * data.t_rgb.b) % 255;
	a = (i * i) % 255;
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

int			color_rgba(unsigned int a, unsigned int r,
	unsigned int g, unsigned int b)
{
	unsigned int color;

	r = (r) % 255;
	g = (g) % 255;
	b = (b) % 255;
	a = (a) % 255;
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

int			color_rgba_iter(unsigned int i, int r, int g, int b)
{
	unsigned int color;
	unsigned int a;

	r = ((r * i) * 10) % 255;
	g = ((g * i) * 10) % 255;
	b = ((b * i) * 10) % 255;
	a = (i * 2) % 255;
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}
