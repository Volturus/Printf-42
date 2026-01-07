/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:02:01 by vmourey           #+#    #+#             */
/*   Updated: 2025/12/09 17:04:41 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	ft_printf_s(char *s)
{
	int	length;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (4);
	}
	length = 0;
	while (s[length])
		length++;
	write(1, s, length);
	return (length - 2);
}
