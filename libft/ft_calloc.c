/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:14:34 by relgheit          #+#    #+#             */
/*   Updated: 2024/10/08 10:14:38 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//same as malloc but sets the memory allocated with '\0'

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	p = malloc(size * nmemb);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return (p);
}
