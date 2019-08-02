/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:16:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 11:51:28 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int				main(int ac, char **av)
{
	t_game		*game;
//	t_win		*win;
//	void		*mlx;
//	t_img		*img;
//
//
//	mlx = mlx_init();
//	win = get_new_win(mlx, W, H, "filler");
//	img = get_new_img(mlx, W, H / 10);
//	title(win, img);
//	mlx_loop(mlx);
	game = init_game();
	//printf("game: %p\nfield: %p\nw: %d\nh: %d\np1: %s\np2: %s\nstep: %d\ncolor: %d\n", game, game->field, game->w, game->h, game->p1, game->p2, game->step, game->color);
	del_game(&game);
	ac++;
	av++;
	return (0);
}
