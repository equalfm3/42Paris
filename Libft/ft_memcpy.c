/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:41:18 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:41:20 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*bckdst;
	unsigned char	*bcksrc;

	bckdst = (unsigned char*)dst;
	bcksrc = (unsigned char*)src;
	while (n)
	{
		*bckdst = *bcksrc;
		bcksrc++;
		bckdst++;
		n--;
	}
	return (dst);
}
