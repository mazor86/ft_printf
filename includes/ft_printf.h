/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:44:12 by mazor             #+#    #+#             */
/*   Updated: 2020/07/25 23:44:24 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# define MAX_SINGLE_CONVERSION_SIZE 4096
# define DECIMAL_BASE "0123456789"
# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

typedef struct	s_carriage
{
	char		*str_start;
	char		*format_current;
	int			spec_len;
	int			tot_print;
	int			va_on;
}				t_carriage;

typedef struct	s_flag
{
	int			zero;
	int			minus;
	int			space;
	int			hash;
	int			plus;
	int			min_width;
	int			precision;
	char		conversion;
}				t_flag;

int		ft_printf(const char *, ...);
int		parse(t_carriage *car, va_list *ap);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
void	ft_itoa_base(int number, char *str, char *base);
void	ft_utoa_base(unsigned int number, char *result, char *base);
void	ft_ulltoa_base(unsigned long long number, char *result, char *base);

#endif