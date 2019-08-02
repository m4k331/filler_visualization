/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:39:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 13:39:23 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				visualization(t_game *game, int **map)
{
	int				w;
	int				h;

	printf("\n%s(%d)\t%s(%d)\n", game->p1, game->wgt_p1, game->p2, game->wgt_p2);
	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			printf("%2d", map[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
}
