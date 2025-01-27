/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:51:21 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:51:23 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		nwords;
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	nwords = ft_nwords2c((char *)s, c);
	if (!(split = (char **)malloc((nwords + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (nwords--)
	{
		while (*s == c && *s != '\0')
			s++;
		split[i] = ft_strsub((char *)s, 0, ft_strlen2c((char *)s, c));
		if (!split[i])
			return (NULL);
		s = s + ft_strlen2c((char *)s, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
