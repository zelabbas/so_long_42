/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:27:00 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 12:38:43 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_door(t_player ***player)
{
	int	i;

	i = 0;
	while ((**player)->map[i])
	{
		free((**player)->map[i]);
		i++;
	}
	free((**player)->map);
	mlx_destroy_window((**player)->mlx, (**player)->win);
	ft_putstr("YOU WON");
	exit(1);
}

void	ft_error_argc(int ac)
{
	if (ac == 1)
	{
		perror("\033[1;35m🛑ERROR: no such file!\033[0m");
		exit(1);
	}
	if (ac > 2)
	{
		perror("\033[1;35m🛑ERROR: there is more then one map\033[0m");
		exit(1);
	}
}

void	exit_error_path_map(t_player ***player)
{
	int	i;

	i = 0;
	while ((**player)->map[i])
	{
		free((**player)->map[i]);
		i++;
	}
	free((**player)->map);
	exit(1);
}

void	get_position_player(t_player **player)
{
	int	i;
	int	j;

	i = 0;
	(*player)->count_collection = 0;
	while ((*player)->map[i])
	{
		j = 0;
		while ((*player)->map[i][j])
		{
			if ((*player)->map[i][j] == 'P')
			{
				(*player)->y_p = i;
				(*player)->x_p = j;
			}
			if ((*player)->map[i][j] == 'C')
				(*player)->count_collection++;
			j++;
		}
		i++;
	}
}

void	open_exit(t_player **player)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*player)->map);
	while (y < height)
	{
		x = 0;
		while ((*player)->map[y][x])
		{
			if ((*player)->map[y][x] == 'E')
			{
				(*player)->img = mlx_xpm_file_to_image((*player)->mlx,
						"./textures/open_door.xpm", &img_w, &img_h);
				ft_load_img_error(&player);
				mlx_put_image_to_window((*player)->mlx, (*player)->win,
					(*player)->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
