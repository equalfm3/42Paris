/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:28:48 by mofikrat          #+#    #+#             */
/*   Updated: 2020/02/22 17:37:01 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WIDTH 1080
# define W_HEIGHT 756
# define ZOOM_MAX 100000000000000
# include <mlx.h>
# include <math.h>
# include <complex.h>
# include <pthread.h>
# include "../libft/includes/libft.h"

typedef struct			s_thread
{
	int					start_x;
	int					start_y;
	int					end_x;
	int					end_y;
	struct s_data		*data;
	int					**img;
	struct s_thread		*next;
}						t_thread;

typedef struct			s_threads
{
	pthread_t			thread;
}						t_threads;

typedef struct			s_data
{
	int					*fractol;
	int					fractol_th1;
	int					fractol_th2;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*win_ptr2;
	void				*img_ptr;
	void				*img_ptr_menu;
	int					*idata_ptr_menu;
	void				*img_ptr2;
	int					*idata_ptr;
	int					*idata_ptr2;
	int					bpp;
	int					size_line;
	int					endian;
	double				mouse_x;
	double				mouse_y;
	double				*mx;
	double				movex_th1;
	double				movex_th2;
	double				*my;
	double				movey_th1;
	double				movey_th2;
	double				*zoom;
	double				zoom_th1;
	double				zoom_th2;
	int					iter;
	int					mouse_mod1;
	int					mouse_mod2;
	int					key_array[128];
	int					menu_show1;
	int					menu_show2;
	t_threads			thread[4];
	struct s_thread		*win_thread;
	struct s_thread		*win_thread1;
	struct s_thread		*win_thread2;
	struct				s_rgb
	{
		int				r;
		int				g;
		int				b;
	}					t_rgb;
}						t_data;

typedef struct			s_fractals
{
	double				cre;
	double				cim;
	double				re;
	double				im;
	double				oldre;
	double				oldim;
}						t_fractals;

int						mandelbrot_definer(t_data *data, t_fractals *it, int i);
int						burningship_definer(t_data *data, t_fractals *it,
	int i);
int						julia_definer(t_data *data, t_fractals *it, int i);
int						newton_definer(t_data *data, t_fractals *it, int i);
int						color_getter(unsigned int i, t_data data);
int						color_rgba(unsigned int a, unsigned int r,
	unsigned int g, unsigned int b);
int						color_rgba_iter(unsigned int i, int r, int g, int b);
void					color_resetter(t_data *data);
void					color_cycler(int keycode, t_data *data);
double					min_double(double t1, double t2);
int						ft_exit(void);
void					window_creator(t_data *data);
int						fractal_data_setter(t_data *data, char *av);
void					input_validator(int ac, char **av, t_data *data);
void					thread_initiator(t_data *data);
void					fractal_processer(t_data *data, t_thread **thread,
	int **img);
void					fractal_displayer(t_data *data, int win);
double					new_ri(t_data *data, int xy, int i, double movexy);
void					main_cycle(t_thread **thread);
void					usage_displayer(void);
void					pos_initiator(t_data *data, t_thread **thread,
	int **img, int ntr);
void					pos_data_setter(t_data *data, t_thread *tmp, int **img,
	int x);
int						mouse_move_th1(int x, int y, t_data *data);
int						mouse_zoom_th1(int g, int x, int y, t_data *data);
int						mouse_zoom_th2(int g, int x, int y, t_data *data);
int						mouse_move_th2(int x, int y, t_data *data);
void					resetter_th1(t_data *data);
void					resetter_th2(t_data *data);
int						key_press_th1(int keycode, t_data *data);
int						key_press_th2(int keycode, t_data *data);
void					key_array_initiator(t_data *data);
void					hook_and_display_th1(t_data *data);
void					hook_and_display_th2(t_data *data);
void					key_processer_th1(int keycode, t_data *data);
void					key_processer_th2(int keycode, t_data *data);
void					thread_creator(void (*fractal), t_data *data,
	t_thread *tr);
void					data_displayer_th1(t_data *data);
void					data_displayer_th2(t_data *data);
void					menu_displayer(t_data *data);
void					menu_displayer_th1(t_data *data);
void					menu_displayer_th2(t_data *data);
void					info_displayer_th1(t_data *data);
void					info_displayer_th2(t_data *data);
void					merge_all(t_data *data, t_thread *tr);

#endif
