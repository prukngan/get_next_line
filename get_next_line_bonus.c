/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:13:02 by prukngan          #+#    #+#             */
/*   Updated: 2023/07/20 20:13:02 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_head	*temp;
	t_head			*head;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	head = temp;
	if (!temp)
		head = ft_init_head(fd, &temp);
	else
	{
		while (head && head->fd != fd)
			head = head->next;
		if (!head)
			head = ft_init_head(fd, &temp);
	}
	if (!head->list)
		head->list = ft_init_node(0);
	head->len = ft_get(fd, head->list);
	line = ft_line(&head->list, head->len);
	ft_next(&head->list);
	return (line);
}

int	ft_get(int fd, t_list *node)
{
	int		byte;
	int		len;

	byte = BUFFER_SIZE;
	len = 0;
	while (!ft_find_next(node, &len) && byte == BUFFER_SIZE)
	{
		node->next = ft_init_node(BUFFER_SIZE);
		if (!node->next)
			break ;
		node = node->next;
		byte = read(fd, node->buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(node->buffer);
			free(node);
			break ;
		}
		node->byte = byte;
	}
	return (len);
}

char	*ft_line(t_list **temp, int len)
{
	t_list	*node;
	char	*line;
	int		i;

	node = *temp;
	if (!node || len <= 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (node)
	{
		ft_memcpy(&line[i], node->buffer, node->n);
		i += node->n;
		if (!node->next)
		{
			*temp = node;
			break ;
		}
		node = ft_free_node(node);
	}
	line[i] = '\0';
	return (line);
}

void	ft_next(t_list **list)
{
	t_list	*last;
	t_list	*new;
	int		size;

	last = *list;
	new = NULL;
	if (!last)
		return ;
	size = last->byte - last->n;
	if (size > 0)
	{
		new = ft_init_node(size);
		if (!new)
			return ;
		ft_memcpy(new->buffer, &last->buffer[last->n], size);
	}
	while (last)
		last = ft_free_node(last);
	*list = new;
}
