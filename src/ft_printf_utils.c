/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:35:31 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 16:41:49 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_base(char spec)
{
	if (spec == 'x')
		return (HEX_LOWER_BASE);
	if (spec == 'X')
		return (HEX_UPPER_BASE);
	return (DECIMAL_BASE);
}

int		print_spaces(int min_w)
{
	int	i;

	i = 0;
	while (i < min_w)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

void	flag_analysis(t_flag *flags)
{
	if (flags->min_w < 0)
		flags->minus = 1;
	if (flags->minus || flags->prec >= 0)
		flags->zero = 0;
}