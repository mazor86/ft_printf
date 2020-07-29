/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:48:38 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 10:15:12 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversion_percent(t_flag *fl)
{
	int		tot_print;
	char	buf[MAX_SINGLE_CONV];
	int		i;

	if (fl->min_w > MAX_SINGLE_CONV)
		return (-1);
	fl->def_len = 1;
	tot_print = fl->min_w > fl->def_len ? fl->min_w : fl->def_len;
	i = 0;
	if (fl->minus)
		buf[i++] = '%';
	while (i < fl->min_w - fl->def_len)
		buf[i++] = ' ';
	if (!fl->minus)
		buf[i] = '%';
	return (write(1, buf, tot_print));
}

int		conversion_char(unsigned char c, t_flag *fl)
{
	int		tot_print;
	char	buf[MAX_SINGLE_CONV];
	int		i;

	if (fl->min_w > MAX_SINGLE_CONV)
		return (-1);
	fl->def_len = 1;
	tot_print = fl->min_w > fl->def_len ? fl->min_w : fl->def_len;
	i = 0;
	if (fl->minus)
		buf[i++] = c;
	while (i < fl->min_w - fl->def_len)
		buf[i++] = ' ';
	if (!fl->minus)
		buf[i] = c;
	return (write(1, buf, tot_print));
}

int		conversion_string(char *str, t_flag *fl)
{
	int		i;
	char	buf[MAX_SINGLE_CONV];

	if (!str)
		str = "(null)";
	i = 0;
	fl->def_len = ft_strlen(str);
	fl->def_len = fl->def_len < fl->prec ? fl->def_len : fl->prec;
	if (fl->minus)
	{
		ft_strlcpy(buf + i, str, fl->def_len + 1);
		i += fl->def_len;
		fl->def_len = 0;
	}
	while (i < fl->min_w - fl->def_len)
		buf[i++] = ' ';
	if (!fl->minus)
	{
		ft_strlcpy(buf + i, str, fl->def_len + 1);
		i += fl->def_len;
	}
	return (write(1, buf, i));
}
