/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:28:08 by sramasam          #+#    #+#             */
/*   Updated: 2025/12/16 22:13:40 by sramasam         ###   ########.fr       */
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

// GAME CONSTANTS
# define TILE_SIZE 64

// KEYBOARD CONTROLS
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_ESC 0xff1b

// STRUCTS
typedef struct	s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct	s_sprite
{
	void	*img;
}	t_sprite;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int	width;
	int	height;
	int	move_count;
	int	collectible_count;
	int	path_collected_count;
	int	path_exit_found;
	t_pos	player_pos;
	t_sprite	player;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	collectible;
	t_sprite	exit;
}	t_game;

// CORE FUNCTIONS
