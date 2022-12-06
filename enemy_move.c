/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:40:14 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:11:13 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_prog *game, char *steps, char *path)
{
	game->enemy.image = mlx_xpm_file_to_image (game->mlx_ptr, path,
			&game->enemy.width, &game->enemy.height);
	put_image(game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 86, 86, COLOR, "Steps - ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 166, 86, COLOR, steps);
}	

int	counter(t_prog *game)
{
	static int			g;
	char				*steps;

	steps = ft_itoa(game->steps);
	g++;
	move_enemy(game);
	if (g == 1000)
		draw_enemy(game, steps, ENEMY);
	if (g == 2000)
		draw_enemy(game, steps, ENEMY2);
	if (g == 3000)
		draw_enemy(game, steps, ENEMY3);
	if (g == 4000)
		draw_enemy(game, steps, ENEMY4);
	if (g > 5000)
		g = 0;
	free(steps);
	return (0);
}

void	enemy_pos(t_prog *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H')
			{
				game->map[i][j] = '0';
				break ;
			}
		}
	}
	game->map[game->enemy_y][game->enemy_x] = 'H';
}

void	set_enemy_pos(t_prog *game, int x, int y)
{
	if (game->map[game->enemy_y][game->enemy_x + x] == '1')
		return ;
	else if (game->map[game->enemy_y][game->enemy_x + x] == 'C')
		return ;
	else if (game->map[game->enemy_y][game->enemy_x + x] == 'E')
		return ;
	else if (game->map[game->enemy_y][game->enemy_x + x] == 'P')
		exit_game(game);
	else
	{
		game->enemy_x = game->enemy_x + x;
		game->enemy_y = game->enemy_y + y;
	}
	enemy_pos(game);
	put_image(game);
}

int	move_enemy(t_prog *game)
{
	static int	g;

	g++;
	if (g == 1000)
		set_enemy_pos(game, -1, 0);
	if (g == 2000)
		set_enemy_pos(game, -1, 0);
	if (g == 3000)
		set_enemy_pos(game, 1, 0);
	if (g == 4000)
		set_enemy_pos(game, 1, 0);
	if (g > 5000)
		g = 0;
	return (0);
}
