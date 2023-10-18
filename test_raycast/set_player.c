#include "test_raycast.h"

void	set_direction(t_mlx *mlx, char direction)
{
	if (direction == 'N')
		mlx->player_direct = NORTH;
	if (direction == 'S')
		mlx->player_direct = SOUTH;
	if (direction == 'E')
		mlx->player_direct = EAST;
	if (direction == 'W')
		mlx->player_direct = WEST;
}

void	set_player(t_mlx *mlx)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (world_map[y][x] == 'N' || world_map[y][x] == 'S'
				|| world_map[y][x] == 'W' || world_map[y][x] == 'E')
			{
				mlx->pos_x = (double)x + 0.5;
				mlx->pos_y = (double)y + 0.5;
				set_direction(mlx, world_map[y][x]);
				world_map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	exit_error("ERROR: start position is not set");
}
