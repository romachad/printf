/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:21:12 by romachad          #+#    #+#             */
/*   Updated: 2022/08/06 07:41:54 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_type(va_list ptr)
{
	char	*str;

	str = malloc(1 + sizeof(char));
	if (!str)
		return ("");
	str[0] = va_arg(ptr, int);
	str[1] = 0;
	return (str);
}
