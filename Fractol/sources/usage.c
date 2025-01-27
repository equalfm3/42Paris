/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:33:46 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:25:50 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		usage_displayer(void)
{
	ft_putstr("Usage: ./fractol -f [1-9] -n [1-9]\n");
	ft_putstr("                    1-Julia 1\n");
	ft_putstr("                    2-Julia 2\n");
	ft_putstr("                    3-Mandelbrot 1\n");
	ft_putstr("                    4-Mandelbrot 2\n");
	ft_putstr("                    5-Burning ship 1\n");
	ft_putstr("                    6-Burning ship 2\n");
	ft_putstr("                    7-Newton 1\n");
	ft_putstr("                    8-Newton 2\n");
	ft_putstr("                    9-Newton 3\n");
	exit(0);
}

void		input_validator(int ac, char **av, t_data *data)
{
	int		x;

	x = 0;
	if (ac > 1)
	{
		while (++x < ac)
		{
			if (ft_strcmp("-f", av[x]) == 0 && av[x + 1])
				x++;
			else
				usage_displayer();
			if (av[x][1] || fractal_data_setter(&(*data), av[x]) == 0)
				usage_displayer();
		}
	}
	else
		usage_displayer();
}
