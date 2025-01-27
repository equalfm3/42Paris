/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:00:57 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:05:08 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	while (*str && ft_isws2(*str) == 1)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str) == 1)
	{
		nbr = nbr * 10;
		nbr = *str - '0' + nbr;
		str++;
	}
	return (sign * nbr);
}
