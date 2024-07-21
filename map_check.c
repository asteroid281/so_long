/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:47:02 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 05:28:17 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	map_name_check(char *map_name, t_game *game)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (len < 4 || map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
		|| map_name[len - 3] != 'b' || map_name[len - 4] != '.')
		exit_with_error("File name extension is not valid.\n", game);
}

static void	wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_data->width)
	{
		if ((game->map_data->flat_map[0][i] == WALL)
			&& (game->map_data->flat_map[game->map_data->height
				- 1][i] == WALL))
			i++;
		else
			exit_with_error("Map's up or down frame is not valid.\n", game);
	}
	i = 1;
	while (i < game->map_data->height - 1)
	{
		if (game->map_data->flat_map[i][0] == WALL
			&& game->map_data->flat_map[i][game->map_data->width - 1] == WALL)
			i++;
		else
			exit_with_error("Map's left or right frame is not valid.\n", game);
	}
}

static void	component_check(t_game *game, int i, int j, t_count *count)
{
	char	*arr;

	arr = game->map_data->flat_map[i];
	while (j < game->map_data->width)
	{
		if ((arr[j] != WALL) && (arr[j] != FLOOR) && (arr[j] != PLAYER)
			&& (arr[j] != COLLECTIBLE) && (arr[j] != EXIT))
			exit_with_error("Invalid component.\n", game);
		if (arr[j] == PLAYER)
		{
			(count->player)++;
			(game->player).x = j;
			(game->player).y = i;
		}
		else if (arr[j] == COLLECTIBLE)
			(count->collectible)++;
		else if (arr[j] == EXIT)
		{
			(count->exit)++;
			(game->exit).x = j;
			(game->exit).y = i;
		}
		j++;
	}
}

static void	map_component_check(t_game *game)
{
	int		i;
	t_count	count;

	count.collectible = 0;
	count.exit = 0;
	count.player = 0;
	i = 0;
	while (i < game->map_data->height)
	{
		component_check(game, i, 0, &count);
		i++;
	}
	if ((count.collectible < 1) || (count.exit != 1) || (count.player != 1))
		exit_with_error("Number of components is not valid.\n", game);
	game->collectible_count = count.collectible;
}

void	map_format_check(t_game *game)
{
	int	i;
	int	line_len;
	int	tmp_len;

	if (game->map_data->flat_map[0] == NULL)
		exit_with_error("Map is empty.\n", game);
	i = 0;
	line_len = ft_strlen(game->map_data->flat_map[0]);
	while (i < game->map_data->height)
	{
		tmp_len = ft_strlen(game->map_data->flat_map[i]);
		if (tmp_len == 0)
			exit_with_error("Map is incomplete.\n", game);
		if (line_len != tmp_len) 
			exit_with_error("Map is not rectangular.\n", game);
		i++;
	}
	game->map_data->width = line_len;
	wall_check(game);
	map_component_check(game);
	map_path_check(game);
}
