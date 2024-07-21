/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:51:02 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 05:36:11 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	calculate_height(t_map_data *map_data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_data->path, O_RDONLY);
	if (fd < 0)
		exit_with_error("The map could not be opened.", NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
	map_data->height = i;
}

static size_t	map_line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

static void	init_map(t_game *game, int fd, int height)
{
	int		i;
	char	*line;
	char	**flat_map;

	flat_map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!flat_map)
		exit_with_error("Memory allocation is failed.", game);
	flat_map[height] = NULL;
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		if (!line)
			exit_with_error("There is no line or couldn't get properly.", game);
		flat_map[i] = ft_substr(line, 0, map_line_len(line));
		if ((i == height - 1) && (line[ft_strlen(line) - 1] == '\n'))
			exit_with_error("Ending of the map is incorrect.\n", game);
		free(line);
		i++;
	}
	game->map_data->flat_map = flat_map;
}

void	create_map(t_game *game)
{
	int	fd;

	fd = open(game->map_data->path, O_RDONLY);
	if (fd < 0)
		exit_with_error("The map could not be opened.", game);
	calculate_height(game->map_data);
	init_map(game, fd, game->map_data->height);
	close(fd);
}
