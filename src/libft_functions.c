/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:10:31 by mazor             #+#    #+#             */
/*   Updated: 2020/07/29 09:24:51 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		digit;
	int		i;

	num = 0;
	sign = 1;
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

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;

	if (src && dst)
	{
		dst_len = (size - 1);
		src_len = ft_strlen(src);
		if (size)
		{
			while (*src && dst_len--)
			{
				*dst++ = *src++;
			}
			*dst = '\0';
		}
		return ((src_len));
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (!c)
		return ((char*)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}
