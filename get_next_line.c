/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 02:19:17 by prukngan          #+#    #+#             */
/*   Updated: 2023/05/11 02:19:17 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_init(t_list **node, int byte)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->buffer = malloc(byte);
	if (!new->buffer)
	{
		free(new);
		return (NULL);
	}
	new->size = byte;
	*node = new;
	return (new);
}

void	ft_clear(t_list **node)
{
	free((*node)->buffer);
	free(*node);
	*node = NULL;
}

int	ft_next(t_list **head, t_list *node)
{
	char	*next;
	int		i;

	if (!head)
		return (0);
	while (i < node->size && node->buffer[i] != '\n')
		i++;
	if (i < node->size - 1)
	{
		head = 
	}
}

t_list	*ft_get(int fd, t_list **head)
{
	char	*buffer;
	t_list	*node;
	int		i;

	i = 0;
	node = *head;
	while (node->size < BUFFER_SIZE && ft_next(head, node))
	{
		node = ft_init(&(node->next), BUFFER_SIZE);
		if (!node)
			return (NULL);
		node->size = read(fd, node->buffer, BUFFER_SIZE);
		if (node->size <= 0)
		{
			ft_clear(&node);
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*list;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (!head)
		head = ft_init(&head, 0);
	ft_get(fd, &head);
}