/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 03:17:30 by romachad          #+#    #+#             */
/*   Updated: 2022/09/01 01:14:05 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned long int n, int flag)
{
	int	i;

	if (flag)
		n = (unsigned int) n;
	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*allocate_hex(int digits, int flag)
{
	char	*str;

	if (!flag)
		str = malloc((digits + 3) * sizeof(char));
	else
		str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (0);
	if (!flag)
	{
		str[0] = 0x30;
		str[1] = 'x';
		str[digits + 2] = 0;
	}
	else
		str[digits] = 0;
	return (str);
}

static char	*get_hexnumber(unsigned long int n, int flag)
{
	char	*number;
	int		digits;

	digits = size_hex(n, flag);
	if (!digits && flag)
		return (ft_strdup("0"));
	else if (!digits && !flag)
		return (ft_strdup("(nil)"));
	number = allocate_hex(digits, flag);
	if (!flag)
		digits += 1;
	else
		digits--;
	if (!number)
		return (0);
	while ((digits > 1 && (!flag)) || (digits > 0 && flag))
	{
		number[digits] = 0x30 + (n % 16);
		n = n / 16;
		digits--;
	}
	if (flag)
		number[0] = 0x30 + (n % 16);
	return (number);
}

static void	clean_hex(char *s, int flag)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= ':' && s[i] <= '?')
		{
			if (flag == 1)
				s[i] = s[i] + 7;
			else
				s[i] = s[i] + 39;
		}
		i++;
	}
}

char	*hex_str(unsigned long int n, int flag)
{
	char	*number;

	number = get_hexnumber(n, flag);
	clean_hex(number, flag);
	return (number);
}
