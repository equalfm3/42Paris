/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:50:15 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:50:17 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hsk, const char *ndl, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*ndl)
		return ((char*)hsk);
	pos = 0;
	while (hsk[pos] != '\0' && (size_t)pos < len)
	{
		if (hsk[pos] == ndl[0])
		{
			i = 1;
			while (ndl[i] != '\0' && hsk[pos + i] == ndl[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (ndl[i] == '\0')
				return ((char*)&hsk[pos]);
		}
		++pos;
	}
	return (0);
}
