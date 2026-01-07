/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:48:47 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/26 17:47:37 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libftprintf.h"

static long long unsigned int	nbrcolumn_llu(long long unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n = n / 16;
		count = count + 1;
	}
	return (count);
}

static char	*convert_to_hexa_llu(long long unsigned int c)
{
	char	*hex;
	char	*retour;
	int		i;
	int		column;

	column = nbrcolumn_llu(c);
	i = 1;
	hex = "0123456789abcdef";
	retour = (char *) malloc (sizeof(char) * column);
	while (c >= 16)
	{
		retour[column - i] = hex[c % 16];
		c = c / 16;
		i++;
	}
	retour[column - i] = hex[c % 16];
	i++;
	return (retour);
}

static int	ft_printf_x_llu(long long unsigned int d)
{
	long long unsigned int		i;
	long long unsigned int		length;
	char						*s;

	s = convert_to_hexa_llu(d);
	length = nbrcolumn_llu(d);
	i = 0;
	while (i < length)
	{
		write(1, s + i, 1);
		i++;
	}
	free(s);
	return (length - 2);
}

int	ft_printf_p(long long unsigned int p)
{
	int	retour;

	if ((void *)p == NULL)
	{
		ft_printf_s("(nil)");
		return (3);
	}
	ft_printf_s("0x");
	retour = 2 + ft_printf_x_llu(p);
	return (retour);
}

// #include <stdio.h>

/* int main()
{
	int d = -45694;
	ft_printf_p((long long unsigned int)&d);
	printf("\n%p", &d);
} */