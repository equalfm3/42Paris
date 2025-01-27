/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:41:49 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:41:50 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*vase;

	vase = ft_strnew(len);
	if (vase)
	{
		ft_memcpy(vase, src, len);
		ft_memcpy(dst, vase, len);
	}
	free(vase);
	return (dst);
}
