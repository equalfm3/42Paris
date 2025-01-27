/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:51:38 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:51:40 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		cs;
	char	*p;

	cs = 0;
	if (!s || !(p = ft_strnew(len)))
		return (NULL);
	while (len-- && s[start] != '\0')
	{
		p[cs] = s[start];
		cs++;
		start++;
	}
	p[cs] = '\0';
	return (p);
}
