/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:10:52 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/14 13:13:09 by relgheit         ###   ########.fr       */
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

#define WIDTH 1000
#define HEIGHT 1000
#define SCALE 50

# define x_angle 45
# define y_angle 35

typedef struct s_data
{
    int     x;
    int     y;
    // int     z;
    int     **matrix;
}				t_data;

typedef struct s_points
{
    int     x;
    int     y;
}				t_points;

char		*get_next_line(int fd);
void		read_file(char *file, t_data *map);
void		get_size(int fd, t_data *map);
int			**fill_matrix(char *file, t_data *map);
void		free_matrix(char **matrix);
void		draw_line(int x0, int x1, int y0, int y1, mlx_image_t *img);
t_points	isometric(t_data *map);