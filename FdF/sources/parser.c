/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:20:50 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 22:43:09 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				grid_creator(t_fdf *f)
{
	int		y;

	if (!(f->grid = (t_vpt **)ft_memalloc(sizeof(t_vpt *) * f->h + 1)))
		return (0);
	y = 0;
	while (y < f->h)
	{
		if (!(f->grid[y] = (t_vpt *)ft_memalloc(sizeof(t_vpt) * f->w)))
			return (0);
		y++;
	}
	f->grid[y] = NULL;
	return (1);
}

int				grid_width_fetcher(char *file)
{
	int		w;
	int		i;

	w = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '0' && file[i + 1] == 'x')
			hex_checker(file, &i);
		if (ft_isdigit(file[i]))
		{
			w++;
			while (ft_isdigit(file[i]))
				i++;
		}
		if (!file[i] || file[i] == '\n')
			break ;
		i++;
	}
	return (w);
}

int				grid_height_fetcher(char *file)
{
	int	h;
	int	i;

	h = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			h++;
		i++;
	}
	if (i != 0 && file[i] == '\0' && file[i - 1] != '\n')
		h++;
	return (h);
}

char			*file_reader(const char *argv, int no_inf_loop)
{
	int		fd;
	char	*file;
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	if ((fd = open(argv, O_RDONLY)) < 0)
		error_displayer("---> ERROR: FILE OPEN FAILURE!");
	file = ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) && no_inf_loop > 0)
	{
		if (ret < 0)
			error_displayer("---> ERROR: FILE READ FAILURE!");
		buffer[ret] = '\0';
		tmp = ft_strjoin(file, buffer);
		ft_memdel((void **)&file);
		file = tmp;
		no_inf_loop--;
	}
	close(fd);
	return (file);
}
