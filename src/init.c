/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:55:57 by anggonza          #+#    #+#             */
/*   Updated: 2022/02/03 17:05:26 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"
#include "include/keys.h"

int	keypress(int keycode, t_all_vars *vars)
{
	if (keycode == ESC)
		ft_leave_program(vars);
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_move(vars, 'u');
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move(vars, 'd');
	if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move(vars, 'l');
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move(vars, 'r');
	return (0);
}

int	destroy(t_all_vars *params)
{
	ft_leave_program(params);
	return (0);
}

void	ft_init_assets(t_all_vars *v)
{
	v->assets.collectible = mlx_xpm_file_to_image(v->mlx, COLLECTIBLE,
			&v->assets.width, &v->assets.height);
	v->assets.exit = mlx_xpm_file_to_image(v->mlx, EXIT, &v->assets.width,
			&v->assets.height);
	v->assets.player = mlx_xpm_file_to_image(v->mlx, PLAYER,
			&v->assets.width, &v->assets.height);
	v->assets.empty_space = mlx_xpm_file_to_image(v->mlx, EMPTY_SPACE,
			&v->assets.width, &v->assets.height);
	v->assets.wall = mlx_xpm_file_to_image(v->mlx, WALL,
			&v->assets.width, &v->assets.height);
}

void	ft_init_window(t_all_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, vars->win_width, vars->win_height,
			"so_long");
	ft_init_assets(vars);
	mlx_hook(vars->window, 2, 1L << 0, &keypress, vars);
	mlx_hook(vars->window, 17, 0, &destroy, vars);
}

void	ft_init_map(t_all_vars *vars)
{
	int		fd;
	char	buffer[65535];

	fd = open(vars->map.map_path, O_RDONLY);
	read(fd, buffer, 65535);
	vars->map.map = ft_split(buffer, '\n');
	vars->map.width = ft_strlen(vars->map.map[0]);
	vars->map.height = ft_strlenn(vars->map.map);
	vars->win_width = vars->map.width * 32;
	vars->win_height = vars->map.height * 32;
	vars->moves = 0;
	vars->collected = 0;
	vars->to_collect = count_occ(vars->map.map, 'C');
	ft_init_player(vars);
}
