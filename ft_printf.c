/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:38:11 by romachad          #+#    #+#             */
/*   Updated: 2022/08/07 00:36:27 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
static char	*read_value(char *str, size_t i, va_list ptr)
{
	char	c;
	char	*result;

	c = str[i];
	if (c == 'c')
		result = char_type(ptr);
	else if (c == 's')
	{
		result = ft_strdup(va_arg(ptr, char *));
		//result = string_type(ptr);
	}
	else if (c == 'p')
	{
		result = malloc(2 * sizeof(char));
		result[0] = '%';
		result[1] = 0;
	}
	else if (c == 'd' || c == 'i')
	{
		result = ft_itoa(va_arg(ptr, int));
	}
	else if (c == 'u')
	{
		result = ft_utoa(va_arg(ptr, unsigned int));
	}
	else if (c == 'x' || c == 'X' || c == '%')
	{
		result = malloc(2 * sizeof(char));
		result[0] = '%';
		result[1] = 0;
	}
	else
	{
		//printf("\nentrou em nada!\n");
		result = malloc (sizeof(char));
		result[0] = 0;
	}
	return (result);
}

static char	*replace_value(char *str, size_t *i, va_list ptr)
{
	char	*partial_str;
	char	*variable;
	size_t	swap;

	partial_str = ft_substr(str, 0, *i);
	//funcao de ler qual eh a var e devolver uma str com resultado da leitura
	variable = read_value(str, *i + 1, ptr); //colocar seguranca de alocacao?
	swap = ft_strlen(variable);
	partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	//variable vai receber o restantante do str a partir do %+1 encontrado:
	variable = ft_substr(str, *i + 2, ft_strlen(str) - (*i + 2));
	*i = ft_strlen(partial_str);
	//juntar o partial str com o variable
	partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	free(str);
	return (partial_str);
}

static char	*read_str(char *str, size_t *pos, va_list ptr)
{
	while (str[*pos])
	{
		while (str[*pos] && str[*pos] != '%')
			*pos += 1;
		if (str[*pos] == '%')
		{
			//printf("\nvalor do pos antes do replace: %zu\n", *pos);
			if (ft_strchr("cspdiuxX%", str[*pos + 1]))
				str = replace_value(str, pos, ptr);
			else
				*pos += 1;
			//printf("\nvalor do pos pos replace: %zu\n", *pos);
		}
	}
	return (str);
}

#include <stdio.h>
int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	size_t	size;
	char	*str;
	size_t	*pos;
	size_t	posicao;

	posicao = 0;
	pos = &posicao;
	size =  ft_strlen(s);
	if (size == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	va_start(ptr, s);
	str = read_str(str, pos, ptr);
	//ft_putstr(str);
	printf("%s", str);
	size = ft_strlen(str);
	va_end(ptr);
	free(str);
	return (size);
}
