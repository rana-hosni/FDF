/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:46:08 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/04 17:38:03 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	if ((!src && dstsize == 0) || (!dest && dstsize == 0))
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && ((dest_len + i) < (dstsize - 1)))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
// #include <stdio.h>
// int main(void)
// {
// 	// unsigned int size;
// 	// size = 10;
// 	char s1[11] = "a";
// 	// char *src = "hello";

// 	printf("%lu", ft_strlcat(s1, "lorem", 6));
// }
