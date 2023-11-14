/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:31:28 by vvu               #+#    #+#             */
/*   Updated: 2023/06/06 11:34:49 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	check_argument(ac, av);
	ft_memset(&game, 0, sizeof(t_game));
	get_map(&game, av);
	check_wall(&game);
	map_check_and_assign(&game);
	valid_path(&game, av);
	if (game.height > 20 || game.width > 30)
		init_window_big(&game);
	else
		init_window(&game);
	return (0);
}
