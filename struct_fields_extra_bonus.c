/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fields_extra_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:20:37 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 18:49:18 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	set_half_for_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if ((((t_node *)tmp->content)->index < ft_lstsize(*stack) / 2
				&& ft_lstsize(*stack) % 2 == 0)
			|| (((t_node *)tmp->content)->index <= ft_lstsize(*stack) / 2
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
	if (((t_node *)biggest(*stack_a)->content)->value < node->value
		&& ((t_node *)biggest(*stack_a)->content)->half != node->half)
	{
		if (node->half == 0)
			node->price = node->index + sort_organized_price(*stack_a) + 1;
		else
			node->price = node->inverted_index
				+ sort_organized_price(*stack_a) + 2;
	}
	else if (node->half == 0 && target_half(*stack_a,
			node->final_a_index) == 0)
		node->price = bigger(node->index, target_index(*stack_a,
					node->final_a_index)) + 1;
	else if (node->half == 1 && target_half(*stack_a,
			node->final_a_index) == 1)
		node->price = bigger(node->inverted_index, target_index(*stack_a,
					node->final_a_index)) + 2;
	else if (node->half == 0 && target_half(*stack_a,
			node->final_a_index) == 1)
		node->price = node->index + target_inverse_index(*stack_a,
				node->final_a_index) + 2;
	else if (node->half == 1 && target_half(*stack_a,
			node->final_a_index) == 0)
		node->price = node->inverted_index + target_index(*stack_a,
				node->final_a_index) + 2;
}
