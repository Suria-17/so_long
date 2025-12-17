/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:39:17 by sramasam          #+#    #+#             */
/*   Updated: 2025/12/17 10:39:25 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_error(char *message)
{
	ft_printf("Error : %s\n", message);
	return (1);
}

int	check_empty_lines(const char *buf)
{
	int	i;
	int	newline_count;

	i = 0;
	newline_count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			newline_count++;
			if (newline_count > 1)
				return (1);
		}
		else
			newline_count = 0;
		i++;
	}
	return (0);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
