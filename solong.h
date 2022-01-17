/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:53 by anggonza          #+#    #+#             */
/*   Updated: 2022/01/12 13:29:43 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int	ft_check_valid_component(char **map);
int	ft_check_rectangular(char **map);
int	ft_check_wall(char **map);
int	ft_at_least_one(char **map);
int ft_strlenn(char **str);

#endif
