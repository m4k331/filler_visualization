/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:57:04 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 20:33:09 by ahugh            ###   ########.fr       */
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

int					next_step(t_game *game, t_dlist **maps)
{
	int				**field;

	game->step++;
	if ((*maps)->next == NULL)
	{
		if (skip_no_map_lines() == false)
			return (false);
		field = get_new_map(game);
		if (field == NULL)
			return (false);
		(*maps)->next = ft_dlstnew(field, game->step);
		del_any_matrix((void **)field, 2);
		if ((*maps)->next == NULL)
			return (false);
	}
	*maps = (*maps)->next;
	upd_weight_players(game, (int **)(*maps)->con);
	//visualization(game, maps[game->step]);
	return (true);
}
