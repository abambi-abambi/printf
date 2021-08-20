/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:07:48 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 19:04:53 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

/*
** print char
*/

int		print_c(char c, int *wpl, char *flags)
{
	if (flags[5] == '-')
	{
		ft_putchar(c, wpl);
		print_width(1, wpl, flags);
	}
	else
	{
		print_width(1, wpl, flags);
		ft_putchar(c, wpl);
	}
	return (1);
}

/*
** print string
*/

void	print_s(char *str, int *wpl, char *flags)
{
	int length;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (wpl[1] != -1 && length > wpl[1])
		length = wpl[1];
	if (flags[5] == '-')
	{
		ft_putstr(str, wpl, length);
		print_width(length, wpl, flags);
	}
	else
	{
		print_width(length, wpl, flags);
		ft_putstr(str, wpl, length);
	}
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

/*
** print pointer
*/

int		print_p(void *address, int *wpl, char *flags)
{
	int				length;
	unsigned long	n;
	int				i;

	n = (address == NULL) ? 0 : (unsigned long)address;
	length = ptrlen(n, wpl);
	if (flags[5] == '0')
		return (print_prefix(wpl, flags)
		+ print_width(length, wpl, flags)
		+ (i = ((wpl[1] == 0 && n == 0) ? 0 : (print_ptrhex(n, flags, wpl)))));
	else if (flags[5] == '-')
		return (print_prefix(wpl, flags)
		+ (i = ((wpl[1] == 0 && n == 0) ? 0 : (print_ptrhex(n, flags, wpl))))
		+ print_width(length, wpl, flags));
	else
		return (print_width(length, wpl, flags)
		+ print_prefix(wpl, flags)
		+ (i = ((wpl[1] == 0 && n == 0) ? 0 : (print_ptrhex(n, flags, wpl)))));
}

int		print_prefix(int *wpl, char *flags)
{
	if (flags[8] == 'p')
		ft_putstr("0x", wpl, 2);
	return (9);
}

int		print_ptrhex(unsigned long long number, char *flags, int *wpl)
{
	int hex_num;

	if (number < 16)
	{
		if (number >= 10)
			hex_num = number - 10 + 'a';
		else
			hex_num = number + '0';
		ft_putchar(hex_num, wpl);
	}
	if (number >= 16)
	{
		print_ptrhex((number / 16), flags, wpl);
		print_ptrhex((number % 16), flags, wpl);
	}
	return (7);
}
