/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:53 by anggonza          #+#    #+#             */
/*   Updated: 2022/02/07 16:36:40 by anggonza         ###   ########.fr       */
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

#endif
