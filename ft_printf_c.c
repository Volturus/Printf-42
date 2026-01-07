/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:44:56 by vmourey           #+#    #+#             */
/*   Updated: 2025/11/26 17:50:11 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf_c(char c)
{
	char	s[1];

	s[0] = c;
	write(1, s, 1);
	return (-1);
}

/* #include <stdio.h>

int main()
{
	char c = 'A';
	ft_printf_c(c);
	printf("\n%c", c);
} */