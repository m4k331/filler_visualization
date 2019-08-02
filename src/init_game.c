/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:06:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 13:52:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

t_game				*init_game(void)
{
	t_game			*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	if (set_players(game) == false)
	{
		del_game(&game);
		return (NULL);
	}
	set_width_height(&game->w, &game->h, PLATEAU);
	if (game->w < 1 || game->h < 1)
	{
		del_game(&game);
		return (NULL);
	}
	return (game);
}
