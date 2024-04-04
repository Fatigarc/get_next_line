/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:10:44 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/04 23:01:13 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void ft_free2(char **stash)
{
	free(stash);
	free(*stash);
	*stash = NULL;
}

char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned char)c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*create_stash(char **stash, int fd)
{
	char		*buf;
	ssize_t		char_read;
	
	char_read = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (/*char_read != 0 &&*/ !ft_strchr(*stash, NL))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			//printf("create stash -1 check \n");
			//ft_free(buf, &*stash);
			free(buf);
			free(*stash);
			return (NULL);
		}
		if (char_read == 0)
			break;
		buf[char_read] = '\0';
		*stash = ft_strjoin(*stash, buf);
		/*if (!stash)
		{
			free(buf);
			return (NULL);
		}*/
	}
	free(buf);
	return (*stash);
}

char	*extract_stash(char *stash)
{
	char	*buf;
	size_t	len_stash;
	int		i;
	int		k;

	if (!stash || !stash[0])
	{
		free(stash);
		return (NULL);
	}	
	k = 0;
	i = 0;
	len_stash = ft_strlen(stash);
	buf = (char *)malloc(sizeof(char) * (len_stash + 1));
	if (!buf)
		return (NULL);
	while (stash[i] && stash[i] != NL)
		buf[k++] = stash[i++];
	if (stash[i] == NL)
		buf[k++] = NL;
	buf[k] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line_readed;
	char		*line_created;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_readed, 0) < 0)
	{
		free(stash);
		return (NULL);
	}
	line_created = create_stash(&stash, fd);
	line_readed = extract_stash(line_created);		
	if (!line_readed || line_readed[0] == '\0')
	{
		if(read(fd, &line_readed, 0) == -1)
		{
			ft_free2(&stash);
			ft_free2(&line_created);	
		}
		free(line_readed);
		return (NULL);
	}
	//printf("222222\n");
	stash = move_buffer(line_created);
	return (line_readed);
}

#include <fcntl.h>
#include <stdio.h>

/*int main()
{
	//int fd = open("text.txt", O_RDONLY);
	int fd = 1;
	char    *ret;
	int		i = 0;

	if (fd < 0)
	{
		perror("error opening file");
		return (1);
	}
	 while (i < 7)
	{
		ret = get_next_line(fd);
		printf("FIN LINEA %s", ret);
		i++;
		free(ret);
	
	}
 	system("leaks -q a.out");
	close (fd);
	return (0);
}*/
