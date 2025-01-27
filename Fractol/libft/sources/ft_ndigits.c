/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:16 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:42:20 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ndigits(int nbr)
{
	int	size;

	size = 0;
	nbr = ft_abs(nbr);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}
