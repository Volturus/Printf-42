/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:33:37 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/26 17:00:10 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	nbrcolumn(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count = count + 1;
	}
	return (count);
}

static void	boucle(unsigned int n, char *retour)
{
	while (n >= 10)
	{
		retour[nbrcolumn(n) - 1] = (n % 10) + 48;
		n = n / 10;
	}
	retour[nbrcolumn(n) - 1] = (n % 10) + 48;
}

char	*ft_itoa_u(unsigned int n)
{
	char	*retour;

	retour = (char *) malloc (nbrcolumn(n) + 1 * sizeof(char));
	if (!retour)
		return (NULL);
	boucle(n, retour);
	retour[nbrcolumn(n)] = '\0';
	return (retour);
}

/* #include <stdio.h>

int main()
{
	int nbr = 100;
    printf("%s", ft_itoa(nbr));
} */
