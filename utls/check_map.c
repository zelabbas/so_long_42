/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:34 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 16:42:31 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	message_error(t_player ***player)
{
	int	x;

	x = 0;
	while ((**player)->map[x])
	{
		free((**player)->map[x]);
		x++;
	}
	free((**player)->map);
	perror("\033[1;32m🛑ERROR: Map is not surrounded by walls!\033[0m");
	perror("\033[1;32m🛑ERROR: or Map is not rectangular!\033[0m");
	exit(1);
}

int	check_row(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map_is_rectangular(t_player **player)
{
	int	firstrowlength;
	int	rows;
	int	i;

	rows = get_height((*player)->map);
	firstrowlength = ft_strlen((*player)->map[0]);
	i = 1;
	while (i < rows)
	{
		if (ft_strlen((*player)->map[i]) != firstrowlength)
			message_error(&player);
		i++;
	}
	if (firstrowlength == rows)
		message_error(&player);
}

void	check_surrounded_walls(t_player **player)
{
	int	rows;
	int	i;
	int	columns;

	i = 0;
	rows = get_height((*player)->map);
	columns = get_width((*player)->map);
	if (rows == 0 || columns == 0)
		message_error(&player);
	if (!check_row((*player)->map[0]) || !check_row((*player)->map[rows - 1]))
		message_error(&player);
	while (rows > i)
	{
		if ((*player)->map[i][0] != '1' ||
			(*player)->map[i][columns - 1] != '1')
			message_error(&player);
		i++;
	}
}

void	check_map_is_valide(t_player *player)
{
	check_surrounded_walls(&player);
	check_map_is_rectangular(&player);
	check_elements(&player);
	get_position_player(&player);
	check_map_path(&player);
}
