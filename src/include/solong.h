/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:53 by anggonza          #+#    #+#             */
/*   Updated: 2022/04/12 17:36:48 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define COLLECTIBLE "decor/collectible.xpm"
# define WALL "decor/wall.xpm"
# define EMPTY_SPACE "decor/grass.xpm"
# define EXIT "decor/exit.xpm"
# define PLAYER "decor/player.xpm"

# include <fcntl.h>
# include "../../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct s_assets {
	int		width;
	int		height;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
	void	*empty_space;
}	t_assets;

typedef struct s_maps {
	char	**map;
	char	*map_path;
	int		width;
	int		height;
}	t_maps;

typedef struct s_all_vars
{
	void		*mlx;
	void		*window;
	int			win_width;
	int			win_height;
	int			moves;
	int			collected;
	int			to_collect;
	int			x;
	int			y;
	t_maps		map;
	t_assets	assets;
}	t_all_vars;

int		ft_check_valid_component(char **map);
int		ft_check_rectangular(char **map);
int		ft_check_wall(char **map);
int		ft_at_least_one(char **map);
int		ft_strlenn(char **str);
int		ft_check_doubleret(char *buffer);
int		ft_extension_check(char *map_path);
int		map_check(char *map_path);
void	free_map(char **map);
void	ft_init_window(t_all_vars *vars);
void	ft_init_assets(t_all_vars *vars);
void	ft_init_map(t_all_vars *vars);
void	ft_fill_map(t_all_vars *vars);
int		ft_leave_program(t_all_vars *vars);
int		ft_check_move(t_all_vars *vars, char type, int x, int y);
void	ft_init_player(t_all_vars *vars);
void	ft_move(t_all_vars *vars, char type);
int		count_occ(char **map, char letter);

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53

#endif
