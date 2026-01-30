/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 05:58:03 by masantos          #+#    #+#             */
/*   Updated: 2025/08/06 07:07:22 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		print_char(*str++);
		count++;
	}
	return (count);
}

int	print_signed(long n, int base, char *symbols, int is_signed)
{
	int count;

	count = 0;
	if (is_signed && n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n >= (long)base)
		count += print_signed(n / base, base, symbols, 0);
	count += print_char(symbols[n % base]);
	return (count);
	}

int print_hex_uintptr(uintptr_t num, char *symbols)
{
	char buffer[sizeof(uintptr_t) * 2];
	int i;
	int count;

	i = 0;
	count = 0;
	if (num == 0)
		return(count + print_char('0'));
	while (num > 0)
	{
		buffer[i] = symbols[num % 16];
		i++;
		num /= 16;
	}
	while (i > 0)
	{
		i--;
		count += print_char(buffer[i]);
	}
	return (count);
}

int	print_pointer(void *ptr)
{
	uintptr_t num;
	int count;

	count = 0;
	num = (uintptr_t)ptr;
	count += print_str("0x");
	if (num == 0)
		return (count += print_char('0'));
	return (count + print_hex_uintptr(num, "0123456789abcdef"));
}

int print_unsigned_base(unsigned long num, int base, char*symbols)
{
	int count;

	count = 0;
	if (num >= (unsigned long)base)
		count += print_unsigned_base(num / base, base, symbols);
	count += print_char(symbols[num % base]);
	return (count);
}

int	print_conversion(char especifier, va_list ap)
{
	int	count;

	count = 0;
	if (especifier == 'c')
		return (count += print_char(va_arg(ap, int)));
	else if (especifier == 's')
		return (count += print_str(va_arg(ap, char *)));
	else if (especifier == 'd')
		return (count += print_signed((long)va_arg(ap, int), 10, "0123456789", 1));
	else if (especifier == 'i')
		return (count += print_signed(va_arg(ap, int), 10, "0123456789", 1));
	else if (especifier == 'u')
		return (count += print_unsigned_base(va_arg(ap, unsigned long), 10, "0123456789"));
	else if (especifier == 'x')
		return (count += print_unsigned_base(va_arg(ap, unsigned int), 16, "0123456789abcdef"));
	else if  (especifier == 'X')
		return (count += print_unsigned_base(va_arg(ap, unsigned int), 16,"0123456789ABCDEF"));
	else if (especifier == 'p')
		return (count += print_pointer(va_arg(ap, void *)));
	else if (especifier == '%')
		return (print_char('%'));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
			count += print_conversion(*(++str), ap);
		else
			count += print_char(*str);
		str++;
	}
	va_end(ap);
	return (count);
}
