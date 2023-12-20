/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:26 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 17:11:57 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_player ***player)
{
	int	x;

	x = 0;
	while ((**player)->map[x])
	{
		free((**player)->map[x]);
		x++;
	}
	free((**player)->map);
	perror("\033[1;31m🛑ERROR: invalide map!\033[0m");
	exit(1);
}

void	invalide_elements(t_player ***player, t_arg_map *map)
{
	if (map->c == 0)
		perror("\033[1;31m🛑ERROR:there is no collection in the map!\033[0m");
	if (map->e == 0)
		perror("\033[1;31m🛑ERROR:there is no exit in the map!\033[0m");
	if (map->e > 1)
		perror("\033[1;31m🛑ERROR:there is a muliple exit in the map!\033[0m");
	if (map->p == 0)
		perror("\033[1;31m🛑ERROR:there is no position!\033[0m");
	if (map->p > 1)
		perror("\033[1;31m🛑ERROR:there is multiple position!\033[0m");
	ft_error(player);
}

void	check_elements(t_player **player)
{
	t_arg_map	map;

	map.c = 0;
	map.e = 0;
	map.p = 0;
	map.y = get_height((*player)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*player)->map[map.y][map.x] != '\0')
		{
			if ((*player)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*player)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*player)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*player)->map[map.y][map.x] != '1'
				&& (*player)->map[map.y][map.x] != '0')
				ft_error(&player);
			map.x++;
		}
	}
	if (map.c == 0 || map.e == 0 || map.e > 1 || map.p == 0 || map.p > 1)
		invalide_elements(&player, &map);
}
