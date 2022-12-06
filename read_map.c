/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:39:54 by tlumbers          #+#    #+#             */
/*   Updated: 2022/07/05 08:04:55 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map_name, t_prog *game)
{
	int		fd;
	int		i;
	char	*str;
	char	*str2;

	str2 = "init";
	i = 0;
	init_map (map_name, game);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("Error to open\n");
	while (str2)
	{
		str = get_next_line(fd);
		str2 = ft_strtrim(str, "\n");
		game->map[i] = str2;
		i++;
		free(str);
	}
	close(fd);
}

void	init_map(char *map_name, t_prog *game)
{
	int		fd;
	int		i;
	char	*str;

	str = "init";
	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("Error to open\n");
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		i++;
	}
	game->map = malloc(sizeof(char *) * (i + 1));
	if (!game->map)
		error("Malloc error\n");
	game->height = i;
	close(fd);
}
