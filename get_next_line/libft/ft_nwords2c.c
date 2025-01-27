/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwords2c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:30 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/10 19:42:32 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_nwords2c(char *s, char c)
{
	int		i;
	int		isword;

	i = 0;
	isword = 0;
	while (*s)
	{
		if (isword == 0 && *s != c)
		{
			isword = 1;
			i++;
		}
		else if (isword == 1 && *s == c)
			isword = 0;
		s++;
	}
	return (i);
}
