/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:31:31 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 11:48:05 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_valid_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->valid_map[i])
	{
		free(game->valid_map[i]);
		i++;
	}
	free(game->valid_map);
}

void	close_image(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player_front)
		mlx_destroy_image(game->mlx, game->player_front);
	if (game->exit_close)
		mlx_destroy_image(game->mlx, game->exit_close);
	if (game->exit_open)
		mlx_destroy_image(game->mlx, game->exit_open);
}

int	exit_game(t_game *game)
{
	int	line;

	close_image(game);
	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	close(game->fd);
	exit(0);
}
