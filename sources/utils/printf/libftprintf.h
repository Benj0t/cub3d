/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:50:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/03 22:52:03 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

int			ft_printf(char *format, ...);
int			ft_strlen(char *str);
int			ft_intlen(int nb);
int			ft_intlen_u(unsigned int nb);
int			ft_putchar(unsigned char c);
void		ft_putstrr(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_isdigit(int ch);
char		*ft_strjoin(char *s1, char *s2);
int			ft_atoi(char *str, int *i);
int			ft_charset(char c);
int			count_args(char *str);
int			**init_tab(char *str);
int			findarg(char *str, int *i, int *tab);
void		det_args(char *str, int ***tab);
int			printf_char(va_list *ap, int *tab);
int			printf_str(va_list *ap, int *tab);
int			printf_addr(va_list *ap, int *tab);
int			printf_nbr(va_list *ap, int *tab);
int			printf_unbr(va_list *ap, int *tab);
int			printf_hnbr_l(va_list *ap, int *tab);
int			printf_hnbr_u(va_list *ap, int *tab);
int			printf_pourc(va_list *ap, int *tab);
void		ft_str_args(int *tab, va_list *ap);
void		ft_ifnot_minus(int *tab, int bool, int nb, char *str);
void		ft_if_minus(int *tab, int *bool, int nb, char *str);
void		ft_hex_args(int *tab, va_list *ap);
void		ft_nbr_args(int *tab, va_list *ap);
void		ft_unbr_args(int *tab, va_list *ap);
void		ft_prec_f(char *str, int *i, int *tab);
void		ft_len_f(char *str, int *i, int *tab);
int			ft_zero(int larg);
char		*ft_nzero(void);
#endif
