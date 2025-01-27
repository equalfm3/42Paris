/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:51:47 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 20:20:43 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((ft_isws1(s[start]) == 1) && s[start])
		start++;
	while ((ft_isws1(s[end]) == 1) && s[end] && end > start)
		end--;
	return (ft_strsub(s, start, (unsigned int)(end - start + 1)));
}
