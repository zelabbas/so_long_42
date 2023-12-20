/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:51 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 12:02:35 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_player *player)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = player->win_w;
	while (player->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (player->win_w > 0)
		{
			put_image_to_map(player->map[y_map][x_map], x1, y1, &player);
			x_map++;
			x1 += 50;
			player->win_w--;
		}
		player->win_w = backup_w;
		y_map++;
		y1 += 50;
		player->win_h--;
	}
}

int	key_hook(int key, t_player *player)
{
	int	i;

	if (key == 123 || key == 0)
		to_left(&player);
	else if (key == 124 || key == 2)
		to_right(&player);
	else if (key == 126 || key == 13)
		to_top(&player);
	else if (key == 125 || key == 1)
		to_bottom(&player);
	else if (key == 53)
	{
		i = 0;
		while (player->map[i])
		{
			free(player->map[i]);
			i++;
		}
		free(player->map);
		mlx_destroy_window(player->mlx, player->win);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_player *player)
{
	int	i;

	i = 0;
	while (player->map[i])
	{
		free(player->map[i]);
		i++;
	}
	free(player->map);
	mlx_destroy_window(player->mlx, player->win);
	exit(1);
	return (0);
}

void	init_player(t_player *player)
{
	player->collectes = 0;
	player->movement = 0;
	player->win_w = get_width(player->map);
	player->win_h = get_height(player->map);
	player->enemy.find_pos = 0;
	player->enemy.i_image = 0;
	player->enemy.time_next_img = 5;
	player->enemy.time_next_move = 40;
	player->enemy.path_to_move = 1;
}

int	main(int argc, char **argv)
{
	t_player	player;

	ft_error_argc(argc);
	check_file_is_valide(argv[1]);
	player.map = get_map(argv[1]);
	if (player.map)
	{
		check_map_is_valide(&player);
		init_player(&player);
		player.mlx = mlx_init();
		if (player.mlx)
		{
			player.win = mlx_new_window(player.mlx,
					player.win_w * 50, player.win_h * 50, "so_long");
			render_map(&player);
			mlx_hook(player.win, 2, 0, key_hook, &player);
			mlx_hook(player.win, 17, 0, ft_exit, &player);
			mlx_loop(player.mlx);
		}
	}
	return (0);
}
