/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 06:54:05 by vvu               #+#    #+#             */
/*   Updated: 2023/06/10 11:33:34 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_path(t_game *game, char **av)
{
	char	*line;
	int		i;
	int		y;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	y = game->height + 1;
	game->valid_map = (char **)malloc(sizeof(char *) * y);
	if (!game->valid_map)
		exit_point(game, "Error\nMalloc in find path\n");
	while (i < y)
	{
		line = get_next_line(fd);
		game->valid_map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	close(fd);
}

static bool	check_path_expand(t_game *game, char c, int line, int col)
{
	if (line < 0 || col < 0 || line >= game->height || col >= game->width)
		return (false);
	else if (game->valid_map[line][col] == 'X')
		return (false);
	else if (game->valid_map[line][col] == '1')
		return (false);
	else if (game->valid_map[line][col] == 'E')
		game->valid_exit++;
	if (game->valid_map[line][col] == 'C')
		game->valid_collect++;
	game->valid_map[line][col] = 'X';
	check_path_expand(game, c, line + 1, col);
	check_path_expand(game, c, line - 1, col);
	check_path_expand(game, c, line, col + 1);
	check_path_expand(game, c, line, col - 1);
	return (game->valid_collect == game->collect && game->valid_exit);
}

static int	check_path(t_game *game)
{
	char	c;
	int		line;
	int		col;
	bool	valid;

	c = game->valid_map[game->y][game->x];
	line = game->y;
	col = game->x;
	valid = check_path_expand(game, c, line, col);
	return (valid);
}

void	valid_path(t_game *game, char **av)
{
	map_path(game, av);
	if (!check_path(game))
	{
		free_valid_map(game);
		exit_point(game, "Error\nPath is not valid\n");
	}
	free_valid_map(game);
}
