/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:38:23 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:12:52 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_rectangular(t_prog *game)
{
	int		i;

	i = 1;
	game->width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->width)
			error("Error\nMap is not rectangular\n");
		i++;
	}
}

void	check_walls(t_prog *game)
{
	int	i;
	int	x;
	int	y;

	game->height = i;
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			error("Error\nWalls error\n");
		x++;
	}	
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			error("Error\nWalls error\n");
		y++;
	}
}

void	map_checker(t_prog *game)
{
	check_map_rectangular(game);
	check_walls(game);
	check_symbols(game);
	set_values(game);
}
