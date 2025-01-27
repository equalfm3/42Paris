/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:53:31 by esuslova          #+#    #+#             */
/*   Updated: 2019/04/28 23:26:48 by esuslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_shapes
{
	t_coor			t1;
	t_coor			t2;
	t_coor			t3;
	t_coor			t4;
	char			alpha;
}					t_shapes;

void				ft_putchar(char c);
void				ft_putendl(char *s);
void				ft_bzero(void *s, size_t n);
int					ft_board_size(int nb);
void				ft_board_display(char **board);
char				**ft_board_create(int nb);
void				ft_board_free(char **board);
int					ft_tetri_read(t_shapes **t, char *buff, int fd, char al);
void				ft_tetri_free(t_shapes **tetri);
void				ft_tetri_delete(char **board, int size, t_shapes tetri);
int					ft_chartotetri(char *input, t_shapes *tetri);
t_coor				ft_firstpiece(char *input);
void				ft_abstorelative(t_coor head, t_shapes *tetri);
int					ft_can_fill(t_coor coo, t_shapes t, char **b, int size);
int					ft_input_check(char *input);
int					ft_neighborscheck1(t_shapes tetri);
int					ft_neighborscheck2(t_shapes tetri);
int					ft_neighborscheck3(t_shapes tetri);
int					ft_neighborscheck4(t_shapes tetri);
int					ft_neighborscheck5(t_shapes tetri);
int					ft_neighborscheck6(t_shapes tetri);
int					ft_neighbors(t_shapes tetri);
void				ft_fill(t_coor coo, t_shapes tetri, char **board, char c);
int					ft_file_open(t_shapes **tetri, char *filename);
int					ft_iterate(char **b, int size, t_shapes **t, t_coor coo);
void				ft_fillit(t_shapes **tetri);
int					ft_tetri_count(t_shapes **tetri);
int					ft_sqrt_recursive(int l, int r, int nb);

#endif
