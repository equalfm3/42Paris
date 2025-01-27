/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:47:58 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:47:59 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2 || !(p = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	p = ft_strcat(ft_strcpy(p, s1), s2);
	return (p);
}
