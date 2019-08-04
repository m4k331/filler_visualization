/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_viz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:06:26 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 17:33:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static void			del_map(void *map, size_t sz)
{
	sz = 0;
	del_any_matrix((void **)map, 2);
}

void				del_viz(t_viz **viz)
{
	(*viz)->maps = ft_dlsthead((*viz)->maps);
	ft_dlstdel(&(*viz)->maps, del_map);
	del_game(&(*viz)->game);
	del_img((*viz)->img);
	del_win((*viz)->win);
	ft_memdel((void **)viz);
}
