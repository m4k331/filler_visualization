/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:36:20 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 19:45:07 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

char				*get_str_player(int num, char *player)
{
	char			*result;

	result = ft_strnew(ft_strlen("player ##: ") + ft_strlen(player));
	if (result == NULL)
		return (NULL);
	if (num == 1)
		ft_strcat(result, "player #1: ");
	else
		ft_strcat(result, "player #2: ");
	ft_strcat(result, player);
	return (result);
}
