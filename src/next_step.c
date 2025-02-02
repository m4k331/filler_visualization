/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:57:04 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 18:23:04 by ahugh            ###   ########.fr       */
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

	if (viz->maps->next == NULL)
	{
		if (skip_no_map_lines() == false)
			return (false);
		field = get_new_map(viz->game);
		if (field == NULL)
			return (false);
		ft_dlstaddlast(&(viz->maps), ft_dlstnew(0, 0));
		viz->maps->next->con = field;
		viz->maps->next->con_sz = viz->game->step;
		if (viz->maps->next == NULL)
			return (false);
	}
	viz->game->step++;
	viz->maps = viz->maps->next;
	upd_weight_players(viz->game, (int **)viz->maps->con);
	visualization(viz);
	return (true);
}
