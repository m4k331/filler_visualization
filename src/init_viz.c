/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:34:03 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 21:55:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static void			set_connect(t_viz **viz)
{
	if (*viz != NULL)
	{
		(*viz)->mlx = mlx_init();
		if ((*viz)->mlx == NULL)
		{
			ft_memdel((void **)viz);
			perror("mlx not init\n");
		}
	}
}

static void			set_window(t_viz **viz)
{
	if (*viz != NULL)
	{
		(*viz)->win = get_new_win((*viz)->mlx, W, H, "filler");
		if ((*viz)->win == NULL)
		{
			ft_memdel((void **)viz);
			perror("window not init\n");
		}
	}
}

static void			set_image(t_viz **viz)
{
	if (*viz != NULL)
	{
		(*viz)->img = get_new_img((*viz)->mlx, W_MAP, H_MAP);
		if ((*viz)->img == NULL)
		{
			del_win((*viz)->win);
			ft_memdel((void **)viz);
			perror("image not created\n");
		}
	}
}

t_viz				*init_viz(t_game *game, t_dlist *maps)
{
	t_viz			*viz;

	viz = (t_viz *)ft_memalloc(sizeof(t_viz));
	set_connect(&viz);
	set_window(&viz);
	set_image(&viz);
	if (viz == NULL)
		return (NULL);
	viz->game = game;
	viz->maps = maps;
	return (viz);
}
