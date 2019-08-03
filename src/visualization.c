/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:39:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 22:57:37 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				visualization(t_viz *viz)
{
	if (draw_panel(viz) == false)
		return ;
	draw_map(viz);
	mlx_loop(viz->mlx);
}
