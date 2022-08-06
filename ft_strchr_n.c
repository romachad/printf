/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:21:27 by romachad          #+#    #+#             */
/*   Updated: 2022/07/31 05:02:22 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strchr_n(const char *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c && n == 0)
			return ((char *) &s[i]);
		else if (s[i] == (char) c && n != 0)
			n--;
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	else
		return (0);
}
