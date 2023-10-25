#include "cub3d.h"

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

void	set_player(t_mlx *mlx, char **map)
{
	size_t	x;
	size_t	y;

	printf("start set_player\n");
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				mlx->pos_x = (double)x + 0.5;
				mlx->pos_y = (double)y + 0.5;
				set_direction(mlx, map[y][x]);
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		// printf("\n");
		y++;
	}
	exit_error("ERROR: start position is not set");
}
