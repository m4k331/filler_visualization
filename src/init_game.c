/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:06:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/01 19:55:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int				init_game(void)
{
	t_game		game;

	if (set_players(&game) == true)
		printf("p1: %s\np2: %s\n", game.p1, game.p2);
	set_width_height(&game.w, &game.h, PLATEAU);
	printf("w: %d\nh: %d\n", game.w, game.h);
	return (true);
}
