/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortinttab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:45:46 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:45:48 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortinttab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i <= size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
