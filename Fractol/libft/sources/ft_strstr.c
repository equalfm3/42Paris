/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:51:29 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:51:31 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hsk, const char *ndl)
{
	size_t	nsize;

	if (*ndl == '\0')
		return ((char *)hsk);
	nsize = ft_strlen(ndl);
	while (*hsk)
	{
		if (ft_strncmp(hsk, ndl, nsize) == 0)
			return ((char *)hsk);
		hsk++;
	}
	return (NULL);
}
