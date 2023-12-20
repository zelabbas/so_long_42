/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_is_valide.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:30 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/18 16:44:38 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_message_error(void)
{
	perror("\033[1;33m🛑SORRY: file is not valide (should be *.ber) \033[0m");
	exit(1);
}

static int	file_is_valide(char *str, char *needle)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (str[i] != needle[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valide(char *name_file)
{
	while (*name_file)
	{
		if (*name_file == '.')
		{
			name_file++;
			if (file_is_valide(name_file, "ber"))
				return ;
		}
		name_file++;
	}
	ft_message_error();
}
