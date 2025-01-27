/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:46:43 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:46:44 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*bckdst;

	bckdst = dst;
	while (*src != '\0')
	{
		*bckdst = *src;
		bckdst++;
		src++;
	}
	*bckdst = '\0';
	return (dst);
}
