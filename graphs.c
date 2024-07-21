/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:50:37 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 05:31:32 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	free_map(game->map_data->flat_map);
	exit(0);
	return (0);
}

static void	init_img_to_mlx(t_game *game)
{
	int	width;
	int	height;

	game->img_ptr.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&width, &height);
	if (!game->img_ptr.floor)
		exit_with_error("Floor image couldn't get initialized.\n", game);
	game->img_ptr.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	if (!game->img_ptr.wall)
		exit_with_error("Wall image couldn't get initialized.\n", game);
	game->img_ptr.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	if (!game->img_ptr.collectible)
		exit_with_error("Collectible image couldn't get initialized.\n", game);
	game->img_ptr.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	if (!game->img_ptr.player)
		exit_with_error("Player image couldn't get initialized.\n", game);
	game->img_ptr.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	if (!game->img_ptr.exit)
		exit_with_error("Exit image couldn't get initialized.\n", game);
}

static void	put_image(t_game *game, char c, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_ptr.floor, x,
		y);
	if (c == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_ptr.wall,
			x, y);
	else if (c == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_ptr.collectible, x, y);
	else if (c == PLAYER)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_ptr.player, x, y);
	if (c == EXIT)
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_ptr.exit,
			x, y);
}

void	put_image_to_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_data->height)
	{
		j = 0;
		while (j < game->map_data->width)
		{
			put_image(game, game->map_data->flat_map[i][j], (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	create_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit_with_error("Mlx couldn't get initialized.\n", game);
	game->mlx_window = mlx_new_window(game->mlx, (game->map_data->width * 64),
			(game->map_data->height * 64), "so_long");
	if (!(game->mlx_window))
		exit_with_error("Mlx window couldn't get initialized\n", game);
	init_img_to_mlx(game);
	put_image_to_window(game);
	mlx_hook(game->mlx_window, KEY_PRESS, 0, key_handler, game);
	mlx_hook(game->mlx_window, CROSS, 0, exit_game, game);
	mlx_loop(game->mlx);
}
