/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:48 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 13:23:51 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_message_error(void)
{
	perror("\033[1;34m🛑ERROR in step de recuperation map\033[0m");
	exit(1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_width(char **map)
{
	int	j;

	j = ft_strlen(map[0]);
	return (j);
}

char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*all_line;
	char	*tmp_ptr;

	line = "";
	all_line = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_message_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		tmp_ptr = all_line;
		all_line = ft_strjoin(all_line, line);
		free(line);
		free(tmp_ptr);
	}
	close(fd);
	free(line);
	if (all_line[0] == '\0')
		ft_message_error();
	return (ft_split(all_line, '\n'));
}
