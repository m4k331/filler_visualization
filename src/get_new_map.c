/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:28:14 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 13:42:11 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static int			fill_row(int *map_row, char *str_row, int n)
{
	int				i;

	i = 0;
	while (i < n)
	{
		if (str_row[i] == '.')
			map_row[i] = 0;
		else if (str_row[i] == 'O')
			map_row[i] = 2;
		else if (str_row[i] == 'o')
			map_row[i] = 1;
		else if (str_row[i] == 'X')
			map_row[i] = -2;
		else if (str_row[i] == 'x')
			map_row[i] = -1;
		else
			return (false);
		i++;
	}
	return (true);
}

static char			*ptr_on_row_elems(char *line)
{
	char			*space;
	size_t			len;

	space = ft_strchr(line, ' ') + 1;
	len = (size_t)space - (size_t)line;
	if (len < 1)
		return (NULL);
	return (line + len);
}

static int			fill_map(int **map, int w, int h)
{
	char			*line;
	char			*str_row;
	int				row;

	row = 0;
	while (row < h)
	{
		line = NULL;
		get_next_line(STDIN_FILENO, &line);
		if (line == NULL)
			return (false);
		str_row = ptr_on_row_elems(line);
		if (str_row == NULL)
			return (false);
		if (fill_row(map[row], str_row, w) == false)
			return (false);
		free(line);
		row++;
	}
	return (true);
}

int					**get_new_map(t_game *game)
{
	int				**map;

	map = get_int_matrix(game->w, game->h);
	if (map == NULL)
		return (NULL);
	if (fill_map(map, game->w, game->h) == false)
	{
		del_any_matrix((void **)map, 2);
		return (NULL);
	}
	return (map);
}