/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:44 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/26 17:00:45 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libftprintf.h"
#include <stdio.h>

int	ft_printf_u(unsigned int d)
{
	unsigned int	i;
	unsigned int	length;
	char			*s;

	s = ft_itoa_u(d);
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

// #include <stdio.h>

/* int main()
{
	int d;

	d = -10649;
	ft_printf_u(d);
	printf(" %u", d);
}  */