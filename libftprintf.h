/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:30:36 by vmourey           #+#    #+#             */
/*   Updated: 2025/12/09 17:14:10 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>

char	*ft_itoa_u(unsigned int n);
int		ft_printf_x(unsigned int d);
int		ft_printf_xx(unsigned int d);
int		ft_printf_c(char c);
int		ft_printf_d(int d);
int		ft_printf_s(char *s);
int		ft_printf_perc(void);
int		ft_printf_p(long long unsigned int p);
char	*ft_itoa(int n);
int		ft_printf_u(unsigned int d);
int		ft_printf(const char *s, ...);

#endif