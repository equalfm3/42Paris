/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:40:40 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:40:42 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *bcks;

	bcks = (unsigned char*)s;
	while (n)
	{
		if (*bcks == (unsigned char)c)
			return (bcks);
		n--;
		bcks++;
	}
	return (NULL);
}
