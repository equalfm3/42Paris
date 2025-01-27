/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:15:38 by mofikrat          #+#    #+#             */
/*   Updated: 2019/11/24 19:15:47 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *addr)
{
	int		count;

	if (addr == NULL)
		return (0);
	count = 0;
	while (addr != NULL)
	{
		count++;
		addr = addr->next;
	}
	return (count);
}
