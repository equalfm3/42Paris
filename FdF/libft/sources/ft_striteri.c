/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:47:46 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:47:47 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	cs;

	cs = 0;
	if (f && s)
	{
		while (*s)
			f(cs++, s++);
	}
}
