/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:40:17 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:40:19 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	if (!(memory = (void *)malloc(size * sizeof(*memory))))
		return (NULL);
	else
	{
		ft_bzero(memory, size);
		return (memory);
	}
}
