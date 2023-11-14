/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:51:50 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 13:23:41 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_col(t_game *game, char **av)
{
	char	*col;
	int		count;
	int		fd;
	int		check;

	fd = open(av[1], O_RDONLY);
	check = 0;
	count = 0;
	while (1)
	{
		if (check != count && check != 0)
			exit_point(game, "Error\nThe map is not rectangular\n");
		check = count;
		col = get_next_line(fd);
		if (!col)
			break ;
		count = ft_strlen(col) - 1;
		free(col);
	}
	game->width = count;
	close(fd);
}

static void	map_line(t_game *game, char **av)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	if (count == 0)
		exit_point(game, "Error\nFile is empty\n");
	game->height = count;
	close(fd);
}

void	get_map(t_game *game, char **av)
{
	char	*line;
	int		height;
	int		i;

	i = 0;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		exit_point(game, "Error\nfile open\n");
	map_line(game, av);
	map_col(game, av);
	height = game->height + 1;
	game->map = (char **)malloc(sizeof(char *) * height);
	if (!game->map)
		exit_point(game, "Error\nmalloc\n");
	while (i < height)
	{
		line = get_next_line(game->fd);
		game->map[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
	}
}
