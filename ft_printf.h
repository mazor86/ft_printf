/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:44:12 by mazor             #+#    #+#             */
/*   Updated: 2020/07/08 16:29:54 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define CHAR_PERCENT '%'

typedef struct	s_carriage
{
	char		*start;
	int			len;
	int			spec;
	int			printed;
	int			va;
}				t_carriage;

int		ft_printf(const char *, ...);

#endif