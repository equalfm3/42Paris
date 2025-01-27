/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:22:46 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 00:27:10 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			error_displayer(char *error)
{
	ft_putendl(error);
	exit(1);
}

int				hex_checker(char *file, int *i)
{
	int		j;
	int		k;

	j = *i + 2;
	k = 0;
	while (file[j] && ((file[j] >= '0' && file[j] <= '9') ||
			(file[j] >= 'A' && file[j] <= 'F') ||
			(file[j] >= 'a' && file[j] <= 'f')))
	{
		j++;
		k++;
	}
	if (k == 6 || k == 4 || k == 2)
	{
		*i += k + 2;
		return (1);
	}
	return (0);
}

void			limits_checker(char *file, int i)
{
	int			j;
	char		*altitude;
	static char	*intmax = "2147483647";
	static char	*intmin = "-2147483648";

	j = i;
	while (ft_isdigit(file[i]) || file[i] == '-')
		i++;
	altitude = ft_strsub(file, j, i - j);
	if ((altitude[0] != '-' && ft_strlen(altitude) > 10) ||
	(altitude[0] == '-' && ft_strlen(altitude) > 11))
		error_displayer("ERROR: ALTITUDE MUST BE AN INT!");
	if ((altitude[0] != '-' && ft_strlen(altitude) == 10) ||
		(altitude[0] == '-' && ft_strlen(altitude) == 11))
	{
		if ((altitude[0] != '-') && (ft_strcmp(altitude, intmax) > 0))
			error_displayer("ERROR: ALTITUDE MUST BE AN INT!");
		if ((altitude[0] == '-') && (ft_strcmp(altitude, intmin) > 0))
			error_displayer("ERROR: ALTITUDE MUST BE AN INT!");
	}
	ft_strdel(&altitude);
}

int				altitude_checker(t_fdf *f, int *z_xy, char *file)
{
	if (z_xy[1] >= f->w)
		return (0);
	limits_checker(file, z_xy[0]);
	f->grid[z_xy[2]][z_xy[1]].z = ft_atoi(&file[z_xy[0]]);
	if (f->grid[z_xy[2]][z_xy[1]].z > f->maxima)
		f->maxima = f->grid[z_xy[2]][z_xy[1]].z;
	else if (f->grid[z_xy[2]][z_xy[1]].z < f->minima)
		f->minima = f->grid[z_xy[2]][z_xy[1]].z;
	z_xy[1]++;
	while (file[z_xy[0]] && (file[z_xy[0]] == '-' || ft_isdigit(file[z_xy[0]])))
		z_xy[0]++;
	return (1);
}

int				checker(t_fdf *f, char *file)
{
	static int		z_xy[3] = {0, 0, 0};

	while (file[z_xy[0]])
	{
		if (file[z_xy[0]] == '0' && file[z_xy[0] + 1] == 'x')
			hex_checker(file, &z_xy[0]);
		if (file[z_xy[0]] == '-' || ft_isdigit(file[z_xy[0]]))
		{
			if (!altitude_checker(f, z_xy, file))
				return (0);
		}
		if (!file[z_xy[0]] || file[z_xy[0]] == '\n')
		{
			if (z_xy[1] != f->w)
				return (0);
			z_xy[2]++;
			z_xy[1] = 0;
		}
		(file[z_xy[0]]) ? z_xy[0]++ : 0;
	}
	if (z_xy[2] != f->h)
		return (0);
	return (1);
}
