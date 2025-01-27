/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:47:07 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/11 23:59:19 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			fdf_terminator(t_fdf *f)
{
	grid_cleaner(f);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_image(f->mlx, f->img);
	free(f);
	exit(0);
	return (0);
}

void		grid_cleaner(t_fdf *f)
{
	int		y;

	y = 0;
	while (y < f->h)
		free(f->grid[y++]);
	free(f->grid[y]);
	free(f->grid);
}
