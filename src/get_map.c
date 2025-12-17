/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:30:00 by sramasam          #+#    #+#             */
/*   Updated: 2025/12/17 10:30:21 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (1);
	if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
		return (1);
	return (0);
}

static char	*file_reading(int fd)
{
	char	*line;
	char	*buf;
	char	*temp;

	buf = ft_calloc(1, 1);
	if (buf == NULL)
		exit(0);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		if (!temp)
			return (NULL);
		buf = temp;
		line = get_next_line(fd);
	}
	return (buf);
}

static	char	*read_and_validate_file(char *file_path)
{
	int		fd;
	char	*buf;

	if (check_file_name(file_path) == 1)
	{
		return_error("Invalid file extension");
		return (NULL);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (return_error_null("Failed to open file"));
	buf = file_reading(fd);
	if (buf == NULL || check_empty_lines(buf) == 1)
	{
		return_error("Invalid map: Empty lines or read error");
		return (NULL);
	}
	return (buf);
}

static void	get_dimensions(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		y++;
	}
	game->height = y;
	game->width = x;
}

char	**get_map(char *file_name, t_game *game)
{
	char	**map;
	char	*buf;

	buf = read_and_validate_file(file_name);
	if (buf == NULL)
		return (NULL);
	map = ft_split(buf, '\n');
	free(buf);
	if (!map)
		exit(0);
	get_dimensions(map, game);
	if (is_map_valid(map, game->height, game->width, game) == 1)
	{
		free_map(map, game->height);
		return (NULL);
	}
	return (map);
}
