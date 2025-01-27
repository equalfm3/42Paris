/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapbits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:52:48 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:52:50 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_swapbits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
