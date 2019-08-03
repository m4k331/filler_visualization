/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:57:04 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 22:50:32 by ahugh            ###   ########.fr       */
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

int					next_step(t_viz *viz)
{
	int				**field;

	viz->game->step++;
	if (viz->maps->next == NULL)
	{
		if (skip_no_map_lines() == false)
			return (false);
		field = get_new_map(viz->game);
		if (field == NULL)
			return (false);
		viz->maps->next = ft_dlstnew(field, viz->game->step);
		del_any_matrix((void **)field, 2);
		if (viz->maps->next == NULL)
			return (false);
	}
	viz->maps = viz->maps->next;
	upd_weight_players(viz->game, (int **)viz->maps->con);
	visualization(viz);
	return (true);
}
