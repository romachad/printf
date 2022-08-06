/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:38:11 by romachad          #+#    #+#             */
/*   Updated: 2022/08/03 04:41:00 by romachad         ###   ########.fr       */
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

static char	*replace_value(char *str, size_t i)
{
	char	*partial_str;
	char	*variable;

	partial_str = ft_substr(str, 0, i);
	//funcao de ler qual eh a var e devolver uma str com resultado da leitura
	variable = read_value(str, i+1); //colocar seguranca de alocacao?
	partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	//variable vai receber o restantante do str a partir do %+1 encontrado:
	variable = ft_substr(str, i+2, ft_strlen(str) - (i + 2));
	//printf("\n\nTHIS IS THE VARIABLE BEFORE THE JOIN: %s",variable);
	//juntar o partial str com o variable
	partial_str = ft_strjoin2(partial_str, variable);
	free(variable);
	free(str);
	return (partial_str);
}

static char	*read_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p')
				str = replace_value(str, i);
			else if (str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u')
				str = replace_value(str, i);
			else if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%')
				str = replace_value(str, i);
		}
		if (str[i] == '%')
			i++;
	}
	return (str);
}

#include <stdio.h>
int	ft_printf(const char *s)
{
	size_t	size;
	char	*str;
	/*char	*p;
	int	t_pct;*/

	size =  ft_strlen(s);
	if (size == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	/*t_pct = 0;
	t_pct = ft_count_char(str, '%');
	t_pct = check_allowed(str, t_pct);
	if (t_pct == -1)
	{
		free(str);
		ft_putstr("Invalid qtd of pct signs!");
		return (-1);
	}
	//printf("total de %d sinais de pct!\n", t_pct);
	size = 0;
	while (t_pct)
	{
		p = strchr(str, '%', size);
		str = replace_value(str, p);
		size++;
		t_pct--;
	}*/
	str = read_str(str);
	//ft_putstr(str);
	printf("%s", str);
	size = ft_strlen(str);
	free(str);
	return (size);
}
