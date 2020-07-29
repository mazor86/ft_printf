/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:12:28 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 15:38:19 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		reverse(char *str)
{
	int				i;
	int				len;
	unsigned char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void			ft_itoa_base(int nb, char *result, char *base)
{
	unsigned	base_len;
	int			sign;
	int			i;
	long		number;

	i = 0;
	number = (long)nb;
	base_len = ft_strlen(base);
	sign = number < 0 ? -1 : 1;
	number *= sign;
	while (number)
	{
		result[i++] = base[number % base_len];
		number /= base_len;
	}
	if (sign < 0)
		result[i++] = '-';
	if (!i)
		result[i++] = '0';
	result[i] = '\0';
	reverse(result);
}

void			ft_utoa_base(unsigned int number, char *result, char *base)
{
	unsigned	base_len;
	int			i;

	i = 0;
	base_len = ft_strlen(base);
	while (number)
	{
		result[i++] = base[number % base_len];
		number /= base_len;
	}
	if (!i)
		result[i++] = '0';
	result[i] = '\0';
	reverse(result);
}

void			ft_ulltoa_base(unsigned long long number,\
								char *result, char *base)
{
	unsigned	base_len;
	int			i;

	i = 0;
	base_len = ft_strlen(base);
	while (number)
	{
		result[i++] = base[number % base_len];
		number /= base_len;
	}
	if (!i)
		result[i++] = '0';
	result[i++] = 'x';
	result[i++] = '0';
	result[i] = '\0';
	reverse(result);
}
