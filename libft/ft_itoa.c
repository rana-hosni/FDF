/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:02 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/07 11:33:19 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

static int	size_of_n(long n)
{
	unsigned long	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned long	size;
	long			nbr;

	nbr = n;
	size = size_of_n(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[size] = '\0';
	if (nbr == 0)
		*str = '0';
	while (size-- && nbr > 0)
	{
		str[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

// int main(void)
// {
// 	printf("%s",ft_itoa(0));
// }