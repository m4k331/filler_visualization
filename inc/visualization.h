/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:17:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 20:37:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H
# include "draw.h"
# include <stdbool.h>
# include <fcntl.h>
# include <time.h>

# define PLATEAU "Plateau"
# define END "=="
# define PLAYER "$$$"

# define W_MAP 1300
# define H_MAP 1000

# define SMX 550
# define SMY 150

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

typedef struct		s_viz
{
	void			*mlx;
	t_win			*win;
	t_img			*img;
	t_game			*game;
	t_dlist			*maps;
}					t_viz;

int					set_players(t_game *game);
void				set_width_height(int *w, int *h, const char *title);
int					**get_int_matrix(int w, int h);
int					**get_new_map(t_game *game);
void				del_game(t_game **game);
t_game				*init_game(void);
void				upd_weight_players(t_game *game, int **map);
void				pass_line(void);
void				visualization(t_viz *viz);

t_viz				*init_viz(t_game *game, t_dlist *maps);
void				del_viz(t_viz **viz);
char				*get_str_map_size(int w, int h);
char				*get_str_player(int num, char *player);
char				*get_str_player_wgt(char *player, int wgt);
int					get_color_player(int num, int color);

int					draw_panel(t_viz *viz);
void				draw_map(t_viz *viz);

int					run_visualization(void);

int					next_step(t_viz *viz);
int					prev_step(t_viz *viz);
int					red_button(void **viz);
void				shift_color(t_viz *viz);

#endif
