#include "../includes/fdF.h"

void ft_print_line(t_line *line)
{
    t_line *tmp = line;
    t_2d_point *pos;

    while(tmp)
   {
    pos = tmp->pos;
    while(pos)
    {
        printf("(%lf, %lf) ", pos->x, pos->y);
        pos = pos->next;
    }
    printf("\n");
    tmp = tmp->next_line;
   }
}