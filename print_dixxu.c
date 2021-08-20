/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dixxu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:15:54 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 19:06:47 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_prec_num(unsigned num, int *wpl)
{
	if (num == 0 && wpl[1] == 0)
	{
		wpl[1] = 0;
		return (-1);
	}
	return (0);
}

int		precision_zeros(int *wpl, int *o, int length)
{
	if (wpl[1] > length)
	{
		*o = wpl[1] - length;
		length = wpl[1];
	}
	else
	{
		*o = 0;
	}
	return (length);
}

int		sign_num(char *flags)
{
	if (flags[0] == '-' || flags[1] == ' ' || flags[1] == '+')
		return (1);
	return (0);
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
**
**	unsigned sn = scale of notation (base)
*/

int		print_i(unsigned n, char *flags, int *wpl, unsigned sn)
{
	int	length;
	int	o;
	int	i;

	length = nbrlen(n, sn) + zero_prec_num(n, wpl);
	length = precision_zeros(wpl, &o, length) + sign_num(flags);
	flags[5] = (wpl[1] >= 0 && flags[5] == '0') ? 0 : flags[5];
	if (flags[5] == '0')
		return (print_sign(flags, wpl)
		+ print_prefix(wpl, flags)
		+ print_width(length, wpl, flags)
		+ print_precision(o, wpl)
		+ (i = ((wpl[1] == 0 && n == 0) ? 0 : (ft_putnbr(n, sn, flags, wpl)))));
	else if (flags[5] == '-')
		return (print_sign(flags, wpl)
		+ print_prefix(wpl, flags)
		+ print_precision(o, wpl)
		+ (i = ((wpl[1] == 0 && n == 0) ? 0 : (ft_putnbr(n, sn, flags, wpl))))
		+ print_width(length, wpl, flags));
	else
		return (print_width(length, wpl, flags)
		+ print_sign(flags, wpl)
		+ print_prefix(wpl, flags)
		+ print_precision(o, wpl)
		+ (i = ((wpl[1] == 0 && n == 0) ? 0 : (ft_putnbr(n, sn, flags, wpl)))));
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

int		ft_putnbr(unsigned num, unsigned base, char *flags, int *wpl)
{
	int		i;
	int		shift;

	shift = 0;
	if (flags[8] == 'X')
		shift = 32;
	if (num >= base)
	{
		ft_putnbr((num / base), base, flags, wpl);
		ft_putnbr((num % base), base, flags, wpl);
	}
	else
	{
		if (num < 10)
			i = num + '0';
		else
			i = num - 10 + 'a' - shift;
		ft_putchar(i, wpl);
	}
	return (4);
}
