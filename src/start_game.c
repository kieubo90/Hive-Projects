/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:14:02 by vvu               #+#    #+#             */
/*   Updated: 2023/06/10 12:47:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_in_game(t_game *game)
{
	int	i;

	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &i, &i);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, COIN, &i, &i);
	game->player_front = mlx_xpm_file_to_image(game->mlx, FRONT, &i, &i);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &i, &i);
	game->exit_close = mlx_xpm_file_to_image(game->mlx, DOOR_C, &i, &i);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, DOOR_O, &i, &i);
	game->door_player = mlx_xpm_file_to_image(game->mlx, PL_DOOR, &i, &i);
}

static void	line_too_long(int x, int y, char c, t_game *game)
{
	if (c == 'E')
	{
		if (game->collect == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->floor, x * 50, y * 50);
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_open, x * 50, y * 50);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_close, x * 50, y * 50);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, x * 50, y * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect_img, x * 50, y * 50);
	}
}

void	put_to_win(int x, int y, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, x * 50, y * 50);
	if (c == 'B')
		mlx_put_image_to_window(game->mlx, game->win,
			game->door_player, x * 50, y * 50);
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, x * 50, y * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_front, x * 50, y * 50);
	}
	if (c == 'E')
		line_too_long(x, y, c, game);
	if (c == 'C')
		line_too_long(x, y, c, game);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, x * 50, y * 50);
}

void	add_images(t_game *game)
{
	int		x;
	int		y;
	char	*str;

	str = ft_itoa(game->counter);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_to_win(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, 10, 0, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 80, 0, 0xFFFFFF, str);
	free(str);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 50,
			game->height * 50, "Game");
	images_in_game(game);
	add_images(game);
	mlx_key_hook(game->win, key_control, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}
