/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:13:21 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/01 11:20:46 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void			set_width_height(int *w, int *h, const char *title)
{
	char		*line;
	char		**slices;

	line = NULL;
	get_next_line(STDIN_FILENO, &line);
	if (line != NULL)
	{
		slices = ft_strsplit(line, ' ');
		ft_free(line);
		if (slices != NULL)
		{
			if (ft_strcmp(title, slices[0]) == 0)
			{
				*h = ft_atoi(slices[1]);
				*w = ft_atoi(slices[2]);
			}
			del_any_matrix((void **)slices, 2);
		}
	}
}
