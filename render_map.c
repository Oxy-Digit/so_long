/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:39:26 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:04:08 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_image(t_prog *game)
{
	game->wall.image = mlx_xpm_file_to_image(game->mlx_ptr, WALL,
			&game->wall.width, &game->wall.height);
	game->ground.image = mlx_xpm_file_to_image (game->mlx_ptr, GROUND,
			&game->ground.width, &game->ground.height);
	game->player.image = mlx_xpm_file_to_image (game->mlx_ptr, PLAYER,
			&game->player.width, &game->player.height);
	game->collectable.image = mlx_xpm_file_to_image (game->mlx_ptr, COLLECTABLE,
			&game->collectable.width, &game->collectable.height);
	game->exit.image = mlx_xpm_file_to_image (game->mlx_ptr, EXIT,
			&game->exit.width, &game->exit.height);
	game->enemy.image = mlx_xpm_file_to_image (game->mlx_ptr, ENEMY,
			&game->enemy.width, &game->enemy.height);
	return (0);
}

int	put_image(t_prog *game)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			put_image1(game, x, y);
	}
	return (0);
}

void	put_image1(t_prog *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->ground.image, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.image, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->ground.image, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player.image, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.image, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectable.image, x * 64, y * 64);
	else if (game->map[y][x] == 'H')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->enemy.image, x * 64, y * 64);
}
