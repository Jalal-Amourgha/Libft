/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:23:08 by jamourgh          #+#    #+#             */
/*   Updated: 2025/10/27 17:14:11 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_zero(void)
{
	char	*zero;

	zero = malloc(2);
	if (!zero)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

static	int	ft_fill_buffer(char *buffer, long ln, int sign)
{
	int	idx;

	idx = 0;
	while (ln > 0)
	{
		buffer[idx++] = (ln % 10) + '0';
		ln /= 10;
	}
	if (sign < 0)
		buffer[idx++] = '-';
	return (idx);
}

char	*ft_itoa(int n)
{
	char	*sn;
	char	buffer[33];
	long	ln;
	int		size;
	int		i;

	if (n == 0)
		return (ft_zero());
	ln = n;
	if (ln < 0)
		ln *= -1;
	size = ft_fill_buffer(buffer, ln, n);
	sn = malloc(size + 1);
	if (!sn)
		return (NULL);
	i = 0;
	while (--size >= 0)
		sn[i++] = buffer[size];
	sn[i] = '\0';
	return (sn);
}
