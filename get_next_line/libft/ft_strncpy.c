/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:49:44 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:49:46 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cdst;

	cdst = 0;
	while (cdst < len && src[cdst] != '\0')
	{
		dst[cdst] = src[cdst];
		cdst++;
	}
	while (cdst < len)
	{
		dst[cdst] = '\0';
		cdst++;
	}
	return (dst);
}
