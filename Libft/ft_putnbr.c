/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:44:01 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:44:03 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putchar('-');
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		else
		{
			ft_putchar('-');
			nb = -nb;
		}
	}
	if (nb / 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
