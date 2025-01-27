/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 18:56:54 by esuslova          #+#    #+#             */
/*   Updated: 2019/04/28 23:32:07 by esuslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_board_size(int nb)
{
	int		sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		sqrt++;
	return ((sqrt * sqrt == nb) ? 2 * sqrt : 2 * --sqrt);
}

void	ft_board_display(char **board)
{
	int	i;

	i = 0;
	while (board[i] != NULL)
	{
		ft_putendl(board[i]);
		i++;
	}
}

char	**ft_board_create(int nb)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(board = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	board[nb] = NULL;
	while (i < nb)
	{
		if (!(board[i] = (char *)malloc(sizeof(char) * (nb + 1))))
			return (NULL);
		board[i][nb] = '\0';
		i++;
	}
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
			board[i][j++] = '.';
		i++;
	}
	return (board);
}

void	ft_board_free(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		board[i] = NULL;
		i++;
	}
	free(board);
	board = NULL;
}
