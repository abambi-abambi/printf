/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 00:09:21 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 18:42:34 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isequal(char c, const char *ch)
{
	int i;

	i = 0;
	while (ch[i] != '\0')
	{
		if (c == ch[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_isdigit(int x)
{
	if (x >= 48 && x <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c, int *wpl)
{
	write(1, &c, 1);
	wpl[2] += 1;
}

void	ft_putstr(char *s, int *wpl, int length)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (*s != '\0' && (i < length))
	{
		ft_putchar(*s, wpl);
		s++;
		i++;
	}
}
