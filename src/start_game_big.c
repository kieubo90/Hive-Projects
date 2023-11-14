/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:11:42 by vvu               #+#    #+#             */
/*   Updated: 2023/06/08 17:15:19 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_too_long(t_game *game, int col)
{
	if (game->x < game->width && game->x >= game->width - 11
		&& game->width > 15)
		col = game->width - 15;
	else if (game->x > 8 && game->x < game->width - 11)
		col = game->x - 5;
	else
		col = 0;
	return (col);
}

void	add_images_big(t_game *game, int col, int line, char *str)
{
	int	i;
	int	j;

	i = 0;
	if (game->y >= game->height - 4 && game->y < game->height
		&& game->height > 10)
		line = game->height - 10;
	else if (game->y > 5 && game->y < game->height - 4)
		line = game->y - 5;
	while (i < game->height && line < game->height)
	{
		j = 0;
		col = line_too_long(game, col);
		while (j < game->width && col < game->width)
		{
			put_to_win(j, i, game->map[line][col], game);
			col++;
			j++;
		}
		line++;
		i++;
	}
	mlx_string_put(game->mlx, game->win, 10, 0, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 80, 0, 0xFFFFFF, str);
	free(str);
}

void	init_window_big(t_game *game)
{
	int	col;
	int	line;

	line = 10;
	col = 15;
	if (game->width < 15)
		col = game->width;
	if (game->height < 10)
		line = game->height;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, col * 50, line * 50, "Game");
	images_in_game(game);
	add_images_big(game, 0, 0, ft_itoa(game->counter));
	mlx_key_hook(game->win, key_control, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}
