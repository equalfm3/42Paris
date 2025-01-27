/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:02:48 by esuslova          #+#    #+#             */
/*   Updated: 2019/05/03 10:57:05 by esuslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetri_delete(char **board, int size, t_shapes tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i][j] == tetri.alpha)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_tetri_read(t_shapes **tetri, char *buff, int fd, char alphac)
{
	int		readres;
	int		readreslast;

	while ((readres = read(fd, buff, 21)) >= 0 && tetri != NULL)
	{
		if ((readres && alphac > 'Z') || (readres == 0 && readreslast == 21))
			return (-1);
		else if (readres == 0 && readreslast != 21)
		{
			*tetri = NULL;
			return (1);
		}
		if (!(*tetri = (t_shapes *)malloc(sizeof(t_shapes))))
			return (-1);
		if (ft_chartotetri(buff, *tetri) == 0)
			return (-1);
		ft_abstorelative((ft_firstpiece(buff)), *tetri);
		(**tetri).alpha = alphac++;
		if (ft_neighbors(**tetri) != 3 && ft_neighbors(**tetri) != 4)
			return (-1);
		tetri++;
		ft_bzero(buff, 22);
		readreslast = readres;
	}
	return (readres);
}

void	ft_tetri_free(t_shapes **tetri)
{
	int	i;

	i = 0;
	while (tetri[i])
	{
		free(tetri[i]);
		tetri[i] = NULL;
		i++;
	}
	free(tetri);
	tetri = NULL;
}

int		ft_tetri_count(t_shapes **tetri)
{
	int	i;

	i = 0;
	while (tetri[i])
		i++;
	return (i);
}
