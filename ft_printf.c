/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:52:03 by mazor             #+#    #+#             */
/*   Updated: 2020/07/08 16:34:38 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_car(t_carriage *car, char **ptr_format)
{
	car->printed = 0;
	car->start = *ptr_format;
	car->len = 0;
	car->va = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_carriage	car;

	if (!format)
		return (-1);
	init_carriage(&car, &format);
	while (*format)
	{
		if (*format++ == CHAR_PERCENT)
		{
			if (!car.va)
			{
				car.va++;
				va_start(args, format);
			}
			

			if ((car.spec = hand_spec(&format)) < 0)
				return (-1);
			car.printed += car.len + car.spec;
			write(1, car.start, car.len);
			car.start = format;
			car.len = 0;
			//TODO
		}
		car.len++;
	}
	return (car.printed);
}