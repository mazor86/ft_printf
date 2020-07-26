/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:52:03 by mazor             #+#    #+#             */
/*   Updated: 2020/07/24 18:45:48 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_carriage(t_carriage *car, char **ptr_format)
{
	car->tot_print = 0;
	car->str_start = *ptr_format;
	car->format_current = car->str_start;
	car->va_on = 0;
}

static ssize_t 	print_clean(t_carriage *car)
{
	int	part_len;

	part_len = (int)(car->format_current - car->str_start);
	car->tot_print += part_len;
	return write(1, car->str_start, part_len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_carriage	car;

	if (!format)
		return (-1);
	init_carriage(&car, &format);
	while (*(car.format_current))
	{
		if (*(car.format_current) == '%')
		{
			if (print_clean(&car) < 0)
				return (-1);
			if (!car.va_on++)
				va_start(ap, format);
			if ((car.spec_len = parse(&car, &ap)) < 0)
				return (-1);
			car.tot_print += car.spec_len;
			car.str_start = car.format_current--;
		}
		car.format_current++;
	}
	if (print_clean(&car) < 0)
		return (-1);
	if (car.va_on)
		va_end(ap);
	return (car.tot_print);
}