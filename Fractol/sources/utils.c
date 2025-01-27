/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:33:59 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:26:09 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_exit(void)
{
	exit(1);
}

double		min_double(double d1, double d2)
{
	if (d1 < d2)
		return (d1);
	else
		return (d2);
}
