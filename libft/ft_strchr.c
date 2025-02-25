/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:34:42 by relgheit          #+#    #+#             */
/*   Updated: 2024/09/25 10:39:17 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((char) c == *str)
			return ((char *)str);
		str++;
	}
	if ((char) c == '\0')
		return ((char *)str);
	return (0);
}

// int main()
// {
//     const char str[] = " hello";
//     char    c;
//     c = ' ';
//     printf("%s",ft_strchr(str, c));
// }
