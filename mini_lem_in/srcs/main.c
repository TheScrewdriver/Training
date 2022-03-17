/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:49:58 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/17 10:01:46 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(void)
{
	int		fd;
	int		instruction;
	char	*line;

	fd = open(PATH_FILE, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		instruction = inst(line);
		if (instruction == EXIT_FAILURE)
		{
			display_error(instruction);
			return (EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
