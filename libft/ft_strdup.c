/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:31:41 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/07 11:57:12 by relgheit         ###   ########.fr       */
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

	size = ft_strlen(s);
	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s, size + 1);
	return (p);
}
// int	main()
// {
// 	char *s = "Hello";
// 	printf("%s", ft_strdup(s));
// }