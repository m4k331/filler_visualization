/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:27:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 16:34:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/draw.h"

t_win			*get_new_win(void *mlx, int width, int height, char *name)
{
	t_win		*window;

	if (!(window = malloc(sizeof(t_win))))
		return (0);
	window->mlx = mlx;
	if (!(window->win = mlx_new_window(mlx, width, height, name)))
		ft_memdel((void **)&window);
	else
	{
		window->width = width;
		window->height = height;
		window->name = name;
	}
	return (window);
}

void			del_win(t_win *window)
{
	if (window)
	{
		if (window->mlx && window->win)
			mlx_destroy_window(window->mlx, window->win);
		else if (window->mlx)
			ft_memdel((void **)&window->mlx);
		else if (window->win)
			ft_memdel((void **)&window->win);
		ft_memdel((void **)&window);
	}
}
