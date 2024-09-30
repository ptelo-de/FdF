#include "../includes/fdF.h"

void ft_add_pos(t_2d_point **pos, char *x, int y)// t_2d_point **pos
{
    t_2d_point *tmp_pos;
    tmp_pos = *pos;
    if(!tmp_pos)
    {
        ft_putendl_fd("bbbbbbbbbbbbbbbbb", 2);
        tmp_pos = ft_calloc(1, sizeof(t_2d_point));
        if (!pos)
        {
            ft_putstr_fd("calloc failed in pos init", 2);
            exit(1); //leeks
        }
        tmp_pos->y = y;
        tmp_pos->x = ft_atoi2(x, 0, 1);
        tmp_pos->next = NULL;
    }
    else
    {
        tmp_pos->next = ft_calloc(1, sizeof(t_2d_point));
        if (!tmp_pos->next)
        {
            ft_putstr_fd("calloc failed in pos init", 2);
            exit(1); //leeks
        }
        tmp_pos->next->y = y;
        tmp_pos->next->x = ft_atoi2(x, 0, 1);
        tmp_pos->next->next = NULL;
    }   
}
t_2d_point *ft_pos_init(char *file_line, int y)
{
    int i;
    int j;
    t_2d_point *pos;

    pos = NULL;
    i = 0;
    while (file_line[i])
    {
        while (file_line[i] == 32 || file_line[i] == '\n')
            i++;
        j = 0;
        while (file_line[i + j] && file_line[i + j] != 32 && file_line[i + j] != '\n')
            j++;
        if (j > 0)
        {
            ft_add_pos(&pos, ft_substr(file_line, i, j), y);
            // ft_putstr_fd(ft_substr(file_line, i, j), 2);
            // ft_putendl_fd("aaaaaaaaaaaaaaa", 2);
    
        }
        i += j;
    }
    return(pos);
}
t_line *ft_new_line(char *s, int y)
{
    t_line *line;

    line = ft_calloc(1, sizeof(t_line));
    if (!line)
    {
        ft_putstr_fd("calloc failed in lines init", 2);
        exit(1);
    }
    line->line_index = y;
    line->pos = ft_pos_init(s, y);
    if(!line->pos)
    {
        return(NULL);
    }
    line->next_line = NULL;
    return(line);
}
void ft_file_to_lines(char *file_path)
{
    t_line *lines;
    char *gnl;
    int fd;
    //int i;

    fd = open(file_path, O_RDONLY);
    if(fd < 0)
    {
    	ft_putstr_fd("[fdf] ERROR - Invalid map or map path\n", 2);
        exit(1);
    }
    gnl = get_next_line(fd);
    if(!gnl)
    {
        ft_putstr_fd("gnl returned null", 2);
        exit(1);
    }
    lines = ft_new_line(gnl, 0);
    if(!lines)
    {
        free(gnl);
        ft_putstr_fd("error in lines_init", 2);
        exit(1);
    }
    ft_print_line(lines);
    
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
