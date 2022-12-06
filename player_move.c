/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:40:27 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:07:01 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_steps(t_prog *game)
{
	char	*steps;

	steps = ft_itoa(game->steps);
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 1);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 86, 86, COLOR, "Steps - ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 166, 86, COLOR,
		steps);
	free(steps);
	game->steps++;
}

void	player_pos(t_prog *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->map[i][j] = '0';
				break ;
			}
		}
	}
	game->map[game->pos_y][game->pos_x] = 'P';
}

void	move_player(t_prog *game, int x, int y)
{
	if (game->map[game->pos_y + y][game->pos_x + x] == '1')
		return ;
	else if (game->map[game->pos_y + y][game->pos_x + x] == 'C')
	{
		game->score++;
		game->pos_x = game->pos_x + x;
		game->pos_y = game->pos_y + y;
	}
	else if (game->map[game->pos_y + y][game->pos_x + x] == 'E')
	{
		if (game->collect == game->score)
			exit_game(game);
		else
			return ;
	}
	else if (game->map[game->pos_y + y][game->pos_x + x] == 'H')
		exit_game(game);
	else
	{
		game->pos_x = game->pos_x + x;
		game->pos_y = game->pos_y + y;
	}
	player_pos(game);
	put_image(game);
	count_steps(game);
}

void	set_values(t_prog *game)
{
	int	x;
	int	y;

	game->collect = 0;
	game->score = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_y = y;
				game->pos_x = x;
			}
			if (game->map[y][x] == 'C')
				game->collect++;
		}
	}
}
