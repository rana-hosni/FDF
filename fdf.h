/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:10:52 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/10 15:09:45 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <math.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_data
{
    int     x;
    int     y;
    int     z;
    int     **matrix;
}				t_data;

char	    *get_next_line(int fd);
void        read_file(char *file, t_data *map);
void	    get_size(int fd, char *file, t_data *map);
int     	**fill_matrix(char *file, t_data *map);
void	    free_matrix(char **matrix);
void	    draw_line(t_data *map, mlx_image_t *img);