/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:21:12 by romachad          #+#    #+#             */
/*   Updated: 2022/08/08 05:00:29 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_type(va_list ptr)
{
	char	*str;

	str = malloc(1 + sizeof(char));
	if (!str)
		return (0);
	str[0] = va_arg(ptr, int);
	if(str[0] == 0)
		str[0] = 127;
	str[1] = 0;
	return (str);
}

void	place_null(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 127)
			s[i] = 0;
		i++;
	}
}
