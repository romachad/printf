/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:38:11 by romachad          #+#    #+#             */
/*   Updated: 2022/08/10 03:26:26 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*read_value(char *str, size_t i, va_list ptr)
{
	//char	c;
	char	*result;

	//c = str[i];
	if (str[i] == 'c')
	{
		char_type(ptr);
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
	{
		result = ft_strdup("%");
		/*result = malloc(2 * sizeof(char));
		result[0] = '%';
		result[1] = 0;*/
	}
	return (result);
}

//static char	*replace_value(char *str, size_t *i, va_list ptr)
static void	replace_value(char *str, size_t *i, va_list ptr, size_t p)
{
	//char	*partial_str;
	char	*variable;

	//partial_str = ft_substr(str, 0, *i);
	variable = read_value(str, p + 1, ptr);
	if (variable && str[p + 1] != 'c')
	{
		//partial_str = ft_strjoin2(partial_str, variable);
		ft_putstr(variable);
		*i = *i + ft_strlen(variable);
		//free(variable);
	}
	else if (!(variable) && str[*i + 1] == 's')
	{
		//partial_str = ft_strjoin2(partial_str, "(null)");
		ft_putstr("(null)");
		*i += 6;
	}
	else
		*i += 1;
	//variable = ft_substr(str, *i + 2, ft_strlen(str) - (*i + 2));
	//*i = ft_strlen(partial_str);
	//partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	//free(str);
	//return (partial_str);
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
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
			{
				//str = replace_value(str, pos, ptr);
				replace_value(str, t, ptr, i);
				i += 2;
			}
			else
			{
				ft_putchar(str[i]);
				*t += 1;
				i++;
			}
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
	size =  ft_strlen(s);
	if (size == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	va_start(ptr, s);
	str = read_str(str, t, ptr);
	//size = ft_strlen(str);
	//place_null(str);
	//ft_putstr_n(str, size);
	va_end(ptr);
	free(str);
	//return (size);
	return (total);
}
