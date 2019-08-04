/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:57:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 16:05:46 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static int			get_color_elem(int elem, int num_color)
{
	int				color;

	if (elem == 0)
		color = L_GR;
	else if (elem < 0)
	{
		if (elem == -2)
			color = get_color_player(2, num_color);
		else
			color = get_color_player(2, num_color) | NC;
	}
	else
	{
		if (elem == 2)
			color = get_color_player(1, num_color);
		else
			color = get_color_player(1, num_color) | NC;
	}
	return (color);
}

static void			draw_row_map(t_viz *viz, int w, int h, int row)
{
	t_px			bgn;
	t_px			end;
	int				**map;
	int				color;
	int				n;

	n = 0;
	map = (int **)viz->maps->con;
	while (n < viz->game->w)
	{
		color = get_color_elem(map[row][n], viz->game->color);
		set_px(&bgn, w * n + 2, h * row + 2, color);
		set_px(&end, w * n + w, h * row + h, color);
		draw_square(viz->img, bgn, end, false);
		n++;
	}
}

static void			set_size_square(int *w, int *h, t_game *game)
{
	*w = (W_MAP - game->w) / game->w;
	*h = (H_MAP - game->h) / game->h;
}

void				draw_map(t_viz *viz)
{
	int				w;
	int				h;
	int				row;

	set_size_square(&w, &h, viz->game);
	row = 0;
	clear_img(viz->img, BLACK);
	while (row < viz->game->h)
	{
		draw_row_map(viz, w, h, row);
		row++;
	}
	mlx_put_image_to_window(viz->mlx, viz->win->win, viz->img->img, SMX, SMY);
}
