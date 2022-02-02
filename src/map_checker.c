/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:49:40 by anggonza          #+#    #+#             */
/*   Updated: 2022/02/02 17:39:22 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

int	map_check(char *map_path)
{
	int		read_val;
	int		fd;
	char	buffer[65535];
	char	**map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("The file doesn't exist. This may be a folder", 2);
		return (-1);
	}
	read_val = read(fd, buffer, 65535);
	if (read_val < 0 || ft_check_doubleret(buffer) == -1
		|| ft_extension_check(map_path) == -1)
		return (-1);
	map = ft_split(buffer, '\n');
	if (ft_check_valid_component(map) == -1 || ft_check_wall(map) == -1
		|| ft_check_rectangular(map) == -1 || ft_at_least_one(map) == -1)
	{
		ft_putendl_fd("Map not valid", 2);
		free_map(map);
		return (-1);
	}
	free_map(map);
	return (0);
}
