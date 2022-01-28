/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:49:40 by anggonza          #+#    #+#             */
/*   Updated: 2022/01/26 17:18:06 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int	ft_check_valid_component(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ft_strlenn(map))
	{
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

static int	ft_check_line_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_rectangular(char **map)
{
	int	i;
	int	count_line;

	i = 0;
	count_line = ft_strlen(map[0]);
	while (i < ft_strlenn(map))
	{
		if (ft_strlen(map[i]) != count_line)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_wall(char **map)
{
	int	i;

	i = 0;
	while (i < ft_strlenn(map))
	{
		if (i == 0 || i == ft_strlenn(map) - 1)
		{
			if (ft_check_line_wall(map[i]) == -1)
				return (-1);
		}
		else
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_extension_check(char *map_path)
{
	int	size;

	size = ft_strlen(map_path) - 1;
	if (!(map_path[size] == 'r' && map_path[size - 1] == 'e'
			&& map_path[size - 2] == 'b' && map_path[size - 3] == '.'))
		return (-1);
	return (1);
}
