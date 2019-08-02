/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:16:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 16:22:42 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int				main(int ac, char **av)
{
	t_game		*game;
	int			***maps;
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
	if (game == NULL)
		return (1);

	maps = (int ***)ft_memalloc(sizeof(int **) * 6024);

	pass_line();
	maps[0] = get_new_map(game);
	if (maps[0] == NULL)
		return (1);
	upd_weight_players(game, maps[game->step]);
	visualization(game, maps[0]);

	while (1)
	{
		if (next_step(game, maps) == false)
			break ;
	}

	del_any_matrix((void **)maps, 3);
	del_game(&game);
while(1){}
	ac++;
	av++;
	return (0);
}
