#include "test_raycast.h"

// bool	is_hit_wall(t_mlx *mlx)
// {
// 	return (world_map[(int)(mlx->pos_y + mlx->player_direct * MOVE_SPEED)]
// 			[(int)(mlx->pos_x + mlx->player_direct * MOVE_SPEED)] == '1');
// }

void	move_forward(t_mlx *mlx)
{
	printf("before mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	printf("mlx->player_direct: %lf\n", mlx->player_direct);

	// printf("new_pos_y: %lf\n", new_pos_y);
	printf("mlx->pos_x: %f\n", mlx->pos_x + MOVE_SPEED * cos(mlx->player_direct));
	printf("mlx->pos_y: %f\n", mlx->pos_y + sin(mlx->player_direct) * MOVE_SPEED);
	if (world_map[(int)(mlx->pos_y + sin(mlx->player_direct) * MOVE_SPEED)]
			[(int)(mlx->pos_x + MOVE_SPEED * cos(mlx->player_direct))] != '1')
	{
		mlx->pos_y = mlx->pos_y + sin(mlx->player_direct) * MOVE_SPEED;
		mlx->pos_x = mlx->pos_x + cos(mlx->player_direct) * MOVE_SPEED;
	}
	printf("after mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	// exit(0);
}

void	move_back(t_mlx *mlx)
{
	printf("before mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	if (world_map[(int)(mlx->pos_y - MOVE_SPEED * sin(mlx->player_direct))]
		[(int)(mlx->pos_x - MOVE_SPEED * cos(mlx->player_direct))] != '1')
	{
		mlx->pos_x = mlx->pos_x - MOVE_SPEED * cos(mlx->player_direct);
		mlx->pos_y = mlx->pos_y - MOVE_SPEED * sin(mlx->player_direct);
	}
	printf("after mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
}

void	move_left(t_mlx *mlx)
{
	printf("before mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	if (world_map[(int)(mlx->pos_y - MOVE_SPEED * sin(mlx->player_direct))]
		[(int)(mlx->pos_x + MOVE_SPEED * cos(mlx->player_direct))] != '1')
	{
		printf("cos: %lf, sin: %lf\n", cos(mlx->player_direct), sin(mlx->player_direct));
		mlx->pos_x = mlx->pos_x + MOVE_SPEED * sin(mlx->player_direct);
		mlx->pos_y = mlx->pos_y - MOVE_SPEED * cos(mlx->player_direct);
	}
	printf("after mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
}

void	move_right(t_mlx *mlx)
{
	printf("before mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	if (world_map[(int)(mlx->pos_y + MOVE_SPEED * sin(mlx->player_direct))]
		[(int)(mlx->pos_x - MOVE_SPEED * cos(mlx->player_direct))] != '1')
	{
		printf("cos: %lf, sin: %lf\n", cos(mlx->player_direct), sin(mlx->player_direct));
		mlx->pos_x = mlx->pos_x - MOVE_SPEED * sin(mlx->player_direct);
		mlx->pos_y = mlx->pos_y + MOVE_SPEED * cos(mlx->player_direct);
	}
	printf("after mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
}

void	rotate_left(t_mlx *mlx)
{
	// printf("before mlx->player_direct: %lf°\n", mlx->player_direct);
	mlx->player_direct -= 20 * (M_PI / 180);
	if (mlx->player_direct < 0)
		mlx->player_direct += 2 * M_PI;
	// printf("after mlx->player_direct: %lf°\n", mlx->player_direct);
}

void	rotate_right(t_mlx *mlx)
{
	mlx->player_direct += 20 * (M_PI / 180);
	if (mlx->player_direct > 2 * M_PI)
		mlx->player_direct -= 2 * M_PI;
}

int	ft_press_key(int key_num, t_mlx *mlx)
{
	printf("%d\n", key_num);
	if (key_num == KEY_ESC)
		ft_destroy("press ESC key", mlx);
	else if (key_num == KEY_W)
	{
		printf("press W key\n");
		move_forward(mlx);
		// exit(0);
	}
	else if (key_num == KEY_S)
	{
		printf("press S key\n");
		move_back(mlx);
	}
	else if (key_num == KEY_A)
	{
		printf("press A key\n");
		move_left(mlx);
	}
	else if (key_num == KEY_D)
	{
		printf("press D key\n");
		move_right(mlx);
	}
	else if (key_num == KEY_ARROW_LEFT)
	{
		printf("press KEY_ARROw_LEFT key\n");
		rotate_left(mlx);
	}
	else if (key_num == KEY_ARROW_RIGHT)
	{
		printf("press KEY_ARROW_RIGHT key\n");
		rotate_right(mlx);
	}
	// exit(0);
	return (0);
}
