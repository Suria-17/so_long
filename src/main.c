/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:41 by sramasam          #+#    #+#             */
/*   Updated: 2025/12/17 10:27:32 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		return_error("Invalid number of arguments");
		return (1);
	}
	game.map = get_map(av[1], &game);
	if (game.map == NULL)
		return (1);
	setup_window(&game);
	return (0);
}
