/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:44:04 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/16 16:29:15 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_game		game;
	t_map		*map;
	t_wrapper	wrapper;

	check_arguments(ac);
	map = read_map(av[1], &wrapper);
	wrapper.game = &game;
	wrapper.map = map;
	if (init_game(&game, map))
		error_exit(&wrapper, -2);
	if (load_sprites(&wrapper))
		error_exit(&wrapper, -2);
	distribute_collectibles(map);
	render_background(&wrapper);
	find_player_position(map);
	setup_hooks(&game, &wrapper);
	mlx_loop(game.mlx_ptr);
	return (0);
}
