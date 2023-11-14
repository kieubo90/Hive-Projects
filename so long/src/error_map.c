/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:17:24 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 13:24:57 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_horizon_vertical_wall(t_game *game)
{
	int	check;
	int	height;
	int	width;

	width = game->width;
	height = game->height;
	check = 0;
	while (check < width)
	{
		if (!(game->map[0][check] == '1'
			&& game->map[height - 1][check] == '1'))
			return (0);
		check++;
	}
	check = 0;
	while (check < height)
	{
		if (!(game->map[check][0] == '1' && game->map[check][width - 1] == '1'))
			return (0);
		check++;
	}
	return (1);
}	

static int	check_rectangular(t_game *game)
{
	int	height;
	int	width;

	height = game->height;
	width = game->width;
	if (height == width)
		return (0);
	return (1);
}

void	check_wall(t_game *game)
{
	int	check_wall;
	int	check_rec;

	check_rec = check_rectangular(game);
	check_wall = check_horizon_vertical_wall(game);
	if (!check_rec)
		exit_point(game, "Error\nThe map is not rectangular\n");
	if (!check_wall)
		exit_point(game, "Error\nMap is not surrounded by 1\n");
}
