#include "../solong.h"

void	ft_init_assets(t_all_vars *vars)
{
	vars->assets.collectible = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE, &vars->assets.width,&vars->assets.height);
	vars->assets.exit = mlx_xpm_file_to_image(vars->mlx, EXIT, &vars->assets.width,&vars->assets.height);
	//vars->assets.player = mlx_xpm_file_to_image(vars->mlx, PLAYER, &vars->assets.width,&vars->assets.height);
	vars->assets.empty_space = mlx_xpm_file_to_image(vars->mlx, EMPTY_SPACE , &vars->assets.width,&vars->assets.height);
	vars->assets.wall = mlx_xpm_file_to_image(vars->mlx, WALL , &vars->assets.width,&vars->assets.height);
}

void    ft_init_window(t_all_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window =  mlx_new_window(vars->mlx,1280,720,"so_long");
	ft_init_assets(vars);
	printf("%p\n", vars->assets.exit);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.exit,0 ,0);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->assets.exit, 32, 0);
	mlx_loop(vars->mlx);
}
