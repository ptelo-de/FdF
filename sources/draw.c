#include "../includes/fdF.h"

 void	ft_mlx_init(t_mlx *mlx, t_line *map)
{
	mlx->map = map;
	mlx->mlx = mlx_init(); //intialize mlx context, void*
	mlx->img = ft_calloc(1, sizeof(t_img));
	if (!mlx->mlx || !mlx->img)
	{
		ft_putstr_fd("fail in mlx init", 2);
		return ;
	}
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, 
			&(mlx->img->bits_per_pixel), &(mlx->img->line_length),
			&(mlx->img->endian));
	mlx_loop(mlx->mlx);
}