/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:14:03 by prukngan          #+#    #+#             */
/*   Updated: 2023/07/20 20:14:03 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find_next(t_list *node, int *len)
{
	int		i;

	if (!node)
		return (0);
	i = 0;
	while (i < node->byte)
	{
		if (node->buffer[i] == '\n')
		{
			node->n = i + 1;
			(*len) += i + 1;
			return (1);
		}
		i++;
	}
	(*len) += i;
	node->n = i;
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t lens)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (dest);
	i = 0;
	while (i < lens)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

t_list	*ft_init_node(int size)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->buffer = (char *)malloc(size);
	if (!node->buffer)
	{
		free(node);
		return (NULL);
	}
	node->byte = size;
	node->n = 0;
	node->next = NULL;
	return (node);
}

t_head	*ft_init_head(int fd, t_head **head)
{
	t_head	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->list = NULL;
	new->fd = fd;
	new->len = 0;
	new->next = *head;
	*head = new;
	return (new);
}

t_list	*ft_free_node(t_list *node)
{
	t_list	*next;

	if (!node)
		return (NULL);
	next = node->next;
	free(node->buffer);
	free(node);
	return (next);
}
