/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:56 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/20 15:12:21 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H

# define UTILITIES_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# define EQUAL 0

///string.c

char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(const char *str1, const char *str2);
char	*ft_stradd(char **str1, const char *str2);
char	*ft_strchr(char *str, const char c);

///get_info.c

size_t	ft_strlen(const char *str);
bool	is_empty(const char *str, const size_t size);
bool	ft_strcmp(const char *str1, const char *str2);
int		ft_memcmp(const void *ptr1, const void *ptr2, const size_t size);

///remove.c

void	ft_bzero(void *array, const size_t size);
void	cut_str(char *str, const char c);

///display.c

void	ft_putstr(const char *str);
void	ft_putendl(const char *str);

#endif