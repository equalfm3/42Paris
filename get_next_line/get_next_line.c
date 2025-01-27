/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:56:36 by mofikrat          #+#    #+#             */
/*   Updated: 2019/04/19 21:12:55 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_markendofline(char *s, char c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		*s = 0;
}

int		ft_lineiteration(char *fdvectorln, char **lineresult)
{
	char	*freemeplz1;
	char	*freemeplz2;

	if (ft_strchr(fdvectorln, '\n'))
	{
		freemeplz1 = ft_strdup(fdvectorln);
		fdvectorln = ft_strcpy(fdvectorln, &ft_strchr(fdvectorln, '\n')[1]);
		ft_markendofline(freemeplz1, '\n');
		freemeplz2 = *lineresult;
		*lineresult = ft_strjoin(*lineresult, freemeplz1);
		free(freemeplz1);
		free(freemeplz2);
		return (NEXTLINE);
	}
	else
	{
		freemeplz1 = *lineresult;
		*lineresult = ft_strjoin(*lineresult, fdvectorln);
		free(freemeplz1);
		ft_bzero(fdvectorln, BUFF_SIZE);
		return (ENDOFFILE);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*fdvector[FD_SIZE];
	int			read_result;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || fd >= FD_SIZE)
		return (ERROR);
	if (!fdvector[fd])
		fdvector[fd] = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (*fdvector[fd])
		if (ft_lineiteration(fdvector[fd], line))
			return (NEXTLINE);
	ft_bzero(fdvector[fd], BUFF_SIZE);
	while ((read_result = read(fd, fdvector[fd], BUFF_SIZE)))
	{
		if (read_result < 0)
			return (ERROR);
		if (ft_lineiteration(fdvector[fd], line))
			return (NEXTLINE);
	}
	if (**line == 0)
	{
		free(*line);
		return (ENDOFFILE);
	}
	return (NEXTLINE);
}
