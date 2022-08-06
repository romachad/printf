/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:21:54 by romachad          #+#    #+#             */
/*   Updated: 2022/08/03 02:23:48 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin2(char *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joined = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!joined)
		return (0);
	i = 0;
	while (i < (size_s1 + size_s2 + 1))
	{
		if (i < size_s1)
			joined[i] = s1[i];
		else
			joined[i] = s2[i - size_s1];
		i++;
	}
	free (s1);
	return (joined);
}
