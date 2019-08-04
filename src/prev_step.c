/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:13:27 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 18:22:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int					prev_step(t_viz *viz)
{
	if (viz->game->step - 1 == -1)
		return (false);
	viz->game->step--;
	viz->maps = viz->maps->prev;
	upd_weight_players(viz->game, (int **)viz->maps->con);
	visualization(viz);
	return (true);
}
