/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:20:40 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 21:19:20 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_movement(t_player ***player)
{
	char	*number;

	number = ft_itoa(++(**player)->movement);
	ft_putstr(number);
	free(number);
}
