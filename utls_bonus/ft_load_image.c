/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:22:40 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 12:46:39 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_img_error(t_player ***player)
{
	int	x;

	x = 0;
	if ((**player)->img == NULL)
	{
		while ((**player)->map[x])
		{
			free((**player)->map[x]);
			x++;
		}
		free((**player)->map);
		perror("\033[1;32m🛑ERROR: there is an error in load image!\033[0m");
		exit(1);
	}
}
