#include "test_raycast.h"

void	set_wall_texture(t_mlx *mlx)
{
	int		i;
	int		height;
	int		width;

	printf("start init_wall_texture\n");
	height = WINSIZE_HEIGTH;
	width = WINSIZE_WIDTH;
	i = 0;
	while (i < 4)
	{
		mlx->wall_texure[i].img_ptr
			= mlx_xpm_file_to_image(mlx->mlx_ptr, NULL, &height, &width);
		if (!mlx->wall_texure[i].img_ptr)
			exit_error("ERROR: \
				cannot convert xpm to image in mlx_xpm_file_to_image()");
		mlx->wall_texure[i].deta_addr = mlx_get_data_addr(
				mlx->wall_texure[i].img_ptr, mlx->wall_texure[i].bits_per_pixel,
				mlx->wall_texure[i].size_line, mlx->wall_texure[i].endian);
		if (!mlx->wall_texure[i].img_ptr)
			exit_error("ERROR: \
				cannot get memory address of image in mlx_get_data_addr()");
	}
	printf("finish init_wall_texture\n");
	exit(0);
}
