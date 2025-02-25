/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:27:53 by relgheit          #+#    #+#             */
/*   Updated: 2024/09/25 10:40:38 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
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
// 		printf("%c",ft_toupper(str[i]));
// 		i++;
// 	}
// }
