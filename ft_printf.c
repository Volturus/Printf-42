/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:29 by vmourey           #+#    #+#             */
/*   Updated: 2025/12/09 17:20:42 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

static int	length(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	printf_choice(va_list arg, int len_arg, int i, const char *s)
{
	char	c;

	c = s[i + 1];
	if (c == 'c')
		len_arg += ft_printf_c((int) va_arg (arg, int));
	else if (c == 'd' || c == 'i')
		len_arg += ft_printf_d((int) va_arg (arg, int));
	else if (c == '%')
		len_arg += ft_printf_perc();
	else if (c == 's')
		len_arg += ft_printf_s((char *) va_arg (arg, char *));
	else if (c == 'x')
		len_arg += ft_printf_x((int) va_arg (arg, int));
	else if (c == 'X')
		len_arg += ft_printf_xx((int) va_arg (arg, int));
	else if (c == 'u')
		len_arg += ft_printf_u((unsigned int) va_arg (arg, unsigned int));
	else if (c == 'p')
		len_arg += ft_printf_p((unsigned long long) va_arg \
(arg, unsigned long long));
	return (len_arg);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len_arg;

	if (s == NULL)
		return (-1);
	va_start(arg, s);
	i = 0;
	len_arg = 0;
	while (length(s) > i)
	{
		if (s[i] == '%')
		{
			len_arg = printf_choice(arg, len_arg, i, s);
			i = i + 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (i + len_arg);
}

/* #include <stdio.h>
#include <limits.h>

void test_char(void)
{
	printf("\n=== Testing %%c ===\n");
	printf("%d result printf\n", printf("printf:    |%c|\n", 'A'));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%c|\n", 'A'));
	printf("%d result printf\n", printf("printf:    |%c|\n", 'z'));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%c|\n", 'z'));
	printf("%d result printf\n", printf("printf:    |%c|\n", '0'));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%c|\n", '0'));
	printf("%d result printf\n", printf("printf:    |%c|\n", 0));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%c|\n", 0));
}

void test_string(void)
{
	printf("\n=== Testing %%s ===\n");
	printf("%d result printf\n", printf("printf:   |%s|\n", "Hello World"));
	printf("%d result ftprintf\n", ft_printf("ftprintf: |%s|\n", "Hello World"));
	printf("%d result printf\n", printf("printf:    |%s|\n", ""));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%s|\n", ""));
	printf("%d result printf\n", printf("printf:    |%s|\n", (char *)NULL));
	printf("%d result ft_printf\n", 
//ft_printf("ft_printf: |%s|\n", (char *)NULL));
	printf("%d result printf\n", printf("printf:    |%s|\n", "42"));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%s|\n", "42"));
	printf("%d result printf\n", printf("printf:   |%s|\n", "Test string"));
	printf("%d result ftprintf\n", ft_printf("ftprintf: |%s|\n", "Test string"));
}

void test_integers(void)
{
	printf("\n=== Testing %%d and %%i ===\n");
	printf("%d result printf\n", printf("printf:    |%d|\n", 42));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%d|\n", 42));
	printf("%d result printf\n", printf("printf:    |%i|\n", -42));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%i|\n", -42));
	printf("%d result printf\n", printf("printf:    |%d|\n", 0));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%d|\n", 0));
	printf("%d result printf\n", printf("printf:    |%d|\n", INT_MAX));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%d|\n", INT_MAX));
	printf("%d result printf\n", printf("printf:    |%d|\n", INT_MIN));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%d|\n", INT_MIN));
	printf("%d result printf\n", printf("printf:    |%i|\n", 2147483647));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%i|\n", 2147483647));
	printf("%d result printf\n", printf("printf:    |%i|\n", (int)-2147483648));
	printf("%d result ftprintf\n", 
//ft_printf("ft_printf: |%i|\n", (int)-2147483648));
}

void test_unsigned(void)
{
	printf("\n=== Testing %%u ===\n");
	printf("%d result printf\n", printf("printf:    |%u|\n", 42u));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%u|\n", 42u));
	printf("%d result printf\n", printf("printf:    |%u|\n", 0u));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%u|\n", 0u));
	printf("%d result printf\n", printf("printf:    |%u|\n", UINT_MAX));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%u|\n", UINT_MAX));
	printf("%d result printf\n", printf("printf:    |%u|\n", 4294967295u));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%u|\n", 4294967295u));
	printf("%d result printf\n", printf("printf:    |%u|\n", (unsigned int)-1));
	printf("%d result ft_printf\n", 
//ft_printf("ft_printf: |%u|\n", (unsigned int)-1));
}

void test_hex_lower(void)
{
	printf("\n=== Testing %%x ===\n");
	printf("%d result printf\n", printf("printf:    |%x|\n", 42));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", 42));
	printf("%d result printf\n", printf("printf:    |%x|\n", 0));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", 0));
	printf("%d result printf\n", printf("printf:    |%x|\n", 255));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", 255));
	printf("%d result printf\n", printf("printf:    |%x|\n", 16));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", 16));
	printf("%d result printf\n", printf("printf:    |%x|\n", UINT_MAX));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", UINT_MAX));
	printf("%d result printf\n", printf("printf:    |%x|\n", -1));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", -1));
	printf("%d result printf\n", printf("printf:    |%x|\n", 66));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%x|\n", 66));
}

void test_hex_upper(void)
{
	printf("\n=== Testing %%X ===\n");
	printf("%d result printf\n", printf("printf:    |%X|\n", 42));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%X|\n", 42));
	printf("%d result printf\n", printf("printf:    |%X|\n", 0));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%X|\n", 0));
	printf("%d result printf\n", printf("printf:    |%X|\n", 255));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%X|\n", 255));
	printf("%d result printf\n", printf("printf:    |%X|\n", 16));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%X|\n", 16));
	printf("%d result printf\n", printf("printf:    |%X|\n", UINT_MAX));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%X|\n", UINT_MAX));
	printf("%d result printf\n", printf("printf:    |%X|\n", -1));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%X|\n", -1));
}

void test_pointer(void)
{
	printf("\n=== Testing %%p ===\n");
	int var = 42;
	char *str = "test";
 	printf("%d result printf\n", printf("printf:    |%p|\n", &var));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%p|\n", &var));
	printf("%d result printf\n", printf("printf:    |%p|\n", str));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%p|\n", str));
	printf("%d result printf\n", printf("printf:   |%p|\n", (void *)0x42));
	printf("%d result ftprintf\n", ft_printf("ftprintf: |%p|\n", (void *)0x42));
	printf("%d result printf\n", printf("printf:    |%p|\n", NULL));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%p|\n", NULL));
}

void test_percent(void)
{
	printf("\n=== Testing %%%% ===\n");
	printf("%d result printf\n", printf("printf:    |%%|\n"));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%%|\n"));
	printf("%d result printf\n", printf("printf:    |%%%%|\n"));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |%%%%|\n"));
	printf("%d result printf\n", printf("printf:    |100%% success|\n"));
	printf("%d result ft_printf\n", ft_printf("ft_printf: |100%% success|\n"));
}

void test_mixed(void)
{
	printf("\n=== Testing mixed conversions ===\n");
	int num = 42;
	char *text = "test";
 	printf("%d result printf\n", 
//printf("printf:    |%s: %d, %x, %p|\n", text, num, num, &num));
	printf("%d result ft_printf\n", 
//ft_printf("ft_printf: |%s: %d, %x, %p|\n", text, num, num, &num));
 	printf("%d result printf\n", 
//printf("printf:    |%c%c%c %d%%|\n", 'A', 'B', 'C', 100));
	printf("%d result ft_printf\n", 
//ft_printf("ft_printf: |%c%c%c %d%%|\n", 'A', 'B', 'C', 100));
 	printf("%d result printf\n", 
//printf("printf:    |%s %s %s|\n", "Hello", "World", "!"));
	printf("%d result ft_printf\n", 
//ft_printf("ft_printf: |%s %s %s|\n", "Hello", "World", "!"));
}

int main(void)
{
	printf("=== MANDATORY PART TESTS ===\n");
	printf("%d result printf for s == NULL\n", printf((char *)NULL)));
	printf("%d result ft_printf for s == NULL\n", ft_printf((char *)NULL)));
 	test_char();
	test_string();
	test_integers();
	test_unsigned();
	test_hex_lower();
	test_hex_upper();
	test_pointer();
	test_percent();
	test_mixed();
 	printf("\n=== Tests completed ===\n");
	return (0);
}
 */
