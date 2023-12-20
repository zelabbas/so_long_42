/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:54 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/19 12:38:43 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h> 
# include <fcntl.h>
# include <stdio.h>
# include "./get_next_line_d/get_next_line.h"
# include <stdbool.h>

typedef struct s_enemy
{
	int		x_e;
	int		y_e;
	int		find_pos;
	int		i_image;
	int		path_to_move;
	int		time_next_img;
	int		time_next_move;
	char	*imgs[5];
}	t_enemy;

typedef struct s_player
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	int		count_collection;
	int		movement;
	int		collectes;
	char	**map;
	t_enemy	enemy;
	int		rows;
	int		cols;
}	t_player;

typedef struct s_arg_map
{
	int	c;
	int	e;
	int	p;
	int	x;
	int	y;
}	t_arg_map;

void	check_file_is_valide(char *file);
void	check_map_is_valide(t_player *player);
char	**get_map(char *file);
char	**ft_split(char const *str, char c);
void	check_elements(t_player **player);
void	put_image_to_map(char p, int x1, int y1, t_player **player);
int		get_height(char **map);
int		get_width(char **map);
void	to_left(t_player **player);
void	to_right(t_player **player);
void	to_top(t_player **player);
void	to_bottom(t_player **player);
void	exit_door(t_player ***player);
void	display_movement(t_player ***player);
char	*ft_itoa(int n);
void	put_image_floor_or_player(t_player **player, char c, char p);
int		animation(t_player *vars);
int		get_position_for_enemy(t_player **player);
void	open_exit(t_player **player);
void	ft_putstr(char *str);
void	check_map_path(t_player **player);
void	exit_error_path_map(t_player ***player);
void	get_position_player(t_player **player);
void	open_exit(t_player **player);
void	free_copied_map(char **map, int height);
char	**copy_map(char **original_map, int height);
void	ft_error_argc(int ac);
void	ft_load_img_error(t_player ***player);
#endif