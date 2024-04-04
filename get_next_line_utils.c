/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:10:46 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/04 23:05:01 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char    *ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(ret, s1, len_s1 + len_s2 + 1);
	ft_strlcpy(ret + ft_strlen(s1), s2, len_s2 + 1);
	free(s1);
	return (ret);
}

char	*move_buffer(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (!str)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, str, ft_strlen(str) + 1);
	while (temp[i] && temp[i] != NL)
		temp[i++] = '\0';
	if (temp[i] == NL)
	{
		i++;
		j = 0;
		while (temp[i] != '\0')
			temp[j++] = temp[i++];
		temp[j] = '\0';
	}
	free (str);
	return (temp);
}

void	*ft_free(char *buf, char **static_c)
{
	free(buf);
	free(static_c);
	*static_c = NULL;
	return (NULL);
}
