/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:49:04 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 05:49:08 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	move(t_game *game, int step_x, int step_y)
{
	char	next;
	char	current;

	current = game->map_data->flat_map[(game->player).y][(game->player).x];
	next = game->map_data->flat_map[(game->player).y + step_y][(game->player).x
		+ step_x];
	if (next != WALL)
	{
		(game->move_count)++;
		ft_printf("Move: %d\n", game->move_count);
		if (next == COLLECTIBLE)
			game->collectible_count--;
		if (current != EXIT)
		{
			game->map_data->flat_map[game->player.y][game->player.x] = FLOOR;
			game->map_data->flat_map[game->exit.y][game->exit.x] = EXIT;
		}
		game->map_data->flat_map[(game->player).y + step_y][(game->player).x
			+ step_x] = PLAYER;
		game->player.x = game->player.x + step_x;
		game->player.y = game->player.y + step_y;
		if ((next == EXIT) && (game->collectible_count == 0))
			return (1);
	}
	return (0);
}

int	key_handler(int key_code, t_game *game)
{
	int	move_response;

	if (key_code == ESC)
		exit_game(game);
	if (key_code == W || key_code == UP)
		move_response = move(game, 0, -1);
	else if (key_code == S || key_code == DOWN)
		move_response = move(game, 0, 1);
	else if (key_code == D || key_code == RIGHT)
		move_response = move(game, 1, 0);
	else if (key_code == A || key_code == LEFT)
		move_response = move(game, -1, 0);
	else
		return (0);
	if (move_response == 1)
	{
		ft_printf("Itadori Yuji collected all the fingers in %d moves!\n",
			game->move_count);
		exit_game(game);
	}
	put_image_to_window(game);
	return (0);
}
