/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:10:15 by jamourgh          #+#    #+#             */
/*   Updated: 2025/10/27 17:13:57 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	total_size;
	size_t	i;

	total_size = (nmemb * size);
	tmp = malloc(total_size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)tmp)[i] = 0;
		i++;
	}
	return (tmp);
}
