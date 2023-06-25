/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2023/06/24 12:32:38 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_ARR_SIZE 3000

# include "libft/libft.h"
# include <unistd.h>
// !!!!!!!!!!
# include <stdio.h>

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
	// int	array_a_len;
	// int	array_b_len;
}	t_state;

int	list_builder(int *stack_a, int argc, char **argv);

void	swap_a(int *head_a, int supress);
void	swap_b(int *head_b, int supress);
void	double_swap(int *head_a, int *head_b, int supress);
int		push_a(int *head_a, int *head_b, int supress);
int		push_b(int *head_a, int *head_b, int supress);
void	rotate_a(int *head_a, int supress);
void	rotate_b(int *head_b, int supress);
void	double_rotate(int *head_a, int *head_b, int supress);
void	reverse_rotate_a(int *head_a, int supress);
void	reverse_rotate_b(int *head_b, int supress);
void	double_reverse_rotate(int *head_a, int *head_b, int supress);

void	sort_three(int *stack_a);
void	sort_four(int *stack_a, int *stack_b);
void	sort_five(int *stack_a, int *stack_b);

void	indexer(int *stack_a);
// int		get_nth(int head, int index);
// int		get_nth_idx(int head, int index);
int		forward_shared(int a_rotate, int b_rotate);
int		reverse_shared(int a_reverse, int b_reverse);
int		min(int x, int y);
int		max_run(int *head, t_state *state);
void	insert_pos(int val, int *stack_a, t_state *state);
// void	delete_list(int *head_ref);

void	a_moves(int a_rotate, int a_reverse, int *stack_a);
void	b_moves(int b_rotate, int b_reverse, int *stack_b);
void	fwd_rotates(int a, int b, int *stack_a, int *stack_b);
void	rev_rotates(int a, int b, int *stack_a, int *stack_b);

int		get_lowest(int *stack_a);
void	move_lowest(int lowest, int *stack_a, int *stack_b);
void	find_lowest(int unshared, int forward, int reverse, t_state *state);
int		find_bin(int val, int *stack_b);

void	push_to_b(int *stack_a, int *stack_b, t_state *state);
int		push_to_a(int *stack_a, int *stack_b, t_state *state);
void	end_correction(int *stack_a, t_state *state);
int		lstsize(int *stack);

#endif