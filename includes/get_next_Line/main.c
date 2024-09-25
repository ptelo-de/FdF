
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> //has close() in it

int	main(void)
{
	char		*line;
	static int	i = 0;
	int			fd;

	line = "aaa";
	fd = open("example.txt", O_RDONLY | O_CREAT);
	if (fd <= 2)
	{
		printf("ocurreu um erro");
		return (1);
	}
	while ((line = get_next_line(0)))
	{
		printf("[%d] %s", i, line);
		free(line);
		i++;
	}
	// free(line);
	// printf("%d\n", fd);
	close(fd);
	return (0);
}
// int main(void)
// {
// 	char *line= "aaa";
// 	int i=0;
// 	int fd = open("example.txt", O_RDONLY | O_CREAT);
// 	if (fd <= 2)
// 	{
//   		printf("ocurreu um erro");
//   		return(1);
// 	}
// 	while (line)
// 	{
//	line = get_next_line(fd);
//   		printf("%s",line);
//   		if(!line)
// 			break ;
// 	}
// 	close(fd);
// 	return(0);
// }