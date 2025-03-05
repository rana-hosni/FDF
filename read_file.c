/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:43 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/05 16:10:38 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
	line = NULL;
	fd = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		temp = ft_split(line, ' ');
		ft_printf("line is : %s\n", line);
		while (temp[i])
		{
			ft_printf("temp[%d] is : %s\n", i ,temp[i]);
			map->matrix[j][i] = ft_atoi(temp[i]);
			i++;
		}
		ft_printf("\n");
		j++;
		// ft_printf("line is : %s\n", line);
		free_matrix(temp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// ft_printf("line is : %s\n", line);
	// i = 0;
	// j = 0;
	// while (i < map->y)
	// {
	// 	j = 0;
	// 	while (j < map->x)
	// 	{
	// 		ft_printf("%d ", map->matrix[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
	
	return (map->matrix);
}

void	get_size(int fd, char *file, t_data *map)
{
	char *line;
	char **temp;
	int i;

	line = NULL;
	temp = NULL;
	map->x = 0;
	map->y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->y++;
		if (map->y == 1)
		{
			temp = ft_split(line, ' ');
			map->x = ft_strlen(*temp);
			free_matrix(temp);
		}
		free(line);
	}
	// close(fd);
	// fd = open(file, O_RDONLY);
	// line = get_next_line(fd);
	// free(line);
	// map->matrix = alloc_matrix(map->x, map->y);
	// ft_printf("x: %d\n", map->x);
	// ft_printf("y: %d\n", map->y);
	// fill_matrix(file, map);
	// return (map->matrix);
}

void    read_file(char *file, t_data *map)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
    {
		ft_printf("error opening file\n");
		return ;
    }
	get_size(fd, file, map);
	close(fd);
	map->matrix = alloc_matrix(map->x, map->y);
	fill_matrix(file, map);
}
