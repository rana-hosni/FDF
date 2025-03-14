/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:29:12 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/14 10:44:17 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
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
	x = (WIDTH/2) - ((map->x/2) * SCALE);
	ft_printf("x: %d\n", x);
	isometric(map);
	while (x <= ((WIDTH/2) + ((map->x/2) * SCALE) - SCALE))
	{
		y = (HEIGHT/2) - ((map->y/2) * SCALE);
		while (y <= ((HEIGHT/2) + ((map->y/2) * SCALE) - SCALE))
		{
			if (x == (WIDTH/2) + ((map->x/2) * SCALE) - SCALE
					&& y == (HEIGHT/2) + ((map->y/2) * SCALE) - SCALE)
					break;
			else if (y == (HEIGHT/2) + ((map->y/2) * SCALE) - SCALE)
				draw_line(x, x + SCALE, y, y, img);
			else if (x == (WIDTH/2) + ((map->x/2) * SCALE) - SCALE)
				draw_line(x, x, y, y + SCALE, img);
			else
			{
				draw_line(x, x + SCALE, y, y, img);
				draw_line(x, x, y, y + SCALE, img);
				
			}	
			// mlx_put_pixel(img, x, y, 0x00FF00FF);
			y+= SCALE;
		}
		x+= SCALE;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map);
	return (0);
}
