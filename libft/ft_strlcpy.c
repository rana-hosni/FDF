/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:14:32 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/03 10:09:59 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	unsigned int	i;
	unsigned int	ssize;

	i = 0;
	ssize = 0;
	ssize = ft_strlen(src);
	if (dsize != 0)
	{
		while (src[i] && i < (dsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ssize);
}
// int main(void)
// {
// 	// unsigned int size;
// 	// size = 10;
// 	char dest[2] = "hi";
// 	char src[] = "hello";

// 	printf("%ld\n", ft_strlcpy(dest, src, 3));
//     printf("%s",dest);
// }