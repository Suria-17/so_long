/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:28:08 by sramasam          #+#    #+#             */
/*   Updated: 2025/12/17 12:28:17 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

//GAME CONSTANTS
# define TILE_SIZE 64

//KEYBOARD CONTROLS
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_ESC 0xff1b

//STRUCTS
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_texture
{
	void	*img;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	player;
	t_texture	wall;
	t_texture	empty;
	t_texture	collectible;
	t_texture	exit;
	char		**map;
	int			width;
	int			height;
	void		*img;
	t_pos		player_pos;
	int			collectible_count;
	int			move_count;
	int			path_collected_count;
	int			path_exit_found;
}	t_game;

//CORE FUNCTIONS
void	cleanup(t_game *game);
int		setup_window(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);

//PLAYER MOVEMENT
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);

//MAP HANDLING & VALIDATION
void	free_map(char **map, int height);
char	**get_map(char *file_name, t_game *game);
int		is_map_valid(char **map, int height, int width, t_game *game);
int		check_empty_lines(const char *buf);

//PATH VALIDATION
int		flood_fill(char **map, int height, int width, t_game *game);
int		path_checker(char **map, t_pos player, t_game *game, int height);

//ERROR HANDLING
int		return_error(char *message);
void	*return_error_null(char *message);

#endif
