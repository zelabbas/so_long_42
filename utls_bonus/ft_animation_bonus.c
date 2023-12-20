/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:21:35 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 13:02:44 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_enemy(t_player **player)
{
	int			img_w;
	int			img_h;

	(*player)->enemy.imgs[0] = "./textures/enemyf1.xpm";
	(*player)->enemy.imgs[1] = "./textures/enemyf2.xpm";
	(*player)->enemy.imgs[2] = "./textures/enemyf3.xpm";
	(*player)->enemy.imgs[3] = "./textures/enemyf4.xpm";
	(*player)->enemy.imgs[4] = "./textures/enemyf2.xpm";
	(*player)->img = mlx_xpm_file_to_image(
			(*player)->mlx, "./textures/floor.xpm", &img_w, &img_h);
	ft_load_img_error(&player);
	mlx_put_image_to_window(
		(*player)->mlx, (*player)->win, (*player)->img,
		(*player)->enemy.x_e * 50, (*player)->enemy.y_e * 50);
	(*player)->img = mlx_xpm_file_to_image(
			(*player)->mlx, (*player)->enemy.imgs[(*player)->enemy.i_image],
			&img_w, &img_h);
	ft_load_img_error(&player);
	mlx_put_image_to_window(
		(*player)->mlx, (*player)->win, (*player)->img,
		(*player)->enemy.x_e * 50, (*player)->enemy.y_e * 50);
}

void	move_enemy(t_player **player)
{
	int			img_w;
	int			img_h;

	(*player)->img = mlx_xpm_file_to_image(
			(*player)->mlx, "./textures/floor.xpm", &img_w, &img_h);
	ft_load_img_error(&player);
	mlx_put_image_to_window(
		(*player)->mlx, (*player)->win, (*player)->img,
		(*player)->enemy.x_e * 50, (*player)->enemy.y_e * 50);
	if ((*player)->map[(*player)->enemy.y_e][(*player)->enemy.x_e + 1] != '1' &&
		(*player)->map[(*player)->enemy.y_e][(*player)->enemy.x_e + 1] != 'C' &&
		(*player)->map[(*player)->enemy.y_e][(*player)->enemy.x_e + 1] != 'E' &&
		(*player)->enemy.path_to_move == 1)
		(*player)->enemy.x_e++;
	else
		(*player)->enemy.path_to_move = 0;
	if ((*player)->map[(*player)->enemy.y_e][(*player)->enemy.x_e - 1] != '1' &&
		(*player)->map[(*player)->enemy.y_e][(*player)->enemy.x_e - 1] != 'C' &&
		(*player)->map[(*player)->enemy.y_e][(*player)->enemy.x_e - 1] != 'E' &&
		(*player)->enemy.path_to_move == 0)
		(*player)->enemy.x_e--;
	else
		(*player)->enemy.path_to_move = 1;
}

static void	ft_lose(t_player **v, char *str)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	ft_putstr(str);
	exit(0);
}

int	animation(t_player *player)
{
	if (get_position_for_enemy(&player))
	{
		if (player->enemy.time_next_img-- <= 0)
		{
			player->enemy.i_image++;
			player->enemy.time_next_img = 5;
		}
		if (player->enemy.i_image == 4)
			player->enemy.i_image = 0;
		if (player->enemy.time_next_move-- <= 0)
		{
			move_enemy(&player);
			player->enemy.time_next_move = 40;
		}
		if ((player->enemy.y_e == player->y_p / 50)
			&& (player->enemy.x_e == player->x_p / 50))
		{
			ft_lose(&player, "You Lose");
		}
		render_enemy(&player);
	}
	return (0);
}
