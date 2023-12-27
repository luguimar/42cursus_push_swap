/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fields.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/19 18:06:27 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_half(t_list **stack_a, t_list **stack_b)
{
	set_half_for_stack(stack_a);
	set_half_for_stack(stack_b);
}

void	set_price(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_node	*node;

	set_price_stack_a(stack_a);
	tmp = *stack_b;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		if (((t_node *)biggest(*stack_a)->content)->value < node->value
			&& ((t_node *)biggest(*stack_a)->content)->half == node->half)
		{
			if (node->half == 0)
				node->price = bigger(sort_organized_price(*stack_a),
						node->index) + 1;
			else
				node->price = bigger(sort_organized_price(*stack_a),
						node->inverted_index) + 1;
		}
		else
			set_price_extra(stack_a, node);
		tmp = tmp->next;
	}
}

void	set_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		((t_node *)tmp->content)->index = i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		((t_node *)tmp->content)->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_final_a_index(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_list	*smallest;

	i = 0;
	while (i < ft_lstsize(*stack_a))
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp == *stack_a)
			{
				while (((t_node *)tmp->content)->final_a_index != -1)
					tmp = tmp->next;
				smallest = tmp;
			}
			if (((t_node *)tmp->content)->value < ((t_node *)smallest->content)
				->value && \
				((t_node *)tmp->content)->final_a_index == -1)
				smallest = tmp;
			tmp = tmp->next;
		}
		((t_node *)smallest->content)->final_a_index = i;
		i++;
	}
}

void	set_init_node_values(t_node *node, char **args, int i)
{
	node->value = ft_atoi(args[i]);
	node->index = i;
	node->final_a_index = -1;
	node->price = -1;
	node->half = -1;
}
