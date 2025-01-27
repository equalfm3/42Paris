/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkspart2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:10:17 by esuslova          #+#    #+#             */
/*   Updated: 2019/04/28 20:57:27 by esuslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_neighborscheck4(t_shapes tetri)
{
	return ((tetri.t1.x == tetri.t3.x + 1 && tetri.t1.y == tetri.t3.y)
			|| (tetri.t1.x == tetri.t3.x - 1 && tetri.t1.y == tetri.t3.y)
			|| (tetri.t1.y == tetri.t3.y - 1 && tetri.t1.x == tetri.t3.x)
			|| (tetri.t1.y == tetri.t3.y + 1 && tetri.t1.x == tetri.t3.x));
}

int		ft_neighborscheck5(t_shapes tetri)
{
	return ((tetri.t1.x == tetri.t4.x + 1 && tetri.t1.y == tetri.t4.y)
			|| (tetri.t1.x == tetri.t4.x - 1 && tetri.t1.y == tetri.t4.y)
			|| (tetri.t1.y == tetri.t4.y - 1 && tetri.t1.x == tetri.t4.x)
			|| (tetri.t1.y == tetri.t4.y + 1 && tetri.t1.x == tetri.t4.x));
}

int		ft_neighborscheck6(t_shapes tetri)
{
	return ((tetri.t4.x == tetri.t2.x + 1 && tetri.t4.y == tetri.t2.y)
			|| (tetri.t4.x == tetri.t2.x - 1 && tetri.t4.y == tetri.t2.y)
			|| (tetri.t4.y == tetri.t2.y - 1 && tetri.t4.x == tetri.t2.x)
			|| (tetri.t4.y == tetri.t2.y + 1 && tetri.t4.x == tetri.t2.x));
}

int		ft_neighbors(t_shapes tetri)
{
	return (ft_neighborscheck1(tetri) + ft_neighborscheck2(tetri)
			+ ft_neighborscheck3(tetri) + ft_neighborscheck4(tetri)
			+ ft_neighborscheck5(tetri) + ft_neighborscheck6(tetri));
}
