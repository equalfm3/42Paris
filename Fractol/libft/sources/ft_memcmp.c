/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:41:06 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:41:08 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bcks1;
	unsigned char	*bcks2;

	bcks1 = (unsigned char*)s1;
	bcks2 = (unsigned char*)s2;
	while (n--)
	{
		if (*bcks1 != *bcks2)
			return (*bcks1 - *bcks2);
		bcks1++;
		bcks2++;
	}
	return (0);
}
