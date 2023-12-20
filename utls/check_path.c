/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:23:06 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 18:30:26 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	flood_fill_exit(char **map, int x, int y, t_player ***player)
{
	bool	reached;

	if (x <= 0 || y <= 0 || x >= (**player)->cols || y >= (**player)->rows
		|| map[y][x] == '1' || map[y][x] == 'V')
		return (false);
	if (map[y][x] == 'E')
		return (true);
	map[y][x] = 'V';
	reached = (flood_fill_exit(map, x + 1, y, player)
			|| flood_fill_exit(map, x - 1, y, player)
			|| flood_fill_exit(map, x, y + 1, player)
			|| flood_fill_exit(map, x, y - 1, player));
	return (reached);
}

int	flood_fill_collectibles(char **map, int x, int y, t_player ***player)
{
	int		reached;

	reached = 0;
	if (x <= 0 || y <= 0 || x >= (**player)->cols || y >= (**player)->rows
		|| map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'C')
		reached++;
	map[y][x] = 'V';
	reached += flood_fill_collectibles(map, x + 1, y, player);
	reached += flood_fill_collectibles(map, x - 1, y, player);
	reached += flood_fill_collectibles(map, x, y + 1, player);
	reached += flood_fill_collectibles(map, x, y - 1, player);
	return (reached);
}

bool	valid_path_collectibles(t_player **player)
{
	char	**new_map;
	int		res;

	(*player)->rows = get_height((*player)->map);
	(*player)->cols = get_width((*player)->map);
	new_map = copy_map((*player)->map, (*player)->rows);
	res = flood_fill_collectibles(new_map, (*player)->x_p,
			(*player)->y_p, &player);
	free_copied_map(new_map, (*player)->rows);
	if (res != (*player)->count_collection)
		perror("\033[1;34m🛑ERROR: no path to all collectibles\n\033[0m");
	return (res == (*player)->count_collection);
}

bool	valid_path_exit(t_player **player)
{
	char	**new_map;
	bool	res;

	(*player)->rows = get_height((*player)->map);
	(*player)->cols = get_width((*player)->map);
	new_map = copy_map((*player)->map, (*player)->rows);
	res = flood_fill_exit(new_map, (*player)->x_p, (*player)->y_p, &player);
	free_copied_map(new_map, (*player)->rows);
	if (!res)
		perror("\033[1;34m🛑ERROR: no path to exit\n\033[0m");
	return (res);
}

void	check_map_path(t_player **player)
{
	if (!valid_path_exit(player) || !valid_path_collectibles(player))
		exit_error_path_map(&player);
}
