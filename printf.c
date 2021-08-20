/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:52:04 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 18:41:48 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_values(void *s, size_t n, int *wpl)
{
	unsigned int			i;
	unsigned char			*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = 0;
		i++;
	}
	wpl[0] = -1;
	wpl[1] = -1;
}

int			ft_printf(const char *line, ...)
{
	va_list	argptr;
	int		length;

	length = 0;
	if (!line)
		return (-1);
	va_start(argptr, line);
	length = parse_line(&argptr, line);
	va_end(argptr);
	return (length);
}

/*
** wpl[0] – width
** wpl[1] – precision
** wpl[2] – length of printed (= return of printf)
**
** position:  				   012345678
** filled all flags in array:  -+#.*0llc
**
** [0] '-' & [1] '+' are positions for signes of numbers;
** [1] '+' / ' ' (plus/gap)
** [6] '-' / '0' (align/width's zeros)
*/

int			parse_line(va_list *argptr, const char *line)
{
	char	flags[10];
	int		wpl[3];

	wpl[2] = 0;
	while (*line)
	{
		while (*line && *line != '%')
			ft_putchar(*line++, wpl);
		if (*line == '%')
			line++;
		if (*line == '\0')
			break ;
		init_values(&flags, sizeof(flags), wpl);
		line = modifiers(line, flags, wpl, argptr);
		conversions(line, flags, wpl, argptr);
		if (*line == '\0')
		{
			wpl[2] = -1;
			break ;
		}
		line++;
	}
	return (wpl[2]);
}

/*
**	position	012345678901234567
**	flags =     -+ #.*0123456789lh
*/

char const	*modifiers(char const *line, char *flags, int *wpl, \
					va_list *argptr)
{
	int			i;

	while ((i = (ft_isequal(*line, "-+ #.*0123456789lh"))) >= 0)
	{
		if (i == 0)
			flags[5] = '-';
		else if ((i == 1 || i == 2) && flags[1] != '+')
			flags[1] = *line;
		else if (i == 3)
			flags[2] = '#';
		else if (i == 4)
			line = read_precision(line, flags, wpl, argptr);
		else if (i == 6 && flags[5] != '-' && wpl[0] == -1)
			flags[5] = '0';
		else if (i >= 5 && i <= 15)
			line = read_width(line, flags, wpl, argptr);
		else if (i == 16)
			line = set_l(line, flags);
		else if (i == 17)
			line = set_h(line, flags);
		line++;
	}
	return (line);
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/

/*
**	position	0123456789012
**	types = 	cspdiuxX%nfge
*/

void		conversions(char const *line, char *flags, int *wpl, \
					va_list *argptr)
{
	int	index;

	if ((index = ft_isequal(*line, "cspdiuxX%nfge")) >= 0)
	{
		flags[8] = *line;
		if (index == 0)
			print_c(va_arg(*argptr, int), wpl, flags);
		else if (index == 1)
			print_s(va_arg(*argptr, char *), wpl, flags);
		else if (index == 2)
			print_p(va_arg(*argptr, void *), wpl, flags);
		else if (index == 3 || index == 4)
			saveminus_i(argptr, wpl, flags);
		else if (index == 5)
			print_i(va_arg(*argptr, unsigned), flags, wpl, 10);
		else if (index == 6 || index == 7)
			print_i(va_arg(*argptr, unsigned), flags, wpl, 16);
		else if (index == 8)
			print_c('%', wpl, flags);
		else if (index == 9)
			process_n(argptr, wpl, flags);
	}
}

/*
** position:  		       012345678
** flags[] in array:       - #.*0llc
**                          +   -
*/
