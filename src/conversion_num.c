/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:42:16 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 16:05:28 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_minus(t_flag *fl, char *result, char *buf, char sign)
{
	int		i;

	i = 0;
	if (fl->prec < 0)
		fl->prec = 1;
	if (sign)
	{
		buf[i++] = sign;
		result++;
		fl->def_len--;
		sign = 1;
	}
	fl->prec = fl->prec > fl->def_len ? fl->prec : fl->def_len;
	while (i < fl->prec - fl->def_len + sign)
		buf[i++] = '0';
	i += ft_strlcpy(buf + i, result, fl->def_len + 1);
	while (i < fl->min_w)
		buf[i++] = ' ';
	return (i);
}

static int	process_no_minus(t_flag *fl, char *result, char *buf, char sign)
{
	char	width_char;
	int		i;

	i = 0;
	width_char = fl->zero ? '0' : ' ';
	if (sign)
	{
		result++;
		fl->def_len--;
		sign = 1;
	}
	if (fl->zero)
		fl->prec = fl->min_w - sign;
	fl->prec = fl->prec > fl->def_len ? fl->prec : fl->def_len;
	fl->min_w = fl->min_w < fl->prec + sign ? fl->prec + sign : fl->min_w;
	while (i < fl->min_w - fl->prec - sign)
		buf[i++] = width_char;
	if (sign)
		buf[i++] = '-';
	while (i < fl->min_w - fl->def_len)
		buf[i++] = '0';
	i += ft_strlcpy(buf + i, result, fl->def_len + 1);
	return (i);
}

int			conversion_unsigned(unsigned int num, t_flag *fl, char spec)
{
	char	buf[MAX_SINGLE_CONV];
	char	result[DIGIT_CAPACITY + 1];
	char	*base;
	int		tot_print;

	if (fl->min_w > MAX_SINGLE_CONV || fl->prec > MAX_SINGLE_CONV)
		return (-1);
	if (!num && !fl->prec)
		return (print_spaces(fl->min_w));
	base = init_base(spec);
	ft_utoa_base(num, result, base);
	fl->def_len = ft_strlen(result);
	if (fl->minus)
		tot_print = process_minus(fl, result, buf, 0);
	else
		tot_print = process_no_minus(fl, result, buf, 0);
	return (write(1, buf, tot_print));
}

int			conversion_integer(int num, t_flag *fl)
{
	char	buf[MAX_SINGLE_CONV];
	char	result[DIGIT_CAPACITY + 1];
	int		tot_print;
	char	sign;

	if (fl->min_w > MAX_SINGLE_CONV || fl->prec > MAX_SINGLE_CONV)
		return (-1);
	if (!num && !fl->prec)
		return (print_spaces(fl->min_w));
	ft_itoa_base(num, result, DECIMAL_BASE);
	fl->def_len = ft_strlen(result);
	sign = num < 0 ? '-' : 0;
	if (fl->minus)
		tot_print = process_minus(fl, result, buf, sign);
	else
		tot_print = process_no_minus(fl, result, buf, sign);
	return (write(1, buf, tot_print));
}

int			conversion_pointer(unsigned long long adress, t_flag *fl)
{
	char	buf[MAX_SINGLE_CONV];
	char	result[DIGIT_CAPACITY + 1];
	char	tot_print;

	if (fl->min_w > MAX_SINGLE_CONV)
		return (-1);
	if (!adress)
		ft_strlcpy(result, "0x0", 4);
	else
		ft_ulltoa_base(adress, result, HEX_LOWER_BASE);
	fl->def_len = ft_strlen(result);
	if (fl->minus)
		tot_print = process_minus(fl, result, buf, 0);
	else
		tot_print = process_no_minus(fl, result, buf, 0);
	return (write(1, buf, tot_print));
}
