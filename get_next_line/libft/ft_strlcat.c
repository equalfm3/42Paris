/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:48:40 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:48:42 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cd;
	size_t	cs;
	size_t	lcat;

	cd = 0;
	while (dst[cd] != '\0')
		++cd;
	lcat = 0;
	while (src[lcat] != '\0')
		++lcat;
	if (size <= cd)
		lcat += size;
	else
		lcat += cd;
	cs = 0;
	while (src[cs] != '\0' && cd + 1 < size)
	{
		dst[cd] = src[cs];
		cd++;
		cs++;
	}
	dst[cd] = '\0';
	return (lcat);
}
