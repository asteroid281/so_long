/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:47:22 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/21 03:04:44 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define FLOOR '0'
# define WALL '1'

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

# define KEY_PRESS 02
# define CROSS 17

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_map_data
{
	char		**flat_map;
	char		*path;
	int			width;
	int			height;
}				t_map_data;

typedef struct s_img
{
	void		*floor;
	void		*wall;
	void		*collectible;
	void		*player;
	void		*exit;
}				t_img;

typedef struct s_game
{
	t_map_data	*map_data;
	void		*mlx;
	void		*mlx_window;
	int			collectible_count;
	int			move_count;
	t_img		img_ptr;
	t_player	player;
	t_exit		exit;
}				t_game;

typedef struct s_count
{
	int			exit;
	int			player;
	int			collectible;
}				t_count;

void			map_name_check(char *file_name, t_game *game);
void			create_map(t_game *game);
void			exit_with_error(char *error_message, t_game *game);
void			map_format_check(t_game *game);
void			map_path_check(t_game *game);
void			create_game(t_game *game);
void			put_image_to_window(t_game *game);
int				key_handler(int key_code, t_game *game);
int				exit_game(t_game *game);
void			free_map(char **map);

#endif
