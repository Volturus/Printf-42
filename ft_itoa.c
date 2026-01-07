/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:33:37 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/25 14:51:53 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	nbrcolumn(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count += 1;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		count = count + 1;
	}
	return (count);
}

static void	write_int_min(char *retour)
{
	int		i;
	char	*src;

	i = 0;
	src = "-2147483648";
	while (src[i] != '\0')
	{
		retour[i] = src[i];
		i++;
	}
	retour[i] = '\0';
}

static void	boucle(int n, char *retour, int y)
{
	while (n >= 10)
	{
		retour[nbrcolumn(n) - 1 + y] = (n % 10) + 48;
		n = n / 10;
	}
	retour[nbrcolumn(n) - 1 + y] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*retour;
	int		test_min;

	test_min = 0;
	if (n == -2147483648)
	{
		retour = (char *) malloc (12 * sizeof(char));
		write_int_min(retour);
	}
	else
	{
		retour = (char *) malloc (nbrcolumn(n) + 1 * sizeof(char));
		if (!retour)
			return (NULL);
		if (n < 0)
		{
			test_min = 1;
			retour[0] = '-';
			n = -n;
		}
		boucle(n, retour, test_min);
		retour[nbrcolumn(n) + test_min] = '\0';
	}
	return (retour);
}

/* #include <stdio.h>

int main()
{
	int nbr = 100;
    printf("%s", ft_itoa(nbr));
} */
