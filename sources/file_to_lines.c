#include "../includes/fdF.h"

void ft_add_pos(t_3d_point **pos, char *z, int y, int x)
{
    t_3d_point *new_node;
    t_3d_point *current;

    new_node = ft_calloc(1, sizeof(t_3d_point));
    if (!new_node)
    {
        ft_putstr_fd("calloc failed in pos init", 2);
        exit(1);
    }
    new_node->y = y;
    new_node->z = ft_atoi2(z, 0, 1);
    new_node->x = x;
    free(z);
    new_node->next = NULL;

    if (!(*pos))
    {
        *pos = new_node;
    }
    else
    {
        current = *pos;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}
t_3d_point *ft_pos_init(char *file_line, int y)
{
    int i;
    int j;
    t_3d_point *pos;
    int x;

    pos = NULL;
    i = 0;
    x = 0;
    while (file_line[i])
    {
        while (file_line[i] == 32 || file_line[i] == '\n')
            i++;
        j = 0;
        while (file_line[i + j] && file_line[i + j] != 32 && file_line[i + j] != '\n')
            j++;
        if (j > 0)
            ft_add_pos(&pos, ft_substr(file_line, i, j), y, x++);
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
void ft_add_line(t_line **lines, t_line *new_line)
{
    t_line *tmp;
    if(!(*lines))
    {
        *lines = new_line;
        return;
    }
    tmp = *lines;
    while(tmp->next_line)
    {
     tmp = tmp->next_line;
    }   
        
    tmp->next_line = new_line;
    
}
t_line *ft_file_to_lines(char *file_path, int num_lines)
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
    if(!gnl) //no sense cause i need one null return
    {
        ft_putstr_fd("gnl returned null", 2);
        exit(1);
    }
    lines = NULL;
    while(gnl)
    {
        ft_add_line(&lines, ft_new_line(gnl, num_lines)); 
        ft_linescheck(&lines, num_lines, gnl);
        free(gnl);
        gnl = get_next_line(fd);
        num_lines--;
    }
        ft_print_line(lines);
    
    free(gnl);
	close(fd);
    return (lines);
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
