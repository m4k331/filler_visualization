/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:57:04 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 16:29:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static int			skip_no_map_lines(void)
{
	char			*line;

	line = NULL;
	while (1)
	{
		get_next_line(STDIN_FILENO, &line);
		if (line == NULL)
			return (false);
		if (ft_strncmp(END, line, 2) == 0)
		{
			ft_memdel((void **)&line);
			pass_line();
			return (false);
		}
		if (ft_strncmp(PLATEAU, line, 7) == 0)
		{
			ft_memdel((void **)&line);
			pass_line();
			return (true);
		}
		ft_memdel((void **)&line);
	}
}

int					next_step(t_game *game, int ***maps)
{
	game->step++;
	if (maps[game->step] == NULL)
	{
		if (skip_no_map_lines() == false)
			return (false);
		maps[game->step] = get_new_map(game);
		if (maps[game->step] == NULL)
			return (false);
	}
	upd_weight_players(game, maps[game->step]);
	visualization(game, maps[game->step]);
	return (true);
}
