/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:54:33 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/09 16:27:30 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd(t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd == PA)
		push(b, a);
	else if (cmd == PB)
		push(a, b);
	else if (cmd == RA)
		rotate(a, 0);
	else if (cmd == RB)
		rotate(b, 0);
	else if (cmd == RR)
		rotate_both(a, b, 0);
	else if (cmd == RRA)
		rev_rotate(a, 0);
	else if (cmd == RRB)
		rev_rotate(b, 0);
	else if (cmd == RRR)
		rotate_both(a, b, 1);
}

void	optimize_cmd(t_stack *a, t_stack *b, t_cmd prev, t_cmd curr)
{
	if (prev < 0 || curr == RB)
		return ;
	if (prev == RB && curr == RA)
		execute_cmd(a, b, RR);
	else if (prev == RB)
	{
		execute_cmd(a, b, RB);
		execute_cmd(a, b, curr);
	}
	else
		execute_cmd(a, b, curr);
}