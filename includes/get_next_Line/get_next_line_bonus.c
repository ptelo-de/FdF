/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:13:48 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:57 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_notfullline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_okspollish(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		buffer[i] = '\0';
		i++;
	}
	if (buffer[i] == '\n')
	{
		buffer[i] = 0;
		i++;
	}
	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		buffer[i] = 0;
		j++;
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytesread;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	bytesread = BUFFER_SIZE;
	line = NULL;
	while (bytesread != 0 && ft_notfullline(line))
	{
		if (!*buffer[fd])
			bytesread = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytesread == -1)
		{
			if (line)
				free(line);
			return (NULL);
		}
		line = ft_strjoin(line, buffer[fd]);
		if (ft_okspollish(buffer[fd]) && !*line)
			return (free(line), NULL);
	}
	return (line);
}
/*RAZOES PARA BUFFER SER UM ARRAY:
1) (static)Conserva sempre o ultimo \0 desde a declaracao
2) Ao contrario da string literal, tem um tamanho fixo de elementos,
3) Permiteme alterar e nao apenas aceder a cada elemento da string
*/
