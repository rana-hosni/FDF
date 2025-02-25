/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:40:20 by relgheit          #+#    #+#             */
/*   Updated: 2024/09/25 10:40:20 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
		return (c);
	}
	return (c);
}

// int	main (void)
// {
// 	int	i;
// 	i	= 0;
// 	char	str[] = "hello WORld!!";
// 	while (str[i])
// 	{
// 		printf("%c",ft_tolower(str[i]));
// 		i++;
// 	}
// }