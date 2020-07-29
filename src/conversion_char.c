/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:48:38 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 17:43:17 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversion_percent(t_flag *fl)
{
	return (conversion_char('%', fl));
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
	{
		buf[i++] = c;
		fl->def_len = 0;
	}
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

	str = !str ? "(null)" : str;
	i = 0;
	fl->def_len = ft_strlen(str);
	if (fl->def_len > MAX_SINGLE_CONV || fl->min_w > MAX_SINGLE_CONV)
		return (-1);
	fl->prec = fl->prec < 0 ? fl->def_len : fl->prec;
	fl->prec = fl->def_len < fl->prec ? fl->def_len : fl->prec;
	fl->def_len = fl->def_len > fl->prec ? fl->prec : fl->def_len;
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
