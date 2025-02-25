/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:24:03 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/04 17:04:08 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "+\t\v\f\r\n \f1234";
// 	// ft_atoi(str);
// 	printf("%d\n", atoi(str));
// 	printf("%d", ft_atoi(str));
// 	return 0 ;
// }