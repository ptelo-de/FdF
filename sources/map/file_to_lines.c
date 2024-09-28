#include "../includes/fdF.h"

t_line *ft_init_lines(void)
{
    t_line *lines;

    lines = ft_calloc(1, sizeof(t_line));
    if (!lines)
    {
        ft_putstr_fd("calloc failed in lines init", 2);
        exit(1);
    }
    lines->line_index = 0;
    lines->pos = NULL;
    lines->next_line = NULL;
    return(lines);
}
void ft_add_pos_to_line(t_line **lines, char *x, int y)
{
    t_line *line = *lines;
    // while(line->next_line)
    //     line = line->next_line;
    line->pos = ft_calloc(1, sizeof(t_2d_point));
    if (!line->pos)
    {
        ft_putstr_fd("calloc failed in pos init", 2);
        exit(1);
    }
    line->pos->y = y;
    line->pos->x = ft_atoi2(x, 0, 1);
    line->pos->next = NULL;
}
void ft_file_to_lines(int fd)
{
    t_line *lines;

    lines = ft_init_lines();

    // line = get_next_line(fd);
    // if (!line)
    // {
    //     ft_putstr_fd("Map file is empty, from gnl return", 2);
    //     exit(1);
    // }
    // while (line)
	// {
	// 	printf("[%d] %s", i, line);
	// 	free(line);
	// 	i++;
    //     break;
	// }
	// free(line);
    
	// printf("%d\n", fd);
	close(fd);
}