/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:57:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 23:25:43 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				draw_map(t_viz *viz)
{
	int				**arr;
	int				w;
	int				h;
	int				x;
	int				y;
	t_px			bgn;
	t_px			end;

	w = (W_MAP - viz->game->w - 2) / viz->game->w;
	h = (H_MAP - viz->game->h - 2) / viz->game->h;
	y = 0;
	while (y < viz->game->h)
	{
		x = 0;
		while (x < viz->game->w)
		{
			arr = (int **)viz->maps->con;
			if (arr[y][x] == 0)
			{
				set_px(&bgn,((x * w) + x), ((y * h) + y), M_GN);
				set_px(&end, (x * w) + w, (y * h) + h, M_GN);
			}
			else
			{
				set_px(&bgn,((x * w) + x), ((y * h) + y), M_BL);
				set_px(&end, ((x * w) + x) + w, ((y * h) + y) + h, M_BL);
			}
			draw_square(viz->img, bgn, end, false);
			mlx_put_image_to_window(viz->mlx, viz->win->win, viz->img->img, X, Y);
			x++;
		}
		y++;
	}
}
