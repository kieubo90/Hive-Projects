/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:31:13 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 13:26:48 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argument(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./so_long (map_name).ber\n");
		exit(0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
	{
		ft_printf("Error\nPlease use: (map_name).ber\n");
		exit(0);
	}
}

static void	check_char(t_game *game, char c, int line, int col)
{
	if (c == 'C')
		game->collect++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->x = col;
		game->y = line;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		exit_point(game, "Error\nDetect wrong character\n");
}

static void	check_map_condition(t_game *game)
{
	if (game->collect == 0)
		exit_point(game, "Error\nMap has no collectible\n");
	else if (game->exit == 0)
		exit_point(game, "Error\nMap has no exit\n");
	else if (game->exit > 1)
		exit_point(game, "Error\nMap has too many exit\n");
	else if (game->player == 0)
		exit_point(game, "Error\nMap has no player\n");
	else if (game->player > 1)
		exit_point(game, "Error\nMap has too many player\n");
}

void	map_check_and_assign(t_game *game)
{
	int		col;
	int		line;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			check_char(game, game->map[line][col], line, col);
			col++;
		}
		line++;
	}
	check_map_condition(game);
}
