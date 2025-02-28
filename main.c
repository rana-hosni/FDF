/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:29:12 by relgheit          #+#    #+#             */
/*   Updated: 2025/02/28 16:58:09 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 500
#define HEIGHT 500

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x = 50;
	int			y = 50;
	int			fd;
	char 		*line;

	line = NULL;
	fd = open("maps/test_maps/10-2.fdf", O_RDONLY);
	line = get_next_line(fd);
	ft_printf("%s\n", line);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (1);
	while (x < 200)
	{
		mlx_put_pixel(img, x, y, 0x00FF00FF);
		x++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}