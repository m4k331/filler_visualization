/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:00:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 16:24:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				del_game(t_game **game)
{
	if (*game != NULL)
	{
		if ((*game)->p1 != NULL)
			ft_memdel((void **)&(*game)->p1);
		if ((*game)->p2 != NULL)
			ft_memdel((void **)&(*game)->p2);
		ft_memdel((void **)game);
	}
}
