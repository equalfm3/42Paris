/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:40:27 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:40:29 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*bckdst;
	unsigned char	*bcksrc;

	bckdst = (unsigned char *)dst;
	bcksrc = (unsigned char *)src;
	while (n)
	{
		*bckdst = *bcksrc;
		if (*bckdst == (unsigned char)c)
			return (++bckdst);
		bckdst++;
		bcksrc++;
		n--;
	}
	return (NULL);
}
