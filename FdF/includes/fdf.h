/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:12:14 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 21:21:02 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** INCLUDES
*/
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

/*
** READ BUFFER
*/
# define BUFF_SIZE	8192

/*
** LOOP LIMITER
*/
# define LIMITER	1024

/*
** WINDOW PARAMETERS
*/
# define WIN_W		1920
# define WIN_H 		1080

/*
** COLOR PARAMETERS
*/
# define WHITE		0xFFFFFF
# define DARK_GRAY	0x101010
# define GOKU2		0x072083
# define GOKU1		0xF85B1A
# define VEGETA2	0xF9EE54
# define VEGETA1	0x2955DC
# define FRIEZA1	0xC1D2C8
# define FRIEZA2	0x633183
# define PICCOLO1	0x00a86b
# define PICCOLO2	0x800080
# define BOO1		0xff05db
# define BOO2		0xfff403

/*
** OTHER PARAMETERS
*/
# define PI 		3.14159265359

/*
** VIRTUAL POINT STRUCTURE
*/
typedef struct		s_vpt
{
	int		x;
	int		y;
	int		z;
	int		color;
}					t_vpt;

/*
** LOGICAL VECTOR STRUCTURE
*/
typedef struct		s_vec
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		deriv;
	int		src;
	int		dst;
	int		src_color;
	int		dst_color;
}					t_vec;

/*
** LOGICAL FDF STRUCTURE
*/
typedef struct		s_fdf
{
	int				w;
	int				h;
	struct s_vpt	**grid;
	int				*img;
	int				*imgvec;
	void			*mlx;
	void			*win;
	char			*theme;
	int				x0;
	int				y0;
	char			view;
	double			zoom;
	int				fluidity;
	int				alpha;
	int				beta;
	int				gamma;
	double			amplitude;
	int				maxima;
	int				minima;
	int				colors[2];
	int				is_menu_displayed;
}					t_fdf;

/*
** checker.c
*/
int					checker(t_fdf *f, char *file);
int					altitude_checker(t_fdf *f, int *z_xy, char *file);
void				limits_checker(char *file, int i);
int					hex_checker(char *file, int *i);
void				error_displayer(char *error);

/*
** cleaner.c
*/
int					fdf_terminator(t_fdf *f);
void				grid_cleaner(t_fdf *f);

/*
** colors.c
*/
void				vpoint_color(t_fdf *f);
int					vpoint_color_computer(t_fdf *f, int altitude);
int					pixel_color_computer(struct s_vec v);
double				ratio_computer(int current, int minima, int maxima);
int					grad_computer(int minima, int maxima, double ratio);

/*
** displayer.c
*/
void				keys_displayer(t_fdf *f);
void				themes_displayer(t_fdf *f);
void				info_displayer(t_fdf *f);
void				display_refactor(t_fdf *f, int y, char *msg, int var);

/*
** drawer.c
*/
void				pixel_drawer(t_fdf *f, struct s_vec v);
void				grid_drawer(t_fdf *f);
void				line_drawer(t_fdf *f, struct s_vpt src, struct s_vpt dst);
void				lineh_drawer(t_fdf *f, struct s_vpt src,
					struct s_vpt dst, struct s_vec v);
void				linel_drawer(t_fdf *f, struct s_vpt src,
					struct s_vpt dst, struct s_vec v);

/*
** fdf.c
*/
t_fdf				*fdf_initiator(void);
void				mlx_runner(t_fdf *f);
void				fdf_runner(t_fdf *f);

/*
** listener1.c & listener2.c
*/
int					key_listener(int key, t_fdf *f);
int					view_switcher(t_fdf *f, int key);
int					translator(int key, t_fdf *f);
int					rotator(int key, t_fdf *f);
int					zoom_controller(int key, t_fdf *f);
int					amplitude_controller(int key, t_fdf *f);
int					fluidity_controller(int key, t_fdf *f);
int					color_palette_selector(int key, t_fdf *f);

/*
** parser.c
*/
int					grid_creator(t_fdf *f);
int					grid_height_fetcher(char *file);
int					grid_width_fetcher(char *file);
char				*file_reader(const char *argv, int no_inf_loop);

/*
** positioner.c
*/
void				grid_rotator(t_fdf *f);
void				x_rotator(t_fdf *f, int *y, double *z);
void				y_rotator(t_fdf *f, int *x, double *z);
void				z_rotator(t_fdf *f, int *x, int *y);

/*
** viewer.c
*/
void				iso_par_selector(t_fdf *f);
void				view_resetter(t_fdf *f);
int					rotation_selector(t_fdf *f);

#endif
