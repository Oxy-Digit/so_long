# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlumbers <tlumbers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 07:37:41 by tlumbers          #+#    #+#              #
#    Updated: 2022/12/07 00:32:01 by tlumbers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIST = so_long.c read_map.c \
		get_next_line.c get_next_line_utils.c \
		render_map.c map_checker.c map_checker2.c player_move.c \
		enemy_move.c so_long_utils.c so_long_utils2.c \
		

OBJ 	=  $(patsubst %.c,%.o,$(LIST))

MLX		=	libmlx.a
MLXDIR	=	./mlx/

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) so_long.h
	make -C $(MLXDIR)
#	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(CC) $(OBJ) -Lmlx -lmlx -lz -framework OpenGL -framework Appkit -o $(NAME)

%.o : %.c 
	$(CC)  -Imlx -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
