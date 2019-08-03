/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:58:00 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 22:28:06 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static int	g_c[14] = {A0, A1, A2, A3, A4, A5, A6, B0, B1, B2, B3, B4, B5, B6};

int			get_color_player(int num, int color)
{
	if (color > 6)
		color %= 6;
	return (g_c[color + ((num - 1) * 7)]);
}
