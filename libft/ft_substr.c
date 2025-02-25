/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:02:00 by rana              #+#    #+#             */
/*   Updated: 2024/10/07 11:55:36 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
//This function takes a string and finds a substring given the
//length and the position.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	p = (char *)malloc(sizeof(char) * (len +1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}

// int main()
// {
//     const char *str = "Hello, world!";
//     char *sub = ft_substr(str, 1, 3);

//     if (sub) {
//         printf("Substring: %s\n", sub);
//         free(sub); // Don't forget to free allocated memory
//     }

//     return 0;
// }