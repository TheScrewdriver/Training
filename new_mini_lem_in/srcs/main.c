/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:55:55 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 11:33:35 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

int	main(int ac, char **av)
{
	char	*path_file;
	t_graph	*graph;

	if (ac > 1)
	{
		path_file = av[1];
		read_file(path_file, display);
		ft_putstr("\n");

		graph = read_file(path_file, get_inst);
		display_graph(&graph);
		destroy_graph(&graph);
	}
	return (EXIT_SUCCESS);
}
