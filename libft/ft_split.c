/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:22:24 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/07 11:09:28 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		if (s[i + 1] == '\0' && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_len;
	int		i;

	arr = (char **)malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (!s || !arr)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			arr[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	arr[i] = NULL;
	return (arr);
}
