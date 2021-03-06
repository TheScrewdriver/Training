/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:15:21 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 18:12:17 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	destroy(void *node, void destroy_fct())
{
	destroy_fct(node);
}

void	cut(t_list **head, void (*destroy_fct)())
{
	if (*head != NULL)
	{
		if ((*head)->next != NULL)
			cut(&(*head)->next, destroy_fct);
		else
			destroy_node(head, destroy_fct);
	}
}

void	destroy_node(t_list **node, void (*destroy_fct)())
{
	if (destroy_fct != NULL)
		destroy(&(*node)->data, destroy_fct);
	destroy(node, full_free);
}

void	destroy_list(t_list **head, void destroy_fct())
{
	if (*head != NULL)
	{
		destroy_list(&(*head)->next, destroy_fct);
		destroy_node(head, destroy_fct);
	}
}

void	destroy_list_rec(t_list **head)
{
	if (*head != NULL)
		destroy_list(head, NULL);
}
