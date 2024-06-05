/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:01:07 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/06/05 15:51:10 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*beginning_next_line(char *start_line)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (start_line[i] != '\n' && start_line[i])
		i++;
	if (start_line[i] == '\n')
		i++;
	if (start_line[i] == '\0')
	{
		free(start_line);
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * ft_strlen(start_line) - i + 1);
	if (!next_line)
		return (NULL);
	while (start_line[i])
	{
		next_line[j++] = start_line[i++];
	}
	next_line[j] = '\0';
	free(start_line);
	return (next_line);
}

static char	*one_line(char *start_line)
{
	int		i;
	char	*line;

	if (!start_line)
		return (NULL);
	i = 0;
	while (start_line[i] != '\n' && start_line[i])
		i++;
	if (start_line[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (start_line[i] != '\n' && start_line[i])
	{
		line[i] = start_line[i];
		i++;
	}
	if (start_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*temporal;
	static char	*start_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	temporal = (char *)malloc(sizeof(char) *(1 + BUFFER_SIZE));
	if (!temporal)
		return (NULL);
	while (bytes_read == BUFFER_SIZE && !ft_strchr(start_line, '\n'))
	{
		bytes_read = read(fd, temporal, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			break ;
		}
		temporal[bytes_read] = '\0';
		start_line = ft_strjoin(start_line, temporal);
	}
	free(temporal);
	temporal = one_line(start_line);
	if (start_line)
		start_line = beginning_next_line(start_line);
	return (temporal);
}

/*#include "stdio.h"
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("linea impresa FINAL :%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/