/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:48:28 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/27 21:28:28 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_in_file(int fd, char *str, char *buffer)
{
	int	octets_lus;

	if (str == NULL)
		str = ft_calloc(1, 1);
	if (str == NULL)
		return (NULL);
	octets_lus = 1;
	while (octets_lus >= 1)
	{
		octets_lus = read(fd, buffer, BUFFER_SIZE);
		if (octets_lus == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[octets_lus] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*create_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	if (str[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	next = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n' && str[i + 1] != '\0')
		next = ft_calloc(ft_strlen(str) - i, 1);
	if (!next)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		i++;
		next[j] = str[i];
		j++;
	}
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str[1025];

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buffer == NULL)
		return (NULL);
	str[fd] = read_in_file(fd, str[fd], buffer);
	if (! (str[fd]) || (str[fd])[0] == 0)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = create_line(str[fd]);
	str[fd] = next_line(str[fd]);
	return (line);
}
