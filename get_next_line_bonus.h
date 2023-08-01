/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:14:29 by prukngan          #+#    #+#             */
/*   Updated: 2023/07/20 20:14:29 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	char			*buffer;
	int				byte;
	int				n;
	struct s_list	*next;
}				t_list;

int		ft_find_next(t_list *node, int *len);
void	*ft_memcpy(void *dest, const void *src, size_t lens);
t_list	*ft_init_node(int size);
t_list	*ft_free_node(t_list *node);

char	*get_next_line(int fd);
int		ft_get(int fd, t_list *node);
void	ft_next(t_list **list);
char	*ft_line(t_list **temp, int len);

#endif