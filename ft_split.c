/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:09:43 by jamourgh          #+#    #+#             */
/*   Updated: 2025/10/27 17:14:47 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	i;
	int	j;

	words = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (j > 0)
				words++;
			j = 0;
		}
		else
			j++;
		i++;
	}
	if (j > 0)
		words++;
	return (words);
}

static char	*ft_worddup(const char *s, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	ft_free(char **strs, int i)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (0);
}

static int	ft_fill(char **strs, const char *s, char c)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j > i)
		{
			strs[idx] = ft_worddup(s, i, j);
			if (!strs[idx])
				return (ft_free(strs, idx));
			idx++;
		}
		i = j;
	}
	strs[idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	strs = malloc((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!ft_fill(strs, s, c))
		return (NULL);
	return (strs);
}
