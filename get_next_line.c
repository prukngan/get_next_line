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
	{
		*node = NULL;
		return (NULL);
	}
	new->buffer = malloc(byte);
	if (!new->buffer)
	{
		free(new);
		*node = NULL;
		return (NULL);
	}
	new->start = 0;
	new->end = 0;
	new->size = byte;
	new->next = NULL;
	*node = new;
	return (new);
}

void	ft_clear(t_list **node)
{
	if (!*node)
		return ;
	free((*node)->buffer);
	free(*node);
	*node = NULL;
}

char	*ft_line(t_list **head, int len)
{
	t_list	*before;
	t_list	*node;
	char	*line;
	int		i;

	if (len <= 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	node = *head;
	i = 0;
	while (node)
	{
		before = node;
		ft_memcpy(&line[i], &node->buffer[node->start], node->end - node->start + 1);
		i += node->end - node->start + 1;
		if (i == len)
			break ;
		node = node->next;
		ft_clear(&before);
	}
	line[i] = '\0';
	*head = node;
	return (line);
}

int	ft_next(t_list **list, int *len)
{
	t_list	*node;
	t_list	*before;
	int		i;

	node = *list;
	// printf("%p\n", node);
	if (!node->size)
		return (1);
	while (node->end < node->size && node->buffer[node->end] != '\n')
		node->end++;
	*len += node->end;
	if (node->end == node->size)
		return (1);
	(*len)++;
	return (0);
}

int	ft_get(int fd, t_list **head)
{
	t_list	*node;
	int		len;

	node = *head;
	len = 0;
	while (ft_next(&node, &len))
	{
		node = ft_init(&node->next, BUFFER_SIZE);
		if (!node)
			break ;
		node->size = read(fd, node->buffer, BUFFER_SIZE);
		// printf("%d\n", (*node)->size);
		if (node->size <= 0)
		{
			ft_clear(&node);
			break ;
		}
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*line;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	len = 0;
	if (!head)
		head = ft_init(&head, 0);
	//printf("%d\n", len);
	if (!head)
		return (NULL);
	len = ft_get(fd, &head);
	if (len == 0)
		return (NULL);
	// printf("%p, ", head);
	// print_list(head);
	line = ft_line(&head, len);
	// printf("%p\n", head);
	return (line);
	// return ("-------end-------");
}