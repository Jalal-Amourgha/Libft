/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:51:10 by jamourgh          #+#    #+#             */
/*   Updated: 2025/10/27 17:15:20 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	idx;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	map = malloc(len + 1);
	if (!map)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		map[idx] = f(idx, s[idx]);
		idx++;
	}
	map[idx] = '\0';
	return (map);
}
