/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:44:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 17:50:06 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static int			print_info_map(t_viz *viz)
{
	char			*map;
	char			*player;

	mlx_string_put(viz->mlx, viz->win->win, 100, 300, INFO_MAP, "___INFO___");
	map = get_str_map_size(viz->game->w, viz->game->h);
	if (map == NULL)
		return (false);
	mlx_string_put(viz->mlx, viz->win->win, 100, 350, INFO_MAP, map);
	ft_memdel((void **)&map);
	player = get_str_player(1, viz->game->p1);
	if (player == NULL)
		return (false);
	mlx_string_put(viz->mlx, viz->win->win, 100, 400, INFO_MAP, player);
	ft_memdel((void **)&player);
	player = get_str_player(2, viz->game->p2);
	if (player == NULL)
		return (false);
	mlx_string_put(viz->mlx, viz->win->win, 100, 450, INFO_MAP, player);
	ft_memdel((void **)&player);
	return (true);
}

static void			print_keys(t_viz *viz)
{
	mlx_string_put(viz->mlx, viz->win->win, 100, 700, KEYS, "___KEYS___");
	mlx_string_put(viz->mlx, viz->win->win, 100, 750, KEYS, "PLAY: ENTER");
	mlx_string_put(viz->mlx, viz->win->win, 100, 800, KEYS, "NEXT: ->");
	mlx_string_put(viz->mlx, viz->win->win, 100, 850, KEYS, "PREV: <-");
	mlx_string_put(viz->mlx, viz->win->win, 100, 900, KEYS, "COLOR: SPACE");
}

static int			print_step(t_viz *viz)
{
	char			*step;
	char			*result;

	step = ft_itoa(viz->game->step);
	if (step == NULL)
		return (false);
	result = ft_strnew(ft_strlen("STEP: ") + ft_strlen(step));
	ft_strcat(result, "STEP: ");
	ft_strcat(result, step);
	mlx_string_put(viz->mlx, viz->win->win, 100, 1100, STEP, result);
	ft_memdel((void **)&step);
	ft_memdel((void **)&result);
	return (true);
}

static int			print_players(t_viz *viz)
{
	char			*player;
	int				color;

	player = get_str_player_wgt(viz->game->p1, viz->game->wgt_p1);
	if (player == NULL)
		return (false);
	color = get_color_player(1, viz->game->color);
	mlx_string_put(viz->mlx, viz->win->win, 800, 100, color, player);
	ft_memdel((void **)&player);
	player = get_str_player_wgt(viz->game->p2, viz->game->wgt_p2);
	if (player == NULL)
		return (false);
	color = get_color_player(2, viz->game->color);
	mlx_string_put(viz->mlx, viz->win->win, 1450, 100, color, player);
	ft_memdel((void **)&player);
	return (true);
}

int					draw_panel(t_viz *viz)
{
	mlx_clear_window(viz->mlx, viz->win->win);
	mlx_string_put(viz->mlx, viz->win->win, 100, 100,
			TL_FL, "### ### #   #   ### ##");
	mlx_string_put(viz->mlx, viz->win->win, 100, 120,
			TL_FL, "#    #  #   #   #   # #");
	mlx_string_put(viz->mlx, viz->win->win, 100, 140,
			TL_FL, "##   #  #   #   ##  ##");
	mlx_string_put(viz->mlx, viz->win->win, 100, 160,
			TL_FL, "#    #  #   #   #   # #");
	mlx_string_put(viz->mlx, viz->win->win, 100, 180,
			TL_FL, "#   ### ### ### ### # #");
	if (print_info_map(viz) == false)
		return (false);
	print_keys(viz);
	if (print_step(viz) == false)
		return (false);
	if (print_players(viz) == false)
		return (false);
	return (true);
}
