/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:10:52 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/04 08:38:08 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <math.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	    *get_next_line(int fd);
// static char	*read_fun(int fd, char *tmp, char *buffer);
// static char	*clean_fun(char *str, char *buffer);
// static char	*clean_buffer(char *buffer);
void        read_file(char *file);
