/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:22:21 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 20:00:51 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check(t_player ***player, int j, int i)
{
	if ((**player)->map[i][j] == '0' && (**player)->map[i][j + 1] == '0'
		&& (**player)->map[i][j + 2] == '0')
	{
		(**player)->enemy.find_pos = 1;
		(**player)->enemy.x_e = j;
		(**player)->enemy.y_e = i;
		return (1);
	}
	return (0);
}

int	get_position_for_enemy(t_player **player)
{
	int			i;
	int			j;
	int			height;

	i = 0;
	height = get_height((*player)->map);
	if ((*player)->enemy.find_pos == 0)
	{
		while (i < height)
		{
			j = 0;
			while ((*player)->map[i][j])
			{
				if (check(&player, j, i))
					return (1);
				j++;
			}
			i++;
		}
		return (0);
	}
	return (1);
}
