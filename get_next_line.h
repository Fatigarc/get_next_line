/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:10:41 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/05 09:56:26 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef NL
#  define NL '\n'
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*create_stash(char **stash, int fd);
char	*extract_stash(char *stash);
char	*move_buffer(char *str);
char	*ft_strchr(char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_free(char *buf, char **static_c);

#endif
