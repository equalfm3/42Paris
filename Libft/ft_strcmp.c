/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:46:27 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:46:30 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *bcks1;
	unsigned char *bcks2;

	bcks1 = (unsigned char *)s1;
	bcks2 = (unsigned char *)s2;
	while (*bcks1 && (*bcks1 == *bcks2))
	{
		bcks1++;
		bcks2++;
	}
	return (*bcks1 - *bcks2);
}
