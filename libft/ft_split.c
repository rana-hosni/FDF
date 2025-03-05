/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:22:24 by relgheit          #+#    #+#             */
/*   Updated: 2025/03/05 16:08:25 by relgheit         ###   ########.fr       */
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

// void	check_arr(char **arr, int pos)
// {
// 	int	i;

// 	i = 0;
// 	if (!arr[pos])
// 	{
// 		while (i < pos)
// 		{
// 			free(arr[i]);
// 			i++;
// 		}
// 		free(arr);
// 	}
// }

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


// static char		**ft_free_all(char **p);
// static int		ft_ischar(char src, char c);
// static size_t	ft_split_strcount(char *s, char c);
// static size_t	ft_split_strlen(char *s, char c, size_t i);

// char	**ft_split(char const *s, char c)
// {
// 	char	**out;
// 	char	*str;
// 	int		i;
// 	int		o;

// 	str = (char *) s;
// 	out = (char **)malloc((ft_split_strcount(str, c) + 1) * sizeof(char *));
// 	if (!out)
// 		return (NULL);
// 	i = 0;
// 	o = 0;
// 	while (str[i])
// 	{
// 		if ((i == 0 && !ft_ischar(str[i], c)) || \
// 		(i > 0 && ft_ischar(str[i - 1], c) && !ft_ischar(str[i], c)))
// 		{
// 			out[o] = ft_substr(str, i, ft_split_strlen(str, c, i));
// 			if (!out[o])
// 				return (ft_free_all(out));
// 			o++;
// 		}
// 		i++;
// 	}
// 	out[o] = NULL;
// 	return (out);
// }

// static size_t	ft_split_strlen(char *s, char c, size_t i)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[i] && !ft_ischar(s[i], c))
// 	{
// 		len++;
// 		i++;
// 	}
// 	return (len);
// }

// static char	**ft_free_all(char **p)
// {
// 	size_t	i;

// 	i = 0;
// 	while (p[i])
// 	{
// 		free(p[i]);
// 		i++;
// 	}
// 	free(p);
// 	return (NULL);
// }

// static int	ft_ischar(char src, char c)
// {
// 	if (src == c)
// 		return (1);
// 	return (0);
// }

// static size_t	ft_split_strcount(char *s, char c)
// {
// 	int		i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (i == 0 && !ft_ischar(s[i], c))
// 			count++;
// 		else if (i > 0 && ft_ischar(s[i - 1], c) && !ft_ischar(s[i], c))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }