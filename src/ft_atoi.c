/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:02:13 by mazor             #+#    #+#             */
/*   Updated: 2020/07/25 22:09:36 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		digit;
	int		i;

	num = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		sign = (*nptr++ == '+' ? 1 : -1);
	i = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		digit = nptr[i++] - '0';
		num = num * 10 + digit;
	}
	return (sign * num);
}
