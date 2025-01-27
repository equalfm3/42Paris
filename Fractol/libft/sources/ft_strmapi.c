/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:49:13 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:49:15 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	c;
	char			*p;

	if (!s || !(p = ft_strnew(ft_strlen(s))))
		return (NULL);
	c = 0;
	if (f && s)
	{
		while (s[c] != '\0')
		{
			p[c] = f(c, s[c]);
			c++;
		}
	}
	p[c] = '\0';
	return (p);
}
