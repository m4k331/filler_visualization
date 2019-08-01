/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:27:09 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/01 19:37:59 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static char		*parse_player_name(char *line)
{
	char		*name;
	char		*dot;
	size_t		len;

	line += 23;
	dot = ft_strchr(line, '.');
	len = (size_t)dot - (size_t)line;
	if (len < 1)
		return (NULL);
	name = (char *)ft_memalloc(len + 1);
	if (name == NULL)
		return (NULL);
	name = ft_memcpy(name, line, len);
	return (name);
}

static int		set(t_game *game)
{
	char		*line;
	int			i;

	i = 0;
	while (i < 2)
	{
		line = NULL;
		get_next_line(STDIN_FILENO, &line);
		if (line == NULL)
			return (false);
		if (ft_strncmp(PLAYER, line, 3) == 0)
		{
			if (i == 0)
				game->p1 = parse_player_name(line);
			else
				game->p2 = parse_player_name(line);
			i++;
		}
		else if (ft_strncmp(PLATEAU, line, 7) == 0)
			return (false);
		free(line);
	}
	return (true);
}

int				set_players(t_game *game)
{
	if (set(game) == true)
	{
		if (game->p1 == NULL || game->p2 == NULL)
		{
			if (game->p1 == NULL)
				free(game->p1);
			if (game->p2 == NULL)
				free(game->p2);
			return (false);
		}
		return (true);
	}
	else
	{
		if (game->p1 != NULL)
			free(game->p1);
		if (game->p2 != NULL)
			free(game->p2);
		return (false);
	}
}
