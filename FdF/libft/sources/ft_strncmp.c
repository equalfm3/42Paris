/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:49:34 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:49:35 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*bcks1;
	unsigned char	*bcks2;

	i = 1;
	bcks1 = (unsigned char*)s1;
	bcks2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*bcks1 && *bcks1 == *bcks2 && i < n)
	{
		i++;
		bcks1++;
		bcks2++;
	}
	return (*bcks1 - *bcks2);
}
