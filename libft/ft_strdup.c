/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:31:41 by relgheit          #+#    #+#             */
/*   Updated: 2025/02/28 16:34:10 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
//This function takes a string and returns a pointer to
// a new string which is a copy.
char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	if ((size + 1) != 0)
	{
		while (s[i] && i < (size))
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
	free ((void *)s);
	return (p);
}
// int	main()
// {
// 	char *s = "Hello";
// 	printf("%s", ft_strdup(s));
// }