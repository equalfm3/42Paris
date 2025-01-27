/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:40:05 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:40:06 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*to_create;

	if (!(to_create = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		to_create->content_size = 0;
		to_create->content = NULL;
	}
	else
	{
		if (!(to_create->content = malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(to_create->content, content, content_size);
		to_create->content_size = content_size;
	}
	to_create->next = NULL;
	return (to_create);
}
