#include "include/solong.h"

void    ft_map_to_assets(int x, int y, char to_print, t_all_vars *vars)
{
	if (to_print == '1')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.wall, x, y);
	if (to_print == '0')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.empty_space, x, y);
	if (to_print == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.exit, x, y);
	if (to_print == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.exit, x, y);
		//mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.player, x, y);
	}
	if (to_print == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.collectible, x, y);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.empty_space, x, y);
	}
}

void    ft_fill_map(t_all_vars *vars)
{
	int i;
	int j;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (i < vars->map.height)
	{
		while (j < vars->map.width)
		{
			ft_map_to_assets(x, y, vars->map.map[i][j], vars);
			j++;
			x += 32;
		}
		j = 0;
		x = 0;
		y += 32;
		i++;
	}
}
