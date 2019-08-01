/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:17:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/01 19:55:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H
# include "draw.h"
# include <stdbool.h>

# define PLATEAU "Plateau"
# define PLAYER "$$$"

typedef struct		s_game
{
	int				**field;
	char			*p1;
	char			*p2;
	int				h;
	int				w;
	int				move;
}					t_game;

int					set_players(t_game *game);
void				set_width_height(int *w, int *h, const char *title);
int					init_game(void);

#endif
