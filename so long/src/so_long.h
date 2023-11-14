/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:13:31 by vvu               #+#    #+#             */
/*   Updated: 2023/06/15 15:22:11 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define WALL "images/wall.xpm"
# define COIN "images/coin.xpm"
# define FRONT "images/front.xpm"
# define FLOOR "images/floor.xpm"
# define DOOR_O "images/door_open.xpm"
# define DOOR_C "images/door.xpm"
# define PL_DOOR "images/player_door_close.xpm"

typedef struct s_game
{
	int		fd;
	int		height;
	int		width;
	int		player;
	int		column;
	int		exit;
	int		x;
	int		y;
	int		line;
	int		col;
	int		counter;
	int		collect;
	int		valid_collect;
	int		valid_exit;
	int		end_game;

	char	**map;
	char	**valid_map;
	char	player_exit;

	void	*wall;
	void	*floor;
	void	*player_front;
	void	*door_player;
	void	*exit_close;
	void	*exit_open;
	void	*exit_img;
	void	*collect_img;
	void	*mlx;
	void	*win;
	void	*destroy;
}	t_game;

int		exit_game(t_game *game);
int		control_move(int command, t_game *game);
int		key_control(int key, t_game *game);
int		key_control_big(int key, t_game *game);

void	exit_point(t_game *game, char *str);
void	free_valid_map(t_game *game);
void	close_image(t_game *game);
void	images_in_game(t_game *game);
void	get_map(t_game *game, char **av);
void	check_wall(t_game *game);
void	check_argument(int ac, char **av);
void	map_check_and_assign(t_game *game);
void	valid_path(t_game *game, char **av);
void	init_window(t_game *game);
void	init_window_big(t_game *game);
void	add_images(t_game *game);
void	add_images_big(t_game *game, int col, int line, char *str);
void	put_to_win(int x, int y, char c, t_game *game);
void	destroy_image(t_game *game);
#endif
