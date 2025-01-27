/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:21:09 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/19 21:12:37 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define FD_SIZE 2048
# define ERROR -1
# define ENDOFFILE 0
# define NEXTLINE 1
# include "libft/libft.h"

int			get_next_line(const int fd, char **line);

#endif
