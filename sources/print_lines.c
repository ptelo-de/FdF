#include "../includes/fdF.h"

void ft_print_line(t_line *line)
{
    t_2d_point *pos = line->pos;

    while(pos)
    {
        ft_printf("(%d, %d)\n", pos->x, pos->y);
        pos = pos->next;
    }
}