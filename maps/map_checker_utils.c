/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:49:40 by anggonza          #+#    #+#             */
/*   Updated: 2022/01/12 15:27:17 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"
#include <stdio.h>

int	ft_check_valid_component(char **map)
{
	int	i;
	int	size;
	int	j;

	j = 0;
	i = 0;
	size = ft_strlen(map);
	while (i < size)
	{
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] && 'C' ||
				map[i][j] != 'E' && map[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_check_line_wall(char *map)
{
	while (*map)
	{
		if (*map != 1)
			return (-1);
		map++;
	}
	return (0);
}

int	ft_check_rectangular(char **map)
{
	int	i;
	int	count_line;
	int	count_column;
	int	j;

	i = 0;
	j = 0;
	count_column = 0;
	count_line = 0;
	while (i < ft_strlen(map))
	{
		while (j < ft_strlen(map[i]))
		{
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_check_wall(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(map);
	while (i < size)
	{
		if (i == 0 || i == size - 1)
		{
			if (ft_check_line_wall(map[i]) == -1)
				return (-1);
		}
		else
		{
			if (map[i][0] != 1 || map[i][ft_strlen(map[i]) - 1] != 1)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_at_least_one(char **map)
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	i;
	int	j;

	i = 0;
	count_e = 0;
	count_p = 0;
	count_c = 0;
	while (i < ft_strlen(map))
	{
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'P')
				count_p++;
			if (map[i][j] == 'C')
				count_c++;
			if (map[i][j] == 'E')
				count_e++;
		}
		j = 0;
		i++;
	}
	if (count_p != 1 || count_e < 1 || count_e < 1)
		return (-1);
	return (0);
}

int	map_check(char *map_path)
{
	int		read_val;
	int		fd;
	char	buffer[65535];
	char	**map;
	int		size;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	read_val = read(fd, buffer, 65535);
	if (read_val < 0)
		return (-1);
	map = ft_split(buffer, '\n');
	if (ft_check_valid_component(map) == -1 || ft_check_wall(map) == -1
		|| ft_check_rectangular(map) == -1 || ft_at_least_one(map) != -1)
		return (-1);
	free(map);
	return (0);
}

int	main(void)
{
	map_check("maps.ber");
}
