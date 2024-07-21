/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:51:21 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 02:51:54 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	flood_fill(int y, int x, char **copied_flat_map,
		t_map_data *map_data)
{
	if ((y < 0) || (y > map_data->height - 1) || (x < 0) || (x > map_data->width
			- 1))
		return ;
	if (copied_flat_map[y][x] != '1' && copied_flat_map[y][x] != 'F')
	{
		copied_flat_map[y][x] = 'F';
		flood_fill(y - 1, x, copied_flat_map, map_data);
		flood_fill(y + 1, x, copied_flat_map, map_data);
		flood_fill(y, x - 1, copied_flat_map, map_data);
		flood_fill(y, x + 1, copied_flat_map, map_data);
	}
}

static char	**create_flat_map(t_map_data *map_data)
{
	char	**flat_map;
	int		i;

	flat_map = (char **)malloc((sizeof(char *) * map_data->height) + 1);
	if (!flat_map)
		exit_with_error("Flat map couldn't get.", NULL);
	flat_map[map_data->height] = NULL;
	i = 0;
	while (i < map_data->height)
	{
		flat_map[i] = ft_strdup(map_data->flat_map[i]);
		i++;
	}
	return (flat_map);
}

void	map_path_check(t_game *game)
{
	int		i;
	int		j;
	char	**copied_flat_map;

	copied_flat_map = create_flat_map(game->map_data);
	flood_fill((game->player).y, (game->player).x, copied_flat_map,
		game->map_data);
	i = 0;
	while (i < game->map_data->height)
	{
		j = 0;
		while (j < game->map_data->width)
		{
			if ((copied_flat_map[i][j] == EXIT)
				|| (copied_flat_map[i][j] == COLLECTIBLE))
			{
				exit_with_error("The map is not playable.\n", game);
				free_map(copied_flat_map);
			}
			j++;
		}
		i++;
	}
	free_map(copied_flat_map);
}
