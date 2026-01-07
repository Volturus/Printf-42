/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:43:05 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/14 14:45:20 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

	i = 1;
	column = nbrcolumn(c);
	hex = "0123456789ABCDEF";
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

int	ft_printf_xx(unsigned int d)
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
	int d = 452;
	printf("%X \n", d);
	ft_printf_X(d);
} */