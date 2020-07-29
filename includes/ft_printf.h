/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:44:12 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 17:12:28 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# define MAX_SINGLE_CONV 65536
# define DIGIT_CAPACITY 64
# define DECIMAL_BASE "0123456789"
# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

typedef struct	s_carriage
{
	const char	*str_start;
	const char	*format_current;
	int			spec_len;
	int			tot_print;
}				t_carriage;

typedef struct	s_flag
{
	int			zero;
	int			minus;
	int			min_w;
	int			prec;
	int			def_len;
}				t_flag;

int				ft_printf(const char *format, ...);
int				parse(t_carriage *car, va_list *ap);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_itoa_base(int number, char *str, char *base);
void			ft_utoa_base(unsigned int number, char *result, char *base);
void			ft_ulltoa_base(unsigned long long number,\
								char *result, char *base);
int				conversion_percent(t_flag *flags);
int				conversion_char(unsigned char c, t_flag *fl);
int				conversion_integer(int num, t_flag *fl);
int				conversion_unsigned(unsigned int num, t_flag *fl, char spec);
int				conversion_string(char *str, t_flag *fl);
int				conversion_pointer(unsigned long long adress, t_flag *fl);
char			*init_base(char spec);
int				print_spaces(int min_w);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			flag_analysis(t_flag *flags);

#endif
