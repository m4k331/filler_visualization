/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_weight_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:11:39 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 13:19:52 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				upd_weight_players(t_game *game, int **map)
{
	int				w;
	int				h;

	game->wgt_p1 = 0;
	game->wgt_p2 = 0;
	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			if (map[h][w] == 1 || map[h][w] == 2)
				game->wgt_p1++;
			else if (map[h][w] == -1 || map[h][w] == -2)
				game->wgt_p2++;
			w++;
		}
		h++;
	}
}
