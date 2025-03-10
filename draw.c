/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:35 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/10 15:09:23 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *map, mlx_image_t *img)
{
	int		i;
	int		j;
	int		dx;
	int		dy;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (j + 1 < map->y)
			{
				dx = j - (j + 1);
				dy = map->matrix[i][j] - map->matrix[i][j + 1];
				if (dx < dy)
				{
					while (dx < dy)
					{
						mlx_put_pixel(img, i, j, 0x00FF00FF);
						dx++;
					}
				}
				else
				{
					while (dy < dx)
					{
						mlx_put_pixel(img, i, j, 0x00FF00FF);
						dy++;
					}
				}
			}
			j++;
		}
	}
	
}