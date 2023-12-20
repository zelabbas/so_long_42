/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:30:49 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 20:36:16 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	free_copied_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **original_map, int height)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc((height + 1) * sizeof(char *));
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(original_map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
