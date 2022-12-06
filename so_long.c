/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:35:39 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:13:01 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	exit_game(t_prog *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
}

int	key_press(int keycode, t_prog *game)
{
	if (keycode == ESC)
		exit_game(game);
	if (keycode == A)
		move_player(game, -1, 0);
	if (keycode == S)
		move_player(game, 0, 1);
	if (keycode == D)
		move_player(game, 1, 0);
	if (keycode == W)
		move_player(game, 0, -1);
	return (0);
}

void	check_map_name(char *map_name)
{
	size_t	size;

	size = ft_strlen(map_name);
	if (ft_strncmp(&map_name[size - 4], ".ber\0", 5))
		error("Incorrect map_name\n");
}

int	main(int argc, char **argv)
{
	t_prog	game;

	game.steps = 1;
	game.flag_enemy = 0;
	if (argc == 2)
	{
		check_map_name(argv[1]);
		game.map = &argv[1];
		read_map(argv[1], &game);
		map_checker(&game);
		game.width = ft_strlen(game.map[0]);
		game.mlx_ptr = mlx_init();
		game.win_ptr = mlx_new_window (game.mlx_ptr, game.width * 64,
				game.height * 64, "Mushroom");
		init_image (&game);
		put_image(&game);
		mlx_hook(game.win_ptr, 17, 1L << 0, exit_game, &game);
		mlx_hook(game.win_ptr, 02, 1L << 0, key_press, &game);
		if (game.flag_enemy)
			mlx_loop_hook(game.mlx_ptr, counter, &game);
		mlx_loop(game.mlx_ptr);
		return (0);
	}
	write(1, "Invalid Arguments\n", 18);
	return (0);
}
