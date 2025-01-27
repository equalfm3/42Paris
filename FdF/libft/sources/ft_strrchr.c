/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:50:24 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:50:26 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int	cs;

	cs = ft_strlen(s);
	while (cs >= 0)
	{
		if (s[cs] == (char)c)
			return (cs + (char*)s);
		cs--;
	}
	return (NULL);
}
