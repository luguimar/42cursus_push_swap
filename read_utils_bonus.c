/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:10:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 19:14:18 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_line(t_list **a, t_list **b, char *line)
{
	line = get_next_line(0);
	while (line)
	{
		exec_operation(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}
