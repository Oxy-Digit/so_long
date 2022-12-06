/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:38:35 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:08:10 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_symbols_enemy(t_prog *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'H')
			{
				game->flag_enemy = 1;
				game->enemy_y = i;
				game->enemy_x = j;
			}
		}
	}
}

static void	count_symbols(t_prog *game, int *players, int *colls, int *exits)
{
	int	i;
	int	j;

	i = -1;
	*players = 0;
	*colls = 0;
	*exits = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'P')
				(*players)++;
			if (game->map[i][j] == 'C')
				(*colls)++;
			if (game->map[i][j] == 'E')
				(*exits)++;
			count_symbols_enemy(game);
		}
	}
}

void	check_symbols(t_prog *game)
{
	int	i;
	int	j;
	int	players;
	int	colls;
	int	exits;

	j = 0;
	count_symbols(game, &players, &colls, &exits);
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'P' || game->map[j][i] == 'E'
					|| game->map[j][i] == '1' || game->map[j][i] == 'C'
					|| game->map[j][i] == '0' || game->map[j][i] == 'H')
				i++;
			else
				error("Error\nInvalid symbol\n");
		}
		j++;
	}
	if (players != 1 || colls < 1 || exits != 1)
		error("Error\nInvalid number of spec symbols\n");
}
