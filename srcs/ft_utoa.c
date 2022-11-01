/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:12:31 by romachad          #+#    #+#             */
/*   Updated: 2022/08/07 01:08:06 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	size_n(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*allocate(unsigned int digits)
{
	char	*str;

	str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (0);
	str[digits] = 0;
	return (str);
}

static char	*get_number(unsigned int n)
{
	char	*number;
	int		digits;

	digits = size_n(n);
	number = allocate(digits);
	digits--;
	if (!number)
		return (0);
	while (digits > 0)
	{
		number[digits] = 0x30 + (n % 10);
		n = n / 10;
		digits--;
	}
	number[0] = 0x30 + (n % 10);
	return (number);
}

char	*ft_utoa(unsigned int n)
{
	char	*number;

	if (n == 0)
	{
		number = malloc(2 * sizeof(char));
		if (number)
		{
			number[0] = 0x30;
			number[1] = 0;
			return (number);
		}
		else
			return (0);
	}
	else
		return (get_number(n));
}
