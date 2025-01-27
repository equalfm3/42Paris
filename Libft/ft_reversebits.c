/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversebits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:45:21 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:45:23 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reversebits(unsigned char octet)
{
	int				i;
	unsigned char	last;
	unsigned char	reversed;

	i = 0;
	while (i < 7)
	{
		last = octet & 1;
		octet >>= 1;
		reversed = last + reversed;
		reversed <<= 1;
		i++;
	}
	return (reversed);
}
