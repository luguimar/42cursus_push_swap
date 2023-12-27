/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:59:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 14:16:11 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
/*
void	swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = lstdup((*stack)->next);
		ft_lstdelone(stack, (*stack)->next, free);
		ft_lstadd_front(stack, tmp);
	}
}

void	push(t_list **stack_orig, t_list **stack_dest)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_orig) > 0)
	{
		tmp = lstdup(*stack_orig);
		ft_lstdelone(stack_orig, (*stack_orig), free);
		ft_lstadd_front(stack_dest, tmp);
	}
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = lstdup(*stack);
		*stack = (*stack)->next;
		ft_lstdelone(stack, (*stack)->prev, free);
		ft_lstadd_back(stack, tmp);
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = lstdup(ft_lstlast(*stack));
		ft_lstdelone(stack, ft_lstlast(*stack), free);
		ft_lstadd_front(stack, tmp);
	}
}*/

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		tmp->prev = *stack;
		(*stack)->prev = NULL;
		tmp->next->prev = tmp;
	}
}

void	push(t_list **stack_orig, t_list **stack_dest)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_orig) > 0)
	{
		tmp = *stack_orig;
		*stack_orig = (*stack_orig)->next;
		if (*stack_orig)
			(*stack_orig)->prev = NULL;
		if (*stack_dest)
		{
			(*stack_dest)->prev = tmp;
			tmp->next = *stack_dest;
		}
		else
			tmp->next = NULL;
		tmp->prev = NULL;
		*stack_dest = tmp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = ft_lstlast(*stack);
		ft_lstlast(*stack)->next = tmp;
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = ft_lstlast(*stack);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}
