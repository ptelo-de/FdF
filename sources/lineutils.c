#include "../includes/fdF.h"

t_line *ft_lastline(t_line *line)
{
    t_line *aux;

    aux = line;
    while(aux->next_line)
        aux = aux->next_line;
    return(aux);
}
void ft_free_pos(t_3d_point *pos)
{
    t_3d_point *tmp;

    while (pos)
    {
        tmp = pos;      // Save the current node
        pos = pos->next; // Move to the next node
        free(tmp);         // Free the current node
    }
}
void ft_free_lines(t_line *lines)
{
 t_line *tmp;

    while (lines)
    {
        tmp = lines;          // Save the current node
        lines = lines->next_line; // Move to the next node

        // Free the linked list of points
        if (tmp->pos)
            ft_free_pos(tmp->pos);
        free(tmp);
    }
}
void ft_linescheck(t_line **lines, int i, char *gnl)
{
    if(!(*lines) || ft_lastline(*lines)->line_index != i)
    {
        free(gnl);
        ft_free_lines(*lines);
        ft_putendl_fd("Error when adding lines", 2);
        exit(1);
    }
}