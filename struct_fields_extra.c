/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fields_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:20:37 by luguimar          #+#    #+#             */
/*   Updated: 2024/01/03 19:41:02 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_half_for_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if ((((t_node *)tmp->content)->index < ft_lstsize(*stack) / 2
				&& ft_lstsize(*stack) % 2 == 0)
			|| (((t_node *)tmp->content)->index < ft_lstsize(*stack) / 2 + 1
				&& ft_lstsize(*stack) % 2 != 0))
			((t_node *)tmp->content)->half = 0;
		else
			((t_node *)tmp->content)->half = 1;
		tmp = tmp->next;
	}
}

void	set_price_stack_a(t_list **stack_a)
{
	t_list	*tmp;
	t_node	*node;

	tmp = *stack_a;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		node->price = -1;
		tmp = tmp->next;
	}
}

void	set_price_extra(t_list **stack_a, t_node *node)
{
	node->price = smaller(node->index + target_inverse_index(*stack_a, \
			node->final_a_index) + 2, smaller(node->inverted_index \
			+ target_index(*stack_a, node->final_a_index) + 2, \
			smaller(bigger(node->index, target_index(*stack_a, \
			node->final_a_index)) + 1, bigger(node->inverted_index \
			+ 1, target_inverse_index(*stack_a, node->final_a_index) \
			+ 1) + 1)));
}
