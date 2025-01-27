/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:49:01 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:49:03 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	c;
	char	*p;

	if (!s || !(p = ft_strnew(ft_strlen(s))))
		return (NULL);
	c = 0;
	if (f && s)
	{
		while (s[c] != '\0')
		{
			p[c] = f(s[c]);
			c++;
		}
	}
	p[c] = '\0';
	return (p);
}
