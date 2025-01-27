/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:13:21 by mofikrat          #+#    #+#             */
/*   Updated: 2019/11/24 19:13:42 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(void *content, size_t size)
{
	if (content && size)
	{
		ft_bzero(content, size);
		free(content);
		content = NULL;
	}
}
