/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_player_wgt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:48:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 19:48:07 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

char				*get_str_player_wgt(char *player, int wgt)
{
	char			*result;
	char			*str_wgt;

	str_wgt = ft_itoa(wgt);
	if (str_wgt == NULL)
		return (NULL);
	result = ft_strnew(3 + ft_strlen(player) + ft_strlen(str_wgt));
	ft_strcat(result, player);
	ft_strcat(result, " (");
	ft_strcat(result, str_wgt);
	ft_strcat(result, ")");
	ft_memdel((void **)&str_wgt);
	return (result);
}
