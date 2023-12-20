/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:39 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 13:05:10 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_player ***player, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**player)->img = mlx_xpm_file_to_image(
			(**player)->mlx, img, &img_w, &img_h);
	ft_load_img_error(player);
	mlx_put_image_to_window((**player)->mlx,
		(**player)->win, (**player)->img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_player **player)
{
	if (p == '1')
		put_image(&player, x1, y1, "./textures/wall1.xpm");
	else if (p == 'C')
	{
		put_image(&player, x1, y1, "./textures/floor.xpm");
		put_image(&player, x1, y1, "./textures/collect.xpm");
		(*player)->collectes++;
	}
	else if (p == 'E')
		put_image(&player, x1, y1, "./textures/close_door.xpm");
	else if (p == 'P')
	{
		(*player)->y_p = y1;
		(*player)->x_p = x1;
		put_image(&player, x1, y1, "./textures/floor.xpm");
		put_image(&player, x1, y1, "./textures/right_player.xpm");
	}
	else
		put_image(&player, x1, y1, "./textures/floor.xpm");
}
