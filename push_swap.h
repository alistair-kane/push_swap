/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/02/21 06:11:17 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_state
{
	int	run_start;
	int	run_end;
	int	len;
	int	a_moves;
	int	b_moves;
	int	val_holder;
	int	move_thresh;
	int	lowest_val;
}	t_state;

t_list	**list_builder(int argc, char **argv);

void	swap_a(t_list **head_a, int supress);
void	swap_b(t_list **head_b, int supress);
void	double_swap(t_list **head_a, t_list **head_b, int supress);
int		push_a(t_list **head_a, t_list **head_b, int supress);
int		push_b(t_list **head_a, t_list **head_b, int supress);
void	rotate_a(t_list **head_a, int supress);
void	rotate_b(t_list **head_b, int supress);
void	double_rotate(t_list **head_a, t_list **head_b, int supress);
void	reverse_rotate_a(t_list **head_a, int supress);
void	reverse_rotate_b(t_list **head_b, int supress);
void	double_reverse_rotate(t_list **head_a, t_list **head_b, int supress);

void	sort_three(t_list *stack_a);
void	sort_four(t_list *stack_a, t_list *stack_b);
void	sort_five(t_list *stack_a, t_list *stack_b);

void	indexer(t_list *stack_a);
int		get_nth(t_list *head, int index);
int		get_nth_idx(t_list *head, int index);
int		forward_shared(int a_rotate, int b_rotate);
int		reverse_shared(int a_reverse, int b_reverse);
int		min(int x, int y);
int		max_run(t_list **head, t_state *state);
void	insert_pos(int val, t_list **stack_a, t_list **stack_b, t_state *state);
void	delete_list(t_list *head_ref);

void	a_moves(int a_rotate, int a_reverse, t_list **stack_a);
void	b_moves(int b_rotate, int b_reverse, t_list **stack_b);
void	fwd_rotates(int a, int b, t_list **stack_a, t_list **stack_b);
void	rev_rotates(int a, int b, t_list **stack_a, t_list **stack_b);

int		get_lowest(t_list *stack_a);
void	move_lowest(int lowest, t_list **stack_a, t_list **stack_b);
void	find_lowest(int unshared, int forward, int reverse, t_state *state);
int		find_bin(int val, t_list **stack_b);

void	push_to_b(t_list **stack_a, t_list **stack_b, t_state *state);
int		push_to_a(t_list **stack_a, t_list **stack_b, t_state *state);
void	end_correction(t_list **stack_a, t_list **stack_b, t_state *state);

#endif