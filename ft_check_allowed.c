/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_allowed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:19:02 by romachad          #+#    #+#             */
/*   Updated: 2022/07/31 04:31:31 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_allowed(const char *s, int t_pct)
{
	int		i;
	char	*p;
	char	c;

	i = 0;
	p = ft_strchr(s, '%');
	while (i < t_pct)
	{
		c = p[1];
		if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
			p += 2;
		else if (c == 'u' || c == 'x' || c == 'X' || c == '%')
			p += 2;
		else
			return (-1);
		if (c == '%')
			t_pct--;
		p = ft_strchr(p, '%');
		i++;
	}
	return (i);
}
