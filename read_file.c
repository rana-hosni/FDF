/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:43 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/04 13:26:58 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	alloc_matrix(int **matrix, int x, int y)
{
	int i;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * y);
	if (!matrix)
		return ;
	while (i < y)
	{
		matrix[i] = (int *)malloc(sizeof(int) * x);
		if (!matrix[i])
			return ;
		i++;
	}

}

int	**fill_matrix(char *line, int y)
{
	int	**matrix;
	char **temp;
	int	x;
	int i;
	
	i = 0;
	x = 0;
	matrix = NULL;
	temp = ft_split(line, ' ');
	ft_printf("TEST");
	
	while (temp[x])
		x++;
	alloc_matrix(matrix, x, y);
	ft_printf("line is : %s\n", line);
	
	return (matrix);
}

void    read_file(char *file)
{
	int		fd;
	char	*line;
	int		**matrix;
	int		y = 0;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
    {
		ft_printf("error opening file\n");
		return ;
    }
	while ((line = get_next_line(fd)) != NULL)
		y++;
	line = NULL;
	ft_printf("y: %d\n", y);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("TEST");
		matrix = fill_matrix(line, y);
	}
	close(fd);
}
