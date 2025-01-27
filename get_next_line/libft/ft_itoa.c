/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:36:50 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:37:06 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int num)
{
	char		*res;
	int			count;
	int			i;
	long int	n;

	n = num;
	count = ft_ndigits(n);
	i = 0;
	if (n < 0 || count == 0)
		count++;
	if (!(res = ft_strnew(count)))
		return (NULL);
	if (n < 0)
	{
		n = ft_abs(n);
		res[0] = '-';
		i++;
	}
	while (count > i)
	{
		count--;
		res[count] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
