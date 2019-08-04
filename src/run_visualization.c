/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_visualization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:28:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 16:53:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static void		key_hooks(t_viz **viz)
{
	(*viz)->game->step += 0;
}

static int		initialisation(t_viz **viz)
{
	t_game		*game;
	t_dlist		*maps;

	game = init_game();
	if (game == NULL)
	{
		perror("failed to create game\n");
		return (false);
	}
	maps = ft_dlstnew(0, 0);
	if (maps == NULL)
	{
		del_game(&game);
		perror("failed to create maps\n");
		return (false);
	}
	*viz = init_viz(game, maps);
	if (*viz == NULL)
	{
		ft_memdel((void **)&maps);
		del_game(&game);
		perror("The basic structure for visualization has not been created\n");
		return (false);
	}
	return (true);
}

static int		set_initial_values(t_viz **viz)
{
	pass_line();
	(*viz)->maps->con = get_new_map((*viz)->game);
	if ((*viz)->maps->con == NULL)
	{
		ft_memdel((void **)&(*viz)->maps);
		del_game(&(*viz)->game);
		del_img((*viz)->img);
		del_win((*viz)->win);
		ft_memdel((void **)viz);
		perror("failed to set initial values\n");
		return (false);
	}
	upd_weight_players((*viz)->game, (*viz)->maps->con);
	return (true);
}

int				run_visualization(void)
{
	t_viz		*viz;

	if (initialisation(&viz) == false)
		return (false);
	if (set_initial_values(&viz) == false)
		return (false);
	visualization(viz);
	key_hooks(&viz);
	mlx_loop(viz->mlx);
	return (true);
}
