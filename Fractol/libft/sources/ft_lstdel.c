/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:37:41 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:37:43 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*vase;
	t_list	*p;

	p = *alst;
	while (p)
	{
		vase = p;
		ft_lstdelone(&p, del);
		p = vase->next;
	}
	*alst = NULL;
}
