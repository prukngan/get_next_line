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
	int	fd = open("files/41_with_nl", O_RDWR);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}