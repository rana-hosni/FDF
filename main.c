/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:29:12 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/05 09:45:41 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 500
#define HEIGHT 500

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*map;
	int			x = 50;
	int			y = 50;

	if (ac != 2)
	{
		ft_printf("check your inputs");
		return (1);
	}
	map = (t_data *)malloc(sizeof(t_data));
	if (!map)
		return (1);
	read_file(av[1], map);
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
