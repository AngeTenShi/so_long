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

int	ft_strlenn(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static int  count_occ(char **map, char letter)
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
	return (0);
}
