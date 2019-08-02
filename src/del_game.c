/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:00:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 11:37:14 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				del_game(t_game **game)
{
	if (*game != NULL)
	{
		if ((*game)->field != NULL)
			del_any_matrix((void **)(*game)->field, 2);
		if ((*game)->p1 != NULL)
			ft_free((*game)->p1);
		if ((*game)->p2 != NULL)
			ft_free((*game)->p2);
		ft_free(*game);
		*game = NULL;
	}
}
