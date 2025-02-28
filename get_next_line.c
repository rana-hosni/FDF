/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:41:18 by relgheit          #+#    #+#             */
/*   Updated: 2025/02/28 16:48:46 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*clean_buffer(char *buffer)
{
	int	k;
	int	j;

	k = 0;
	while (buffer[k] && buffer[k] != '\n')
		k++;
	if (buffer[k] == '\n' || buffer[k] == '\0')
		k++;
	j = 0;
	if (k == (int)BUFFER_SIZE)
	{
		while (j < BUFFER_SIZE)
			buffer[j++] = '\0';
		return (buffer);
	}
	while (buffer[k])
		buffer[j++] = buffer[k++];
	buffer[j] = '\0';
	return (buffer);
}

static char	*clean_fun(char *str, char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!str || *str == 0)
	{
		free (str);
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			line = ft_substr(str, 0, i + 1);
			free (str);
			buffer = clean_buffer(buffer);
			return (line);
		}
		i++;
	}
	return (str);
}

static char	*read_fun(int fd, char *tmp, char *buffer)
{
	ssize_t	byte_read;
	char	*nline;
	int		i;

	byte_read = 1;
	nline = ft_strchr(buffer, '\n');
	while (nline == NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		else if (byte_read == 0)
			return (tmp);
		buffer[BUFFER_SIZE] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		nline = ft_strchr(buffer, '\n');
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		i;
	char		*line;
	char		*temp;

	i = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (++i <= BUFFER_SIZE)
		temp[i] = 0;
	if (*buffer)
		temp = ft_strjoin(temp, buffer);
	temp = read_fun(fd, temp, buffer);
	line = clean_fun(temp, buffer);
	return (line);
}
