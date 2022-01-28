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

#include "../solong.h"

int main(int argc, char **argv)
{
    t_all_vars  vars;

    if (argc != 2)
    {
        ft_putendl_fd("Error \nUsage : ./solong map_path",STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    else if (map_check(argv[1]) == -1) {
        ft_putendl_fd("Error \nMap not valid", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    ft_init_window(&vars);
    return (EXIT_SUCCESS);
}

