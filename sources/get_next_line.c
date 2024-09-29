/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:13:48 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/05/20 19:15:06 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdF.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytesread;

	if (fd < 0)
		return (NULL);
	bytesread = BUFFER_SIZE;
	line = NULL;
	while (bytesread != 0 && ft_notfullline(line))
	{
		if (!*buffer)
			bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			if (line)
				free(line);
			return (NULL);
		}
		line = ft_strjoin2(line, buffer);
		if (ft_okspollish(buffer) && !*line)
			return (free(line), NULL);
	}
	return (line);
}
/*RAZOES PARA BUFFER SER UM ARRAY:
1) (static)Conserva sempre o ultimo \0 desde a declaracao
2) Ao contrario da string literal, tem um tamanho fixo de elementos,
3) Permiteme alterar e nao apenas aceder a cada elemento da string
*/
