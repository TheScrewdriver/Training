/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:20:18 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/27 10:32:42 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"

void	*get_inst(const char *line)
{
	static t_graph	*graph = NULL;
	bool			(*is_inst[])(const char *) = {is_start_inst,
												  is_end_inst,
												  is_link_inst};
	int				(*inst[])(t_graph **, const char *) = {start, end, ft_link};
	int				i;

	i = 0;
	if (line != NULL)
	{
		while (i < NBOF_COM)
		{
			if (is_inst[i](line) == true)
			{
				inst[i](&graph, line);
				break ;
			}
			++i;
		}
	}
	return ((t_list *)graph);
}

void	*display(const char *line)
{
	if (line != NULL)
		ft_putendl(line);
	return (NULL);
}
