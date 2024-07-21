/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:48:27 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 02:48:31 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_map(char **map_data)
{
	int	i;

	if (map_data == NULL)
		exit(0);
	i = 0;
	while (map_data[i] != NULL)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}

void	exit_with_error(char *error_message, t_game *game)
{
	ft_printf(error_message);
	if (!game)
		exit(1);
	if (game->map_data->flat_map)
		free_map(game->map_data->flat_map);
	exit(1);
}
