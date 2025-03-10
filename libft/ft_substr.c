/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:02:00 by rana              #+#    #+#             */
/*   Updated: 2025/03/05 13:02:10 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// #include <stdio.h>
//This function takes a string and finds a substring given the
//length and the position.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	s_len;
	size_t			i;

	i = 0;
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
	if ((len + 1) != 0)
	{
		while (s[i] && i < (len))
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*out;
// 	size_t	l;

// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		out = malloc(sizeof(char));
// 		if (!out)
// 			return (NULL);
// 		out[0] = '\0';
// 		return (out);
// 	}
// 	if (ft_strlen(s) - start < len)
// 		l = ft_strlen(s) - start;
// 	else
// 		l = len;
// 	out = malloc((l + 1) * sizeof(char));
// 	if (!out)
// 		return (NULL);
// 	ft_strlcpy(out, s + start, l + 1);
// 	return (out);
// }
