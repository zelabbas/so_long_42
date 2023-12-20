/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_floor_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:07:39 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 13:21:50 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_floor_or_player(t_player **player, char c, char p)
{
	int		img_w;
	int		img_h;

	if (c == 'f')
	{
		(*player)->img = mlx_xpm_file_to_image((*player)->mlx,
				"./textures/floor.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*player)->mlx, (*player)->win,
			(*player)->img, (*player)->x_p, (*player)->y_p);
	}
	else if (c == 'p' && p == 'l')
	{
		(*player)->img = mlx_xpm_file_to_image((*player)->mlx,
				"./textures/left_player.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*player)->mlx, (*player)->win,
			(*player)->img, (*player)->x_p, (*player)->y_p);
	}
	else if (c == 'p' && p == 'r')
	{
		(*player)->img = mlx_xpm_file_to_image((*player)->mlx,
				"./textures/right_player.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*player)->mlx, (*player)->win,
			(*player)->img, (*player)->x_p, (*player)->y_p);
	}
	ft_load_img_error(&player);
}
