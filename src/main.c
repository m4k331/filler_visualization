/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:16:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 16:51:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

int				main(int ac, char **av)
{
	if (run_visualization() == false)
		return (1);
	ac++;
	av++;
	return (0);
}
