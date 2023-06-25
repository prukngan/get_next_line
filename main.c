/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:36:32 by prukngan          #+#    #+#             */
/*   Updated: 2023/06/04 03:36:32 by prukngan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	char	*line;

	int	fd = open("files/nl", O_RDWR);
	printf("line = %s\n", get_next_line(fd));
	printf("line = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}