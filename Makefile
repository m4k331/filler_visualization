# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/08/04 17:39:24 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	visualization

# colors

BLACK			=	'\033[0;30m'
RED				=	'\033[0;31m'
GREEN			=	'\033[0;32m'
YELLOW			=	'\033[0;33m'
BLUE			=	'\033[0;34m'
MAGENTA			=	'\033[0;35m'
CYAN			=	'\033[0;36m'
GRAY			=	'\033[0;37m'

# bold color

DGRAY			=	'\033[1;30m'
LRED			=	'\033[1;31m'
LGREEN			=	'\033[1;32m'
LYELLOW			=	'\033[1;33m'
LBLUE			=	'\033[1;34m'
LMAGENTA		=	'\033[1;35m'
LCYAN			=	'\033[1;36m'
WHITE			=	'\033[1;37m'

# name files

FILES			=	bottom.c \
					clip_end.c \
					draw_square.c \
					left_p1.c \
					top.c \
					center_p1.c \
					color.c \
					draw_straight_line.c \
					left_p2.c \
					utils_draw_line.c \
					center_p2.c \
					draw_line.c \
					image.c \
					left_top.c \
					window.c \
					clip_bgn.c \
					draw_slant_line.c \
					left_bottom.c \
					init_game.c \
					del_game.c \
					set_players.c \
					set_width_height.c \
					get_int_matrix.c \
					get_new_map.c \
					next_step.c \
					pass_line.c \
					visualization.c \
					upd_weight_players.c \
					init_viz.c \
					draw_panel.c \
					str_map_size.c \
					get_str_player.c \
					get_str_player_wgt.c \
					get_color_player.c \
					draw_map.c \
					run_visualization.c \
					red_button.c \
					del_viz.c \
					play.c \
					shift_color.c \
					main.c

# flags && compile

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -c

# mlx library

MLX				=	./minilibx/
MLX_LIB			=	$(MLX)mlx.a
MLX_INC			=	-I $(MLX)
MLX_LNK			=	-L $(MLX) -l mlx -framework OpenGL -framework AppKit

# ft library

FT				=	../libft_gh/
FT_LIB			=	$(FT)libft.a
FT_INC			=	-I $(FT)includes/
FT_LNK			=	-L $(FT) -l ft

# dir

OBJ_DIR		=	./obj/
SRC_DIR		=	./src/
INC_DIR		=	./inc/

# all files

HEADER			=	./inc/visualization.h
OBJ				=	$(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))
SRC				=	$(addprefix $(SRC_DIR), $(FILES))

# exceptions

.PHONY:				all clean fclean re

all: $(NAME)

$(FT_LIB):
	make -C $(FT) >> /dev/null
	@echo $(GREEN)"compile libft!"$(DGRAY)

$(MLX_LIB):
	make -C $(MLX) >> /dev/null
	@echo $(GREEN)"compile libmlx!"$(DGRAY)

obj:
	mkdir -p $(OBJ_DIR)
	@echo $(CYAN)"create dir "$(WHITE)$(OBJ_DIR)$(DGRAY)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I. $(FT_INC) $(MLX_INC) -o $@ -c $<
	@echo $(YELLOW)"create obj files visualization"$(DGRAY)

$(NAME): obj $(FT_LIB) $(MLX_LIB) $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -o $(NAME)
	@echo $(LMAGENTA)"visualization - ready!"$(DGRAY)

norm:
	@echo $(GREEN)"cheking is norminette:"$(DGRAY)
	@norminette $(HEADER) $(SRC)

clean:
	@echo $(LRED)"clean!"$(DGRAY)
	make -C $(MLX) clean >> /dev/null
	make -C $(FT) clean >> /dev/null
	rm -rf $(OBJ_DIR)
	@echo $(RED)"deleted dir: "$(WHITE) $(OBJ_DIR)

fclean: clean
	@echo $(LRED)"all clean!"$(DGRAY)
	make -C $(FT) fclean >> /dev/null
	rm -f $(NAME)

re: fclean all

horde:
	@echo $(RED)"\n\
                                   ########                                  \n\
                               #######  ######                               \n\
                            ######         ######                            \n\
                         ######               ######                         \n\
                #####  #####                     ###### #####                \n\
               ### ######                           ##########               \n\
              ###                                           ###              \n\
              ###                                            ##              \n\
             ###                                             ###             \n\
           ####                                               ####           \n\
          ###                   #############                   ####         \n\
        ####                 ######        #####                  ####       \n\
      ####                 ####               #####                ####      \n\
    ####                 ####                   ####                 ####    \n\
   ###                  ###         #####         ###                  ###   \n\
   ###                 ###        #########        ###                 ###   \n\
    ####              ###        ###     ####       ###              ####    \n\
      ####            ###      ####        ###       ##             ###      \n\
       ####           ##      ###           ####     ##           ####       \n\
         ####         ##     ###              ##     ##          ###       # \n\
######    ####        ###    ###             ###     ##        ####    ######\n\
 #############        ###     ###           ###      ##        ##############\n\
 ###    ######         ##      ###         ###      ###        #######   ### \n\
  ###                  ###      ####     ####      ###                  ###  \n\
   ###                  ###       #### #####      ###                  ###   \n\
    ###                  ###        ######       ###                  ###    \n\
     ###                  ###                   ###                  ###     \n\
      ###     ######       ###                 ###       ######     ###      \n\
       ###############      ###               ###      ###############       \n\
                    ###      ###             ###      ####        #          \n\
                     ###      ###            ##      ###                     \n\
                      ###      ##           ###     ###                      \n\
                       ###     ###         ###     ###                       \n\
                        ##      ##         ##     ###                        \n\
                        ###     ###       ###     ##                         \n\
                         ##      ##       ###    ###                         \n\
                         ##      ##       ##     ###                         \n\
                         ###     ###     ###      #######                    \n\
                         ###     ###     ###          ###                    \n\
                    ########     ###     ###         ###                     \n\
                    #######       ##     ###         ##                      \n\
                     ##           ##     ###        ###                      \n\
                     ###         ###     ###       ###                       \n\
                      ###        ###      ##      ###                        \n\
                       ###       ##       ###    ###                         \n\
                        ###      ##        ##   ###                          \n\
                         ###     ##        ### ###                           \n\
                          ###   ###         #####                            \n\
                           ###  ##           ###                             \n\
                            ######                                           \n\
                             ####                                            \n\
"$(DGRAY)

