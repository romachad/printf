/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:38:11 by romachad          #+#    #+#             */
/*   Updated: 2022/09/01 01:15:09 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*read_value(char *str, size_t i, va_list ptr)
{
	char	*result;

	if (str[i] == 'c')
	{
		ft_putchar(va_arg(ptr, int));
		return (0);
	}
	else if (str[i] == 's')
		result = ft_strdup(va_arg(ptr, char *));
	else if (str[i] == 'p')
		result = hex_str(va_arg(ptr, size_t), 0);
	else if (str[i] == 'd' || str[i] == 'i')
		result = ft_itoa(va_arg(ptr, int));
	else if (str[i] == 'u')
		result = ft_utoa(va_arg(ptr, unsigned int));
	else if (str[i] == 'x')
		result = hex_str(va_arg(ptr, unsigned long int), 2);
	else if (str[i] == 'X')
		result = hex_str(va_arg(ptr, unsigned long int), 1);
	else
		result = ft_strdup("%");
	return (result);
}

static void	replace_value(char *str, size_t *i, va_list ptr, size_t p)
{
	char	*variable;

	variable = read_value(str, p + 1, ptr);
	if (variable && str[p + 1] != 'c')
	{
		ft_putstr(variable);
		*i = *i + ft_strlen(variable);
	}
	else if (!(variable) && str[p + 1] == 's')
	{
		ft_putstr("(null)");
		*i += 6;
	}
	else
		*i += 1;
	free(variable);
}

static char	*read_str(char *str, size_t *t, va_list ptr)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i]);
			*t += 1;
			i++;
		}
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			replace_value(str, t, ptr, i);
			i += 2;
		}
		else if (str[i] == '%')
		{
			ft_putchar(str[i]);
			*t += 1;
			i++;
		}
	}
	return (str);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	size_t	size;
	char	*str;
	size_t	*t;
	size_t	total;

	total = 0;
	t = &total;
	size = ft_strlen(s);
	if (size == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	va_start(ptr, s);
	str = read_str(str, t, ptr);
	va_end(ptr);
	free(str);
	return (total);
}
