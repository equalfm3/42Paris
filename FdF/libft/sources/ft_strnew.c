/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:50:06 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:50:08 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(newstr, size + 1);
	return (newstr);
}
