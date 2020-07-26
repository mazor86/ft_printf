/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:52:40 by mazor             #+#    #+#             */
/*   Updated: 2020/07/25 17:56:41 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_flags(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->min_width = 0;
}

static void		parse_flags(t_carriage **ptr_car, t_flag *flags)
{
	t_carriage	*car;

	car = *ptr_car;
	while (ft_strchr("-+# 0", *(car->format_current)))
	{
		if (*(car->format_current) == '-')
			flags->minus = 1;
		if (*(car->format_current) == '0')
			flags->zero = 1;
		(car->format_current)++;
	}
}

static void		parse_min_width(t_carriage **ptr_car, va_list **ap, t_flag *flags)
{
	t_carriage *car;
	int			temp;

	car = *ptr_car;
	if (*(car->format_current) == '*')
	{
		(car->format_current)++;
		temp = va_arg(**ap, int);
		if (temp < 0)
			flags->minus = 1;
		if (!temp)
			flags->zero = 1;
		flags->min_width = (temp > 0) ? temp : -temp;
		return ;
	}
	flags->min_width = ft_atoi(*(car->format_current));
	while (ft_isdigit(*(car->format_current)))
		(car->format_current)++;
}

static void		parse_precision(t_carriage **ptr_car, va_list **ap, t_flag *flags)
{
	t_carriage *car;

	car = *ptr_car;
	(car->format_current)++;
	if (*(car->format_current) == '*')
	{
		(car->format_current)++;
		flags->precision = va_arg(**ap, int);
		return ;
	}
	flags->precision = ft_atoi(*(car->format_current));
	while (ft_isdigit(*(car->format_current)))
		(car->format_current)++;
}

int				parse(t_carriage *car, va_list *ap)
{
	t_flag	flags;

	(car->format_current)++;
	init_flags(&flags);
	parse_flags(&car, &flags);
	parse_min_width(&car, &ap, &flags);
	if (*(car->format_current) == '.')
		parse_precision(&car, &ap, &flags);
	if (ft_strchr("di", *(car->format_current)))
		return (conversion_integer(va_arg(*ap, int), &flags));
	if (ft_strchr("uxX", *(car->format_current)))
		return (conversion_unsigned(va_arg(*ap, unsigned int), &flags,\
										   *(car->format_current)));
	if (*(car->format_current) == 's')
		return (conversion_string(va_arg(*ap, char *), &flags));
	if (*(car->format_current) == 'c')
		return (conversion_char((unsigned char)va_arg(*ap, int), &flags));
	if (*(car->format_current) == 'p')
		return (conversion_pointer(va_arg(*ap,size_t), &flags));
	if (*(car->format_current) == '%')
		return (conversion_percent(&flags));
	else
		return (-1);
}