/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 06:00:38 by romachad          #+#    #+#             */
/*   Updated: 2022/07/31 00:55:33 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*new_str;
	int		size;
	int		i;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	new_str = malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = src[i];
	return (new_str);
}
