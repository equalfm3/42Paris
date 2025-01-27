/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:45:20 by mofikrat          #+#    #+#             */
/*   Updated: 2019/12/12 00:39:25 by mofikrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_refactor(t_fdf *f, int y, char *msg, int var)
{
	char *tofree1;
	char *tofree2;

	tofree2 = ft_itoa(var);
	tofree1 = ft_strjoin(msg, tofree2);
	mlx_string_put(f->mlx, f->win, 30, y, WHITE, tofree1);
	free(tofree2);
	free(tofree1);
}

void	keys_displayer(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 30, 30, BOO2, "### KEYS #####");
	mlx_string_put(f->mlx, f->win, 30, 50, WHITE, "HIDE MENU     [TAB]");
	mlx_string_put(f->mlx, f->win, 30, 70, WHITE, "ISO vs //     [Return]");
	mlx_string_put(f->mlx, f->win, 30, 90, WHITE, "Translate     <Arrows>");
	mlx_string_put(f->mlx, f->win, 30, 110, WHITE, "X° Rotate      [A]:[D]");
	mlx_string_put(f->mlx, f->win, 30, 130, WHITE, "Y° Rotate      [W]:[X]");
	mlx_string_put(f->mlx, f->win, 30, 150, WHITE, "Z° Rotate      [Q]:[E]");
	mlx_string_put(f->mlx, f->win, 30, 170, WHITE, "Auto X° Rotate [6]:[4]");
	mlx_string_put(f->mlx, f->win, 30, 190, WHITE, "Auto Y° Rotate [8]:[2]");
	mlx_string_put(f->mlx, f->win, 30, 210, WHITE, "Auto Z° Rotate [9]:[7]");
	mlx_string_put(f->mlx, f->win, 30, 230, WHITE, "Relax & Watch [0]");
	mlx_string_put(f->mlx, f->win, 30, 250, WHITE, "Zoom          [+]:[-]");
	mlx_string_put(f->mlx, f->win, 30, 270, WHITE, "Amplitude     [P+]:[P-]");
	mlx_string_put(f->mlx, f->win, 30, 290, WHITE, "Fluidity      [Hm]:[End]");
	mlx_string_put(f->mlx, f->win, 30, 310, WHITE, "Reset         [clear]");
}

void	info_displayer(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 30, 420, BOO2, "### INFO ######");
	mlx_string_put(f->mlx, f->win, 30, 440, WHITE, "Theme         : ");
	mlx_string_put(f->mlx, f->win, 190, 440, WHITE, f->theme);
	display_refactor(f, 460, "Height        : ", f->h);
	display_refactor(f, 480, "Width         : ", f->w);
	display_refactor(f, 500, "Alpha         : ", f->alpha % 360);
	display_refactor(f, 520, "Beta          : ", f->beta % 360);
	display_refactor(f, 540, "Gamma         : ", f->gamma % 360);
	display_refactor(f, 560, "Amplitude     : ", 100 * (f->amplitude));
	display_refactor(f, 580, "Zoom          : ", f->zoom);
	display_refactor(f, 600, "X Position    : ", f->x0);
	display_refactor(f, 620, "Y Position    : ", f->y0);
	display_refactor(f, 640, "Fluidity      : ", f->fluidity);
}

void	themes_displayer(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 30, 910, BOO2, "### THEMES ####");
	mlx_string_put(f->mlx, f->win, 30, 930, WHITE, "42            : [1]");
	mlx_string_put(f->mlx, f->win, 30, 950, GOKU1, "GOKU          : [2]");
	mlx_string_put(f->mlx, f->win, 30, 970, FRIEZA2, "FRIEZA        : [3]");
	mlx_string_put(f->mlx, f->win, 30, 990, VEGETA1, "VEGETA        : [4]");
	mlx_string_put(f->mlx, f->win, 30, 1010, PICCOLO1, "PICCOLO       : [5]");
	mlx_string_put(f->mlx, f->win, 30, 1030, BOO1, "BOO           : [6]");
}
