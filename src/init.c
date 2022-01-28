#include "include/solong.h"


void	ft_init_assets(t_all_vars *vars)
{
	vars->assets.collectible = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE, &vars->assets.width,&vars->assets.height);
	vars->assets.exit = mlx_xpm_file_to_image(vars->mlx, EXIT, &vars->assets.width,&vars->assets.height);
	vars->assets.player = mlx_xpm_file_to_image(vars->mlx, PLAYER, &vars->assets.width,&vars->assets.height);
	vars->assets.empty_space = mlx_xpm_file_to_image(vars->mlx, EMPTY_SPACE , &vars->assets.width,&vars->assets.height);
	vars->assets.wall = mlx_xpm_file_to_image(vars->mlx, WALL , &vars->assets.width,&vars->assets.height);
}

void    ft_init_window(t_all_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window =  mlx_new_window(vars->mlx,vars->win_width,vars->win_height,"so_long");
	ft_init_assets(vars);
}

void    ft_init_map(t_all_vars *vars)
{
	int		fd;
	char	buffer[65535];

	fd = open(vars->map.map_path, O_RDONLY);
	read(fd, buffer, 65535);
	vars->map.map = ft_split(buffer, '\n');
	vars->map.width = ft_strlen(vars->map.map[0]);
	vars->map.height = ft_strlenn(vars->map.map);
	vars->win_width = vars->map.width * 32;
	vars->win_height = vars->map.height * 32;
}

