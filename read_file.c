/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:43 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/12 14:35:00 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	**alloc_matrix(int x, int y)
{
	int i;
	int **matrix;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * y);
	if (!matrix)
		exit(EXIT_FAILURE);
	while (i < y)
	{
		matrix[i] = (int *)malloc(sizeof(int) * x);
		if (!matrix[i])
			exit(EXIT_FAILURE);
		i++;
	}
	return (matrix);
}

int	**fill_matrix(char *file, t_data *map)
{
	int		fd;
	char	*line;
	char	**temp;
	int 	i;
	int 	j;
	
	j = 0;
	fd = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		temp = ft_split(line, ' ');
		while (temp[i] && temp[i][0] != '\n')
		{
			map->matrix[j][i] = ft_atoi(temp[i]);
			i++;
		}
		j++;
		if (i < map->x || i > map->x)
		{
			ft_printf("Invalid Map\n");
			free_matrix(temp);
			return (NULL);
		}
		if (temp)
			free_matrix(temp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map->matrix);
}

void	get_size(int fd, t_data *map)
{
	char *line;
	char **temp;

	map->x = 0;
	map->y = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Empty Map\n");
		return ;
	}
	temp = ft_split(line, ' ');
	while (temp[map->x] && temp[map->x][0] != '\n')
		map->x++;
	while (line)
	{
		map->y++;
		free(line);
		line = get_next_line(fd);
	}
	free_matrix(temp);
	free(line);
	ft_printf("y: %d\n", map->y);
	ft_printf("x: %d\n", map->x);
}

void    read_file(char *file, t_data *map)
{
	int		fd;
	char	*line;
	int i;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
    {
		ft_printf("error opening file\n");
		return ;
    }
	ft_printf("file opened\n");
	get_size(fd, map);
	close(fd);
	map->matrix = alloc_matrix(map->x, map->y);
	fill_matrix(file, map);
	ft_printf("matrix allocated\n");
	i = 0;
	while (i < map->y)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
}
