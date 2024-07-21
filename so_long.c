/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:46:12 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 03:43:03 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	static t_game		game;
	static t_map_data	map_data;

	game.map_data = &map_data;
	if (ac == 2)
	{
		map_name_check(av[1], &game);
		game.map_data->path = av[1];
		create_map(&game);
		map_format_check(&game);
		if (game.map_data->height > 22 || game.map_data->width > 38)
			exit_with_error("Game window extends from screen.\n", &game);
		create_game(&game);
		free_map(game.map_data->flat_map);
	}
	else
		ft_printf("2 arguments must be entered.\n");
	return (0);
}
