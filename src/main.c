/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:49:40 by anggonza          #+#    #+#             */
/*   Updated: 2022/01/27 17:25:22 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int	ft_leave_program(t_all_vars *vars)
{
	free_map(vars->map.map);
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}

int	main(int ac, char **av)
{
	t_all_vars	vars;

	if (ac != 2)
	{
		ft_putendl_fd("Error \nUsage : ./solong map_path", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (map_check(av[1]) == -1)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	vars.map.map_path = av[1];
	ft_init_map(&vars);
	ft_init_window(&vars);
	ft_fill_map(&vars);
	mlx_loop(vars.mlx);
}
