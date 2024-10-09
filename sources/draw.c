#include "../includes/fdF.h"

 void	ft_mlx_init(t_data *mlx, t_line *map)
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
			&(mlx->img->endian));//sets bits_per_pixel to 32
	ft_printf("bits per pixel %d\n", mlx->img->bits_per_pixel);
	ft_printf("line lenght %d\n", mlx->img->line_length);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
void    draw_pixels(t_data *mlx, int color)
{
   t_line *tmp;
   t_3d_point *tmp_pos;

   tmp = mlx->map;
    while (tmp)
    {
		tmp_pos = tmp->pos;
		while(tmp_pos)
		{
        	draw_pixel(mlx->img, tmp_pos->x, tmp_pos->y, color);
			tmp_pos = tmp_pos->next;
		}
		tmp = tmp->next_line;
    }
}
/* Draw the entire grid */
void draw_grid(t_data *data)
{
    for (int y = 0; y < data->height; y++)
    {
        for (int x = 0; x < data->width; x++)
        {
            t_point p1 = {x * ZOOM, y * ZOOM, data->matrix[y][x]};
            t_point p2;

            p1 = project_point(p1);  // Project the 3D point into 2D space

            if (x < data->width - 1) // Draw horizontal lines
            {
                p2 = (t_point){(x + 1) * ZOOM, y * ZOOM, data->matrix[y][x + 1]};
                p2 = project_point(p2);
                draw_line(p1, p2, data, 0xFFFFFF);  // White color
            }

            if (y < data->height - 1) // Draw vertical lines
            {
                p2 = (t_point){x * ZOOM, (y + 1) * ZOOM, data->matrix[y + 1][x]};
                p2 = project_point(p2);
                draw_line(p1, p2, data, 0xFFFFFF);  // White color
            }
        }
    }
}


