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
		return (-1);
	read_val = read(fd, buffer, 65535);
	if (read_val < 0)
		return (-1);
	map = ft_split(buffer, '\n');
	for (int i = 0; i < ft_strlenn(map); i++)
		printf("%s\n", map[i]);
	if (ft_check_valid_component(map) == -1 || ft_check_wall(map) == -1
		|| ft_check_rectangular(map) == -1 || ft_at_least_one(map) == -1)
	{
		free_map(map);
		return (-1);
	}
	free_map(map);
	return (0);
}

int	main(void)
{
	printf("%d\n", map_check("maps/maps.ber"));
}
