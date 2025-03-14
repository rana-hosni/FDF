/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:35 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/14 13:21:20 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_points	isometric(t_data *map)
{
	t_points	*points;
	int		i;
	int		x;
	int		y;
	
	points = (t_points *)malloc(sizeof(t_points) * map->x * map->y);
	if (!points)
		exit(1);

	x = 0;
	i = 0;
	while(x < map->x)
	{
		y = 0;
		while(y < map->y)
		{
			points[i].x = (x - y) * cos(0.523599);
			points[i].y = (x + y) * sin(0.523599) - map->matrix[x][y];
			i++;
			y++;
		}
		x++;
	}
	return (*points);
}
void	draw_line(int x0, int x1, int y0, int y1, mlx_image_t *img)
{
	int		i;
	int		dx;
	int		dy;
	int 	d;

	dx = x1 - x0;
	dy = y1 - y0;
	d = (2 * dy) - dx;
	i = 0;
	if (abs(dx) > abs(dy))
	{
		while (i < dx)
		{
			mlx_put_pixel(img, x0, y0, 0xFF0000FF);
			if (d > 0)
			{
				d = d - (2 * dx);
				y0++;
			}
			d = d + (2 * dy);
			x0++;
			i++;
		}
	}
	else
	{
		while (i < dy)
		{
			mlx_put_pixel(img, x0, y0, 0xAAFF00FF);
			if (d > 0)
			{
				d = d - (2 * dy);
				x0++;
			}
			d = d + (2 * dx);
			y0++;
			i++;
		}
	}
}

