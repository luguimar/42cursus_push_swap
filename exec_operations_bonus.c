/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:28:25 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/26 21:24:55 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exec_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		lwest_price_index;
	t_list	*tmp;
	t_node	*node;

	tmp = *stack_b;
	lwest_price_index = lowest_price_index(*stack_b);
	while (tmp)
	{
		node = (t_node *)tmp->content;
		if (node->index == lwest_price_index)
		{
			if (exec_cheapest_aux1(stack_a, stack_b, node))
				break ;
			else if (exec_cheapest_aux2(stack_a, stack_b, node))
				break ;
			else if (exec_cheapest_aux3(stack_a, stack_b, node))
				break ;
			else if (exec_cheapest_aux4(stack_a, stack_b, node))
				break ;
			else if (exec_cheapest_extra(stack_a, stack_b, node))
				break ;
		}
		tmp = tmp->next;
	}
}

int	exec_cheapest_extra(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (exec_cheapest_aux5(stack_a, stack_b, node))
		return (1);
	else if (exec_cheapest_aux6(stack_a, stack_b, node))
		return (1);
	else if (exec_cheapest_aux7(stack_a, stack_b, node))
		return (1);
	return (0);
}

void	operations_aux(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		wrong_args(*stack_a, *stack_b, line);
}

void	exec_operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		push(stack_a, stack_b);
	else
		operations_aux(stack_a, stack_b, line);
}
