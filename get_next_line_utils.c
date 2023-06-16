/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 02:19:12 by prukngan          #+#    #+#             */
/*   Updated: 2023/05/11 02:19:12 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, void *src, size_t lens)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (dest);
	while (i < lens)
	{	
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s, %d\n", head->buffer, head->size);
		head = head->next;
		printf("----------\n");
	}
}