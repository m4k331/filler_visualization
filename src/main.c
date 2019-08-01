/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:16:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/01 17:58:19 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void			title(t_win *win, t_img *img, t_game *game)
{
	t_px		bgn;
	t_px		end;

	set_px()
}

int				main(int ac, char **av)
{
	t_win		*win;
	void		*mlx;
	t_img		*img;


	mlx = mlx_init();
	win = get_new_win(mlx, W, H, "filler");
	img = get_new_img(mlx, W, H / 10);
	title(win, img);
	mlx_loop(mlx);
	ac++;
	av++;
	return (0);
}
