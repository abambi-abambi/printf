/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:27:11 by abambi            #+#    #+#             */
/*   Updated: 2021/01/29 16:37:35 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int					ft_printf(const char *line, ...);
void				init_values(void *s, size_t n, int *dimensions);
int					parse_line(va_list *argptr, char const *line);
char const			*modifiers(char const *line, char *flags_conversions, \
									int *dimensions, va_list *argptr);
void				conversions(char const *line, char *flags_conversions, \
									int *dimensions, va_list *argptr);

/*
** set flags
*/

char const			*set_l(char const *line, char *set_flags);
char const			*set_h(char const *line, char *set_flags);
char const			*read_precision(char const *line, char *set_flags, \
									int *dimensions, va_list *argptr);
char const			*read_width(const char *line, char *set_flags, \
									int *dimensions, va_list *argptr);

/*
** length
*/

int					ptrlen(unsigned long long number, int *dimensions);
int					nbrlen(unsigned number, int base);
size_t				ft_strlen(const char *str);
long long			*get_nlen(va_list *argptr, char *flags);
long long			get_ilen(va_list *argptr, char *flags);
unsigned long long	get_uxxlen(va_list *argptr, char *flags);
int					sign_num(char *flags);
int					precision_zeros(int *dimensions, int *zeros, int length);

/*
** print
*/

void				ft_putchar(char c, int *dimensions);
void				ft_putstr(char *s, int *dimensions, int length);
int					ft_putnbr(unsigned num, unsigned base, \
								char *flags, int *dimensions);
int					print_sign(char *flags, int *dimensions);
int					print_prefix(int *dimensions, char *flags);
int					print_width(int length, int *dimensions, \
								char *flags_conversions);
int					print_precision(int zeros, int *dimensions);
int					print_p(void *address, int *dimensions, \
								char *flags_conversions);
int					print_c(char c, int *dimensions, char *flags_conversions);
int					print_i(unsigned num, char *flags_conversions, \
								int *dimensions, unsigned base);
void				print_s(char *str, int *dimensions, \
								char *flags_conversions);
int					print_ptrhex(unsigned long long number, \
								char *flags, int *dimensions);

/*
** compare
*/

int					ft_isdigit(int x);
int					ft_isequal(char c, const char *ch);

/*
** prepare
*/

void				saveminus_i(va_list *argptr, int *dimensions, char *flags);
void				process_n(va_list *argptr, int *dimensions, char *flags);
int					zero_prec_num(unsigned num, int *dimensions);

#endif
