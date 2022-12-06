/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:35:48 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:13:57 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# define PLAYER "./assets/player.xpm"
# define COLLECTABLE "./assets/collectable.xpm"
# define WALL "./assets/wall.xpm"
# define GROUND "./assets/ground.xpm"
# define EXIT "./assets/exit.xpm"
# define ENEMY "./assets/hedgehog1.xpm"
# define ENEMY2 "./assets/hedgehog2.xpm"
# define ENEMY3 "./assets/hedgehog3.xpm"
# define ENEMY4 "./assets/hedgehog4.xpm"

# define COLOR 0x0000FF

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_img{
	void	*image;
	int		width;
	int		height;
}		t_img;

typedef struct s_prog{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		enemy_x;
	int		enemy_y;
	int		score;
	int		collect;
	int		steps;
	int		flag_enemy;
	t_img	ground;
	t_img	wall;
	t_img	player;
	t_img	collectable;
	t_img	exit;
	t_img	enemy;
}		t_prog;
int		exit_game(t_prog *game);
void	check_map_name(char *map_name);
void	map_checker(t_prog *game);
void	check_symbols(t_prog *game);
int		key_press(int keycode, t_prog *game);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	read_map(char *map_name, t_prog *game);
void	set_values(t_prog *game);
void	init_map(char *map_name, t_prog *game);
char	*get_next_line(int fd);
int		init_image(t_prog *game);
int		put_image(t_prog *game);
void	put_image1(t_prog *game, int x, int y);
void	move_player(t_prog *game, int x, int y);
void	player_pos(t_prog *game);
void	count_steps(t_prog *game);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char *s1, char *set);
void	error(char *str);
int		counter(t_prog *game);
int		move_enemy(t_prog *game);
void	set_enemy_pos(t_prog *game, int x, int y);
void	draw_enemy(t_prog *game, char *steps, char *path);
void	enemy_pos(t_prog *game);

#endif