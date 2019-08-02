/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_viz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:44:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 20:02:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

static char			*map_size(int w, int h)
{
	char			*result;
	char			*str_w;
	char			*str_h;

	str_w = ft_itoa(w);
	if (str_w == NULL)
		return (false);
	str_h = ft_itoa(h);
	if (str_h == NULL)
	{
		ft_memdel((void **)&str_w);
		return (false);
	}
	result = ft_strnew(8 + ft_strlen(str_h) + ft_strlen(str_w));
	if (result == NULL)
	{
		ft_memdel((void **)&str_w);
		ft_memdel((void **)&str_h);
		return (false);
	}
	ft_strcat(result, "map: ");
	ft_strcat(result, str_h);
	ft_strcat(result, " x ");
	ft_strcat(result, str_w);
	ft_memdel((void **)&str_w);
	ft_memdel((void **)&str_h);
	return (result);
}

int					panel_viz(t_viz *viz)
{
	char			*str;

	mlx_string_put(viz->mlx, viz->win->win, 100, 50, SKY, "FILLER");
	mlx_string_put(viz->mlx, viz->win->win, 100, 300, M_RD, "INFO");
	str = map_size(viz->game->w, viz->game->h);
	if (str == NULL)
		return (false);
	mlx_string_put(viz->mlx, viz->win->win, 100, 400, M_RD, str);
	ft_memdel((void **)&str);

	return (1);
}

