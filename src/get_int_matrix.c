/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:11:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/01 11:11:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int				**get_int_matrix(int w, int h)
{
	size_t		size;
	int			**matrix;
	int			*row;
	int			iter;

	size = sizeof(int *) * (h + 1);
	matrix = (int **)ft_memalloc(size);
	if (matrix == NULL)
		return (NULL);
	iter = 0;
	size = sizeof(int) * (w + 1);
	while (iter < h)
	{
		row = (int *)ft_memalloc(size);
		if (row == NULL)
		{
			del_any_matrix((void **)matrix, 2);
			return (NULL);
		}
		matrix[iter] = row;
		iter++;
	}
	return (matrix);
}
