#include "test_raycast.h"

void	set_direction(t_mlx *mlx, char direction)
{
	if (direction == 'N')
		mlx->direction = NORTH;
	if (direction == 'S')
		mlx->direction = SOUTH;
	if (direction == 'E')
		mlx->direction = EAST;
	if (direction == 'W')
		mlx->direction = WEST;
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
				mlx->pos_x = x;
				mlx->pos_y = y;
				mlx->map_x = (int)mlx->pos_x;
				mlx->map_y = (int)mlx->pos_y;
				set_direction(mlx, world_map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
	exit_error("ERROR: start position is not set\n");
}
