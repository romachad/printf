/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:38:11 by romachad          #+#    #+#             */
/*   Updated: 2022/08/06 06:51:47 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
static char	*read_value(char *str, size_t i)
{
	char	c;
	char	*result;

	c = str[i];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
	{
		result = malloc(2 * sizeof(char));
		result[0] = '%';
		result[1] = 0;
	}
	else if (c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		result = malloc(2 * sizeof(char));
		result[0] = '%';
		result[1] = 0;
	}
	else
	{
		result = malloc (sizeof(char));
		result[0] = 0;
	}
	return (result);
}

static char	*replace_value(char *str, size_t *i)
{
	char	*partial_str;
	char	*variable;
	size_t	swap;

	partial_str = ft_substr(str, 0, *i);
	//funcao de ler qual eh a var e devolver uma str com resultado da leitura
	variable = read_value(str, *i+1); //colocar seguranca de alocacao?
	swap = ft_strlen(variable);
	partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	//variable vai receber o restantante do str a partir do %+1 encontrado:
	variable = ft_substr(str, *i+2, ft_strlen(str) - (*i + 2));
	*i = ft_strlen(partial_str);
	//juntar o partial str com o variable
	partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	free(str);
	return (partial_str);
}

static char	*read_str(char *str, size_t *pos)
{
	while (str[*pos])
	{
		while (str[*pos] && str[*pos] != '%')
			*pos += 1;
		if (str[*pos] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[*pos + 1]))
				str = replace_value(str, pos);
			/*if (str[*pos + 1] == 'c' || str[*pos + 1] == 's' || str[*pos + 1] == 'p')
				str = replace_value(str, pos);
			else if (str[*pos + 1] == 'd' || str[*pos + 1] == 'i' || str[*pos + 1] == 'u')
				str = replace_value(str, pos);
			else if (str[*pos + 1] == 'x' || str[*pos + 1] == 'X' || str[*pos + 1] == '%')
				str = replace_value(str, pos);*/
		}
	}
	return (str);
}

#include <stdio.h>
int	ft_printf(const char *s, ...)
{
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
	str = read_str(str, pos);
	//ft_putstr(str);
	printf("%s", str);
	size = ft_strlen(str);
	free(str);
	return (size);
}
