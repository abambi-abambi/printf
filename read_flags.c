/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:55:26 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 18:43:57 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

char const	*read_width(const char *line, char *set_flags, int *wpl, \
						va_list *argptr)
{
	set_flags[4] = 1;
	if (*line == '*')
	{
		wpl[0] = va_arg(*argptr, int);
		if (wpl[0] < 0)
		{
			set_flags[5] = '-';
			wpl[0] = -wpl[0];
		}
	}
	else
	{
		wpl[0] = 0;
		while (ft_isdigit(*line) == 1)
		{
			wpl[0] = wpl[0] * 10;
			wpl[0] = wpl[0] + (*line - '0');
			line++;
		}
		line--;
	}
	return (line);
}

char const	*read_precision(char const *line, char *set_flags, \
							int *wpl, va_list *argptr)
{
	++line;
	set_flags[3] = 1;
	if (*line == '*')
	{
		if ((wpl[1] = va_arg(*argptr, int)) < 0)
		{
			set_flags[3] = 0;
			wpl[1] = -1;
		}
	}
	else if (ft_isdigit(*line))
	{
		wpl[1] = 0;
		while (ft_isdigit(*line))
			wpl[1] = (wpl[1] * 10) + (*line++ - '0');
		line--;
	}
	else
	{
		wpl[1] = 0;
		line--;
	}
	return (line);
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

char const	*set_l(char const *line, char *set_flags)
{
	if (*(line + 1) == 'l')
	{
		set_flags[6] = 'l';
		set_flags[7] = 'l';
		return (line + 1);
	}
	set_flags[6] = 'l';
	return (line);
}

char const	*set_h(char const *line, char *set_flags)
{
	if (*(line + 1) == 'h' && set_flags[6] != 'h')
	{
		set_flags[6] = 'h';
		set_flags[7] = 'h';
		return (line + 1);
	}
	set_flags[6] = 'h';
	set_flags[7] = 0;
	return (line);
}

void		saveminus_i(va_list *argptr, int *wpl, char *flags)
{
	int			arg;
	unsigned	num;

	arg = va_arg(*argptr, int);
	if (arg < 0)
	{
		flags[0] = '-';
		num = -arg;
	}
	else
	{
		num = arg;
	}
	print_i(num, flags, wpl, 10);
}
