/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_game_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:38:44 by vvu               #+#    #+#             */
/*   Updated: 2023/06/10 10:51:19 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_game *game, int width, int height, int key)
{
	game->player_exit = '0';
	if (game->map[height][width] == '1')
		return (-1);
	if (game->map[height][width] == 'C')
		game->collect--;
	if (game->map[height][width] == 'E' && game->collect > 0)
	{
		game->player_exit = 'B';
		return (1);
	}
	if (game->map[height][width] == 'E' && game->collect == 0)
	{
		game->end_game = 1;
		ft_printf("\nYou Win!!\n");
		exit_game(game);
	}
	if (key != 13 && key != 1 && key != 2 && key != 0)
		return (-1);
	else
		return (1);
}

static void	move(t_game *game, int width, int height, int key)
{
	int	valid;
	int	temp_w;
	int	temp_h;

	temp_w = game->x;
	temp_h = game->y;
	valid = valid_move(game, width, height, key);
	if (valid != -1)
	{
		game->y = height;
		game->x = width;
		if (game->player_exit != 'B')
			game->map[height][width] = 'P';
		else
			game->map[height][width] = 'B';
		if (game->map[temp_h][temp_w] != 'B')
			game->map[temp_h][temp_w] = '0';
		else
			game->map[temp_h][temp_w] = 'E';
		ft_printf("Moves: %d\n", ++(game->counter));
		if (game->height > 20 || game->width > 30)
			add_images_big(game, 0, 0, ft_itoa(game->counter));
		else if (game->height <= 20 || game->width <= 30)
			add_images(game);
	}
}

int	key_control(int key, t_game *game)
{
	int	width;
	int	height;

	width = game->x;
	height = game->y;
	if (key == 53)
		exit_game(game);
	if (key == 13)
		height--;
	if (key == 1)
		height++;
	if (key == 0)
		width--;
	if (key == 2)
		width++;
	if (game->end_game != 1)
		move(game, width, height, key);
	return (1);
}
