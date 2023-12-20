/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:22:10 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 13:05:33 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	collected(t_player ***player)
{
	int		img_w;
	int		img_h;

	(**player)->collectes--;
	(**player)->map[((**player)->y_p / 50)][((**player)->x_p / 50)] = '0';
	(**player)->img = mlx_xpm_file_to_image(
			(**player)->mlx, "./textures/floor.xpm", &img_w, &img_h);
	ft_load_img_error(player);
	mlx_put_image_to_window((**player)->mlx, (**player)->win,
		(**player)->img, (**player)->x_p, (**player)->y_p);
}

void	to_left(t_player **player)
{
	put_image_floor_or_player(player, 'f', 0);
	if ((*player)->map[((*player)->y_p / 50)][((*player)->x_p / 50) - 1] == 'E')
	{
		if ((*player)->collectes <= 0)
			exit_door(&player);
	}
	else if ((*player)->map[((*player)->y_p / 50)]
		[((*player)->x_p / 50) - 1] != '1')
	{
		(*player)->x_p -= 50;
		display_movement(&player);
	}
	if ((*player)->map[((*player)->y_p / 50)][((*player)->x_p / 50)] == 'C')
		collected(&player);
	put_image_floor_or_player(player, 'p', 'l');
	if ((*player)->collectes <= 0)
		open_exit(player);
}

void	to_right(t_player **player)
{
	put_image_floor_or_player(player, 'f', 0);
	if ((*player)->map[((*player)->y_p / 50)][((*player)->x_p / 50) + 1] == 'E')
	{
		if ((*player)->collectes <= 0)
			exit_door(&player);
	}
	else if ((*player)->map[(*player)->y_p / 50]
		[((*player)->x_p / 50) + 1] != '1')
	{
		(*player)->x_p += 50;
		display_movement(&player);
	}
	if ((*player)->map[(*player)->y_p / 50][((*player)->x_p / 50)] == 'C')
		collected(&player);
	put_image_floor_or_player(player, 'p', 'r');
	if ((*player)->collectes <= 0)
		open_exit(player);
}

void	to_top(t_player **player)
{
	put_image_floor_or_player(player, 'f', 0);
	if ((*player)->map[((*player)->y_p / 50) - 1][((*player)->x_p / 50)] == 'E')
	{
		if ((*player)->collectes <= 0)
			exit_door(&player);
	}
	else if ((*player)->map[((*player)->y_p / 50) - 1]
		[((*player)->x_p / 50)] != '1')
	{
		(*player)->y_p -= 50;
		display_movement(&player);
	}
	if ((*player)->map[((*player)->y_p / 50)][((*player)->x_p / 50)] == 'C')
		collected(&player);
	put_image_floor_or_player(player, 'p', 'r');
	if ((*player)->collectes <= 0)
		open_exit(player);
}

void	to_bottom(t_player **player)
{
	put_image_floor_or_player(player, 'f', 0);
	if ((*player)->map[((*player)->y_p / 50) + 1][((*player)->x_p / 50)] == 'E')
	{
		if ((*player)->collectes <= 0)
			exit_door(&player);
	}
	else if ((*player)->map[((*player)->y_p / 50) + 1]
		[((*player)->x_p / 50)] != '1')
	{
		(*player)->y_p += 50;
		display_movement(&player);
	}
	if ((*player)->map[((*player)->y_p / 50)][((*player)->x_p / 50)] == 'C')
		collected(&player);
	put_image_floor_or_player(player, 'p', 'r');
	if ((*player)->collectes <= 0)
		open_exit(player);
}
