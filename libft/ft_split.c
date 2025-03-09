/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rana <rana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:22:24 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/08 22:00:43 by rana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

static void	check_arr(char **arr, int pos)
{
	int	i;

	i = 0;
	if (!arr[pos])
	{
		while (i < pos)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
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
		check_arr(arr, i - 1);
	}
	arr[i] = NULL;
	return (arr);
}
