/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nllhh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:44:31 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 18:56:27 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				process_n(va_list *argptr, int *wpl, char *flags)
{
	long long *address;

	address = get_nlen(argptr, flags);
	if (address)
		*address = wpl[2];
	else
		*address = 0;
}

long long			*get_nlen(va_list *argptr, char *flags)
{
	long long			*arg;
	int					sumarg;

	sumarg = flags[6] + flags[7];
	if (sumarg == 0)
		arg = (long long*)va_arg(*argptr, int *);
	else if (sumarg == 104)
		arg = (long long *)va_arg(*argptr, int *);
	else if (sumarg == 108)
		arg = (long long *)va_arg(*argptr, long int *);
	else if (sumarg == 208)
		arg = (long long *)va_arg(*argptr, int *);
	else
		arg = (long long *)va_arg(*argptr, long long int *);
	return (arg);
}

/*
** 104 h | 108 l | 208 hh | 216 ll
*/

long long			get_ilen(va_list *argptr, char *flags)
{
	long long	arg;
	int			sumarg;

	sumarg = flags[6] + flags[7];
	if (sumarg == 0)
		arg = (long long)va_arg(*argptr, int);
	else if (sumarg == 104)
		arg = (short int)va_arg(*argptr, int);
	else if (sumarg == 108)
		arg = va_arg(*argptr, long int);
	else if (sumarg == 208)
		arg = (char)va_arg(*argptr, int);
	else
		arg = (long long)va_arg(*argptr, long long int);
	return (arg);
}

/*
** 104 h | 108 l | 208 hh | 216 ll
*/

unsigned long long	get_uxxlen(va_list *argptr, char *flags)
{
	unsigned long long	arg;
	int					sumarg;

	sumarg = flags[6] + flags[7];
	if (sumarg == 0)
		arg = va_arg(*argptr, unsigned int);
	else if (sumarg == 104)
		arg = (unsigned short int)va_arg(*argptr, unsigned int);
	else if (sumarg == 108)
		arg = va_arg(*argptr, unsigned long int);
	else if (sumarg == 208)
		arg = (unsigned char)va_arg(*argptr, unsigned int);
	else
		arg = va_arg(*argptr, unsigned long long int);
	return (arg);
}
