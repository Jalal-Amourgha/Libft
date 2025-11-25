/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:38:34 by jamourgh          #+#    #+#             */
/*   Updated: 2025/10/27 17:15:28 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_find_start(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_check_char(s[i], set))
		i++;
	return (i);
}

static size_t	ft_find_end(char const *s, char const *set)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && ft_check_char(s[len - 1], set))
		len--;
	return (len);
}

static char	*ft_empty(void)
{
	char	*empty;

	empty = malloc(1);
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	if (start >= end)
		return (ft_empty());
	trim = malloc(end - start + 1);
	if (!trim)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
