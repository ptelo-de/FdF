#include "../includes/fdF.h"

void ft_file_array(int fd)
{
    char **lines;
    char *line;

    line = get_next_line(fd);
    if (!line)
    {
        ft_putstr_fd("Map file is empty, from gnl return", 2);
        exit(1);
    }
    while (line)
	{
		printf("[%d] %s", i, line);
		free(line);
		i++;
        break;
	}
	// free(line);
	// printf("%d\n", fd);
	close(fd);
}