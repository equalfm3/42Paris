/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:45:55 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:45:57 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char			*ptr;
	unsigned char	*bcks2;

	ptr = s1 + ft_strlen(s1);
	bcks2 = (unsigned char*)s2;
	while (*bcks2)
	{
		*ptr = *bcks2;
		ptr++;
		bcks2++;
	}
	*ptr = '\0';
	return (s1);
}
