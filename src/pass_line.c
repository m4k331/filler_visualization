/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:02:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/07/31 21:52:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void				pass_line(void)
{
	char			*line;

	line = NULL;
	get_next_line(STDIN_FILENO, &line);
	if (line != NULL)
		ft_free(line);
}
