/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:30:06 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 18:43:18 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbrlen(unsigned number, int base)
{
	int	length;

	length = 0;
	if (number == 0)
	{
		length = 1;
		return (length);
	}
	while (number > 0)
	{
		number /= base;
		length++;
	}
	return (length);
}

int		ptrlen(unsigned long long number, int *wpl)
{
	int length;

	length = 0;
	if (number == 0)
	{
		length = 3;
		if (wpl[1] == 0)
			length--;
		return (length);
	}
	else
	{
		while (number > 0)
		{
			number /= 16;
			length++;
		}
		return (length + 2);
	}
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

int		print_sign(char *flags, int *wpl)
{
	if (flags[0] == '-')
	{
		ft_putchar('-', wpl);
	}
	else if (flags[1] != 0 && (flags[8] == 'i' || flags[8] == 'd'))
	{
		ft_putchar(flags[1], wpl);
	}
	return (0);
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

int		print_width(int length, int *wpl, char *flags)
{
	while (length < wpl[0])
	{
		if (flags[5] == '0')
			ft_putchar('0', wpl);
		else
			ft_putchar(' ', wpl);
		length++;
	}
	return (1);
}

int		print_precision(int zeros, int *wpl)
{
	while (zeros > 0)
	{
		ft_putchar('0', wpl);
		zeros--;
	}
	return (2);
}
