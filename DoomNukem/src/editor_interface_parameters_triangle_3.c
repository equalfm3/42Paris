/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_interface_parameters_triangle_3.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparis <lparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:28:12 by mofikrat          #+#    #+#             */
/*   Updated: 2021/02/23 14:24:15 by lparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void		ft_map_editor_triangle_parameter_position_h(t_variable_list *l)
{
	l->u.str_address = "H";
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	l->u.wsx += 1;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_v(t_variable_list *l)
{
	l->u.str_address = "V";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_l(t_variable_list *l)
{
	l->u.str_address = "L";
	l->u.wsx += 0.5;
	l->u.action = ++l->action;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_x_1(t_variable_list *l)
{
	l->u.str_address = "X";
	l->u.wsx = 37;
	l->u.wsy += 2.5;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.x1[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}

void		ft_map_editor_triangle_parameter_position_y_1(t_variable_list *l)
{
	l->u.str_address = "Y";
	l->u.wsx += 1;
	l->u.action = ++l->action;
	l->u.size = 1;
	l->u.colors = l->me.color_blue;
	l->u.colors_on = l->me.color_green;
	ft_put_text(l);
	ft_itoa(l->t.y1[l->triangle_select], l->me.str);
	l->u.str_address = l->me.str;
	l->u.wsx += 0.5;
	l->u.size = 0.80;
	l->u.colors = l->me.color_white;
	l->u.colors_on = l->me.color_white;
	ft_put_text(l);
}
