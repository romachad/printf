/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:32:19 by romachad          #+#    #+#             */
/*   Updated: 2022/08/03 02:33:37 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
void	ft_putstr(char *s);
int	ft_count_char(const char *s, char c);
int	check_allowed(const char *s, int t_pct);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr_n(const char *s, int c, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
