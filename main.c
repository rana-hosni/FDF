/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:29:12 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/10 15:08:51 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

#define WIDTH 500
#define HEIGHT 500

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			**matrix;
	int			x = 50;
	int			y = 50;
	int			fd;
	char		*file;
	t_data		*map;

	if (ac != 2)
	{
		ft_printf("Wrong input\n");
		return (1);
	}
	file = av[1];
	map = (t_data *)malloc(sizeof(t_data));
	if (!map)
		return (1);
	read_file(file, map);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (1);
	draw_line(map, img);
	// while (x < 200)
	// {
	// 	mlx_put_pixel(img, x, y, 0x00FF00FF);
	// 	x++;
	// }
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map);
	return (0);
}