/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:22:50 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 16:50:26 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->exit_close);
	mlx_destroy_image(game->mlx, game->exit_open);
	mlx_destroy_image(game->mlx, game->player_front);
	mlx_destroy_image(game->mlx, game->wall);
}

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

void	exit_point(t_game *game, char *str)
{
	int	line;

	line = 0;
	if (game->fd < 0)
	{
		ft_printf("%s", str);
		close(game->fd);
	}
	else
		ft_printf("%s", str);
	if (game->map)
	{
		while (line < game->height)
			free(game->map[line++]);
		free(game->map);
	}
	exit(0);
}

int	exit_game(t_game *game)
{
	int	line;

	destroy_image(game);
	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	close(game->fd);
	exit(0);
}
