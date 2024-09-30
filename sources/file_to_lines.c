#include "../includes/fdF.h"

void ft_add_pos(t_2d_point *pos, char *x, int y)// t_2d_point **pos
{
    if(!pos)
    {
        pos = ft_calloc(1, sizeof(t_2d_point));
        if (!pos)
        {
            ft_putstr_fd("calloc failed in pos init", 2);
            exit(1); //leeks
        }
        pos->y = y;
        pos->x = ft_atoi2(x, 0, 1);
        pos->next = NULL;
    }
    else
    {
        pos->next = ft_calloc(1, sizeof(t_2d_point));
        if (!pos->next)
        {
            ft_putstr_fd("calloc failed in pos init", 2);
            exit(1); //leeks
        }
        pos->next->y = y;
        pos->next->x = ft_atoi2(x, 0, 1);
        pos->next->next = NULL;
    }   
}
t_2d_point *ft_pos_init(char *file_line, int y)
{
    int i;
    int j;
    t_2d_point *pos;

    pos = NULL;
    while (file_line[i])
    {
        while (file_line[i] == 32 || file_line[i] == '\n')
            i++;
        
        j = 0;
        while (file_line[i + j] && file_line[i + j] != 32 && file_line[i + j] != '\n')
            j++;

        if (j > 0)
            ft_add_pos(pos, ft_substr(file_line, i, j), y);

        i += j;
    }
}
t_line *ft_new_line(char *s, int y)
{
    t_line *lines;

    lines = ft_calloc(1, sizeof(t_line));
    if (!lines)
    {
        ft_putstr_fd("calloc failed in lines init", 2);
        exit(1);
    }
    lines->line_index = y;
    lines->pos = NULL;
    lines->next_line = NULL;
    return(lines);
}
void ft_file_to_lines(char *file_path)
{
    t_line *lines;
    char *gnl;
    int fd;
    int i;

    fd = open(file_path, O_RDONLY);
    if(fd < 0)
    {
    	ft_putstr_fd("[fdf] ERROR - Invalid map or map path\n", 2);
        exit(1);
    }
    gnl = get_next_line(fd);
    lines = ft_new_line(fd, 0);
    
    free(gnl);
	close(fd);
}

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
