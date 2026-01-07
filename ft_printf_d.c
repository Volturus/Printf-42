/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:44:52 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/26 16:51:24 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libftprintf.h"

int	ft_printf_d(int d)
{
	int		i;
	int		length;
	char	*s;

	s = ft_itoa(d);
	i = 0;
	length = 0;
	while (s[length])
		length++;
	while (i < length)
	{
		write(1, s + i, 1);
		i++;
	}
	free(s);
	return (length - 2);
}

/* #include <stdio.h>

int main()
{
	int d = 10649;
	ft_printf_d(d);
	printf(" %d", d);
} */