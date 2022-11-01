/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:32:19 by romachad          #+#    #+#             */
/*   Updated: 2022/08/10 04:00:11 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
void	ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*hex_str(unsigned long int n, int flag);
void	ft_putchar(char c);

#endif
