/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:43 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/04 15:10:01 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

// int	**fill_matrix(char *line, int y)
// {
// 	int	**matrix;
// 	// char **temp;
// 	// int	x;
// 	// int i;
	
// 	// i = 0;
// 	// x = 0;
// 	// matrix = NULL;
// 	// temp = ft_split(line, ' ');
	
// 	// while (temp[x])
// 	// 	x++;
// 	// // alloc_matrix(matrix, x, y);
// 	ft_printf("line is : %s\n", line);
	
// 	return (matrix);
// }

int	**get_size(int fd, char *file)
{
	int x;
	int y;
	char *line;
	char **temp;
	int **matrix;
	
	x = 0;
	y = 0;
	line = NULL;
	temp = NULL;
	while ((line = get_next_line(fd)) != NULL)
		y++;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	temp = ft_split(line, ' ');
	while (temp[x])
		x++;
	ft_printf("x: %d\n", x);
	ft_printf("y: %d\n", y);
	matrix = alloc_matrix(x, y);
	return (matrix);
}

void    read_file(char *file)
{
	int		fd;
	char	*line;
	int		**matrix;
	// int		y = 0;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
    {
		ft_printf("error opening file\n");
		return ;
    }
	// while ((line = get_next_line(fd)) != NULL)
	// 	y++;
	// line = NULL;
	// ft_printf("y: %d\n", y);
	// fd = open(file, O_RDONLY);
	matrix = get_size(fd, file);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	matrix = fill_matrix(line, y);
	// }
	close(fd);
}
