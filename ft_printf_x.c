/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:20:27 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/14 14:45:56 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	nbrcolumn(unsigned int n)
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

static char	*convert_to_hexa(unsigned int c)
{
	char	*hex;
	char	*retour;
	int		i;
	int		column;

	column = nbrcolumn(c);
	i = 1;
	hex = "0123456789abcdef";
	retour = (char *) malloc (sizeof(char) * nbrcolumn(c));
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

int	ft_printf_x(unsigned int d)
{
	int		i;
	int		length;
	char	*s;

	s = convert_to_hexa(d);
	i = 0;
	length = nbrcolumn(d);
	i = 0;
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
	int d = 154257036;
	printf("%llx \n", (unsigned long long)d);
	ft_printf_x(d);
} */