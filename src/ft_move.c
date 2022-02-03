/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:46:57 by anggonza          #+#    #+#             */
/*   Updated: 2022/02/03 16:57:57 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int	ft_check_move(t_all_vars *v, char type, int x, int y)
{
	printf("%d: to collect, %d : collected\n", v->to_collect, v->collected);
	if (type == 'u')
		if (v->map.map[y - 1][x] == '1' ||
			(v->to_collect != v->collected && v->map.map[y - 1][x] == 'E'))
			return (0);
	if (type == 'd')
		if (v->map.map[y + 1][x] == '1' ||
			(v->to_collect != v->collected && v->map.map[y + 1][x] == 'E'))
			return (0);
	if (type == 'l')
		if (v->map.map[y][x - 1] == '1' ||
		(v->to_collect != v->collected && v->map.map[y][x - 1] == 'E'))
			return (0);
	if (type == 'r')
		if (v->map.map[y][x + 1] == '1' ||
		(v->to_collect != v->collected && v->map.map[y][x + 1] == 'E'))
			return (0);
	return (1);
}

void	ft_update(t_all_vars *vars, char type)
{
	vars->map.map[vars->y][vars->x] = '0';
	if (type == 'u')
		vars->y -= 1;
	if (type == 'd')
		vars->y += 1;
	if (type == 'r')
		vars->x += 1;
	if (type == 'l')
		vars->x -= 1;
	if (vars->map.map[vars->y][vars->x] == 'C')
		vars->collected += 1;
	if (vars->map.map[vars->y][vars->x] == 'E'
		&& vars->collected == vars->to_collect)
		ft_leave_program(vars);
	vars->map.map[vars->y][vars->x] = 'P';
	ft_fill_map(vars);
}

void	ft_move(t_all_vars *vars, char type)
{
	if (ft_check_move(vars, type, vars->x, vars->y) == 1)
	{
		vars->moves += 1;
		printf("Number of moves : %d\n", vars->moves);
		ft_update(vars, type);
	}
}
