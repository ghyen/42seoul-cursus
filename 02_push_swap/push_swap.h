/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:05:38 by jiyunlee          #+#    #+#             */
/*   Updated: 2023/02/05 19:04:59 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	int				idx;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	char			name;
	int				len;
	struct s_list	*top;
}	t_stack;

char	**split_space(char const *s);
char	**free_arr(char **arr);
void	stack_init(t_stack *a, t_stack *b, char **argv);
int		is_sorted(t_stack *stack);
t_list	*lstnew(int val);
void	lstadd_back(t_stack *stack, t_list *new);
void	free_list(t_stack *stack);
void	check_error(t_stack *stack, char *arg_str, long long arg_int);
void	error_exit(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

#endif
