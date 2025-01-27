/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:30:54 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 22:43:09 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_initiator(void)
{
	t_fdf	*f;

	if (!(f = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		return (NULL);
	f->h = 0;
	f->w = 0;
	f->grid = NULL;
	f->img = NULL;
	f->imgvec = NULL;
	f->mlx = NULL;
	f->win = NULL;
	f->maxima = 0;
	f->minima = 0;
	f->is_menu_displayed = 1;
	f->fluidity = 1;
	return (f);
}

void	fdf_runner(t_fdf *f)
{
	ft_bzero(f->imgvec, WIN_W * WIN_H * sizeof(int));
	mlx_clear_window(f->mlx, f->win);
	iso_par_selector(f);
	grid_drawer(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	if (f->is_menu_displayed == 1)
	{
		keys_displayer(f);
		info_displayer(f);
		themes_displayer(f);
	}
}

void	mlx_runner(t_fdf *f)
{
	int		temp[3];

	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "DBZ THEMED - FDF");
	f->img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	f->imgvec = (int *)mlx_get_data_addr(f->img, &temp[0], &temp[1], &temp[2]);
	view_resetter(f);
	fdf_runner(f);
	mlx_hook(f->win, 17, 0, fdf_terminator, f);
	mlx_hook(f->win, 2, 0, key_listener, f);
	mlx_loop_hook(f->mlx, rotation_selector, f);
	mlx_loop(f->mlx);
}

int		main(int argc, char const **argv)
{
	t_fdf	*f;
	char	*file;

	if (argc != 2)
	{
		ft_putendl("---> USAGE: ./fdf <file>");
		exit(0);
	}
	f = fdf_initiator();
	file = file_reader(argv[1], LIMITER);
	if (file == NULL)
		error_displayer("---> ERROR: READ FAILURE!");
	f->h = grid_height_fetcher(file);
	f->w = grid_width_fetcher(file);
	if (!f->h || !f->w)
		error_displayer("---> ERROR: GRID VALIDATION FAILURE!");
	if (!grid_creator(f))
		error_displayer("---> ERROR: GRID CREATION FAILURE!");
	if (!checker(f, file))
		error_displayer("---> ERROR: GRID VALIDATION FAILURE!");
	ft_memdel((void **)&file);
	mlx_runner(f);
	return (0);
}
