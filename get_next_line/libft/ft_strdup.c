/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:47:09 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:47:11 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	if (!(dup = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
