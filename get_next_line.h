/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 02:19:39 by prukngan          #+#    #+#             */
/*   Updated: 2023/05/11 02:19:39 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

//#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
#endif

typedef struct s_head
{
	int				fd;
	struct s_list	*list;
	strcat s_head	next;
}	t_head;

typedef struct s_list
{
	char			*buffer;
	int				start;
	int				end;
	int				size;
	struct s_list	*next;
}	t_list;

void	*ft_memcpy(void *dest, void *src, size_t lens);
int		ft_memchr(void *buffer, int c, size_t len);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *arg);

char 		*get_next_line(int fd);
int			ft_get(int fd, t_list **head);
int			ft_next(t_list **list, int *len);
char		*ft_line(t_list **head, int len);
t_list		*ft_init(t_list **pt, int size);
void		ft_clear(t_list **node);

void		print_list(t_list *head);

// char	*ft_joinfree(char *temp, char *buffer);
// char	*ft_next(char *buff, int i);
// char	*ft_line(char *buff, int i);

// char	*ft_line(t_temp *node, int len);
// int		ft_get(int fd, t_temp *temp);
// void	ft_next(t_temp *node);

#endif