/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:17:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 13:25:28 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H
# include "draw.h"
# include <stdbool.h>

# define PLATEAU "Plateau"
# define END "=="
# define PLAYER "$$$"

typedef struct		s_game
{
	char			*p1;
	char			*p2;
	int				wgt_p1;
	int				wgt_p2;
	int				h;
	int				w;
	int				step;
	int				color;
}					t_game;

int					set_players(t_game *game);
void				set_width_height(int *w, int *h, const char *title);

int					**get_int_matrix(int w, int h);
int					**get_new_map(t_game *game);

void				del_game(t_game **game);

t_game				*init_game(void);

int					next_step(t_game *game, int ***maps);

void				upd_weight_players(t_game *game, int **map);

void				pass_line(void);

void				visualization(t_game *game, int **map);

#endif
