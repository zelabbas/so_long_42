/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_movement_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:20:40 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 13:05:55 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_movement(t_player ***player)
{
	int		img_w;
	int		img_h;
	char	*string;
	char	*number;

	number = ft_itoa(++(**player)->movement);
	string = ft_strjoin("Pas:", number);
	(**player)->img = mlx_xpm_file_to_image(
			(**player)->mlx, "./textures/wall1.xpm", &img_w, &img_h);
	ft_load_img_error(player);
	mlx_put_image_to_window(
		(**player)->mlx, (**player)->win, (**player)->img, 0, 0);
	mlx_put_image_to_window(
		(**player)->mlx, (**player)->win, (**player)->img, 50, 0);
	mlx_string_put((**player)->mlx, (**player)->win, 5, 5, 0x00ff00, string);
	ft_putstr(number);
	free(string);
	free(number);
}
