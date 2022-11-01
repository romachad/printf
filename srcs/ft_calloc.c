/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:32:19 by romachad          #+#    #+#             */
/*   Updated: 2022/08/03 02:33:12 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	mem_size;
	size_t	i;
	char	*replace;

	if (nmemb == 0 || size == 0)
		return (0);
	mem_size = nmemb * size;
	if (mem_size / nmemb != size)
		return (0);
	mem = malloc(mem_size);
	if (!mem)
		return (0);
	replace = (char *) mem;
	i = 0;
	while (i < mem_size)
	{
		replace[i] = 0;
		i++;
	}
	return (mem);
}
