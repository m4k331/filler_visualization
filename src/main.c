/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:16:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 18:13:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int				main(int ac, char **av)
{
	t_viz		*viz;
	t_game		*game;
	int			***maps;

	game = init_game();
	if (game == NULL)
	{
		perror("failed to create game!\n");
		return (1);
	}
	maps = (int ***)ft_memalloc(sizeof(int **) * 6024);
	if (maps == NULL)
	{
		perror("failed to create maps!\n");
		del_game(&game);
		return (1);
	}
	viz = init_viz(game, maps);
	if (viz == NULL)
	{
		perror("The basic structure for visualization has not been created!\n");
		del_any_matrix((void **)maps, 3);
		del_game(&game);
		return (1);
	}

	pass_line();
	maps[0] = get_new_map(game);
	if (maps[0] == NULL)
		return (1);
	upd_weight_players(game, maps[game->step]);
	visualization(viz);

	while (1)
	{
		if (next_step(game, maps) == false)
			break ;
	}

	del_any_matrix((void **)maps, 3);
	del_game(&game);
	mlx_loop(viz->mlx);
	ac++;
	av++;
	return (0);
}
