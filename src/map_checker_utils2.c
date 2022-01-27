/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:49:40 by anggonza          #+#    #+#             */
/*   Updated: 2022/01/26 16:57:02 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_strlenn(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	count_occ(char **map, char letter)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (i < ft_strlenn(map))
	{
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == letter)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	ft_at_least_one(char **map)
{
	if (count_occ(map, 'P') != 1 || count_occ(map, 'E') < 1
		|| count_occ(map, 'C') < 1)
		return (-1);
	return (1);
}

int	ft_check_doubleret(char *buffer)
{
	int	i;

	if (buffer[0] == '\n')
		return (-1);
	i = 1;
	while (i < ft_strlen(buffer))
	{
		if (buffer[i - 1] == '\n' && buffer[i] == '\n')
			return (-1);
		i++;
	}
	return (1);
}
