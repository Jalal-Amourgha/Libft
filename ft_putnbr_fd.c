/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:02:52 by jamourgh          #+#    #+#             */
/*   Updated: 2025/10/27 17:16:00 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[33];
	long	ln;
	int		idx;

	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	ln = n;
	if (ln < 0)
		ln *= -1;
	idx = 0;
	while (ln > 0)
	{
		buffer[idx++] = (ln % 10) + '0';
		ln /= 10;
	}
	if (n < 0)
		buffer[idx++] = '-';
	while (--idx >= 0)
		write(fd, &buffer[idx], 1);
}
