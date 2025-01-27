/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:50:34 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:50:35 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*first;
	char	*last;
	char	temp;
	char	*result;

	first = str;
	last = str;
	result = str;
	while (*last != '\0')
		last++;
	last--;
	while (first < last)
	{
		temp = *first;
		*first = *last;
		*last = temp;
		first++;
		last--;
	}
	return (result);
}
