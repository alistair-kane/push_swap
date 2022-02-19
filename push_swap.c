/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/02/19 23:40:59 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <unistd.h>

int	count_dup(t_list *head_ref)
{
	int		count;
	t_list	*ptr;

	count = 0;
	while (head_ref -> next != NULL)
	{
		ptr = head_ref -> next;
		while (ptr != NULL)
		{
			if (head_ref -> content == ptr -> content)
			{
				count++;
				break ;
			}
			ptr = ptr -> next;
		}
		head_ref = head_ref -> next;
	}
	return (count);
}

t_list	**list_builder(int argc, char **argv)
{
	t_list	**stack_a;
	int		i;
	long	val;

	stack_a = malloc(sizeof(t_list));
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		if (val >= 2147483648 || val < -2147483648)
			return (NULL);
		else
		{
			if (i++ == 1)
				*stack_a = ft_lstnew(val);
			else
			{
				ft_lstadd_back(stack_a, ft_lstnew(val));
				if (count_dup(*stack_a))
					return (NULL);
			}
		}
	}
	return (stack_a);
}

int	return_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

t_list	*print_gne(t_list *node, int *holder)
{
	t_list	*empty;

	empty = malloc(sizeof(t_list));
	empty->index = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return (empty);
	}
	else
		*holder = node->index;
	free(empty);
	return (node);
}

void	print_ll(t_list *head_a, t_list *head_b)
{
	t_list	*new_node_a;
	t_list	*new_node_b;
	int		a_holder;
	int		b_holder;

	new_node_a = head_a;
	new_node_b = head_b;
	a_holder = 0;
	b_holder = 0;
	while (new_node_a != NULL || new_node_b != NULL)
	{
		new_node_a = print_gne(new_node_a, &a_holder);
		new_node_b = print_gne(new_node_b, &b_holder);
		printf("| %i \t\t %i |\n", a_holder, b_holder);
		new_node_a = new_node_a->next;
		new_node_b = new_node_b->next;
	}
}

void	delete_list(t_list *head_ref)
{
	if (head_ref == NULL)
		return ;
	delete_list(head_ref -> next);
	free(head_ref);
}

void	swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	bubble_sort(t_list *start)
{
	int		swapped;
	t_list	*ptr1;
	t_list	*lptr;

	ptr1 = NULL;
	lptr = NULL;
	if (start == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr)
		{
			if (ptr1->content > ptr1->next->content)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

static	t_list	*copy(t_list *head)
{
	t_list	*current;
	t_list	*new_list;
	t_list	*tail;

	current = head;
	new_list = NULL;
	while (current != NULL)
	{
		if (new_list == NULL)
		{
			new_list = ft_lstnew(current->content);
			new_list->index = current->index;
			tail = new_list;
		}
		else
		{
			tail->next = (t_list *)malloc(sizeof(t_list));
			tail = tail->next;
			tail->index = current->index;
			tail->content = current->content;
			tail->next = NULL;
		}
		current = current->next;
	}
	return (new_list);
}

int	get_nth(t_list *head, int index)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current->content);
		count++;
		current = current->next;
	}
	return (-1);
}

int	forward_shared(int a_rotate, int b_rotate)
{
	int	i;

	i = 0;
	while (a_rotate && b_rotate)
	{
		a_rotate--;
		b_rotate--;
		i++;
	}
	if (a_rotate > 0)
	{
		while (a_rotate--)
			i++;
	}
	if (b_rotate > 0)
	{
		while (b_rotate--)
			i++;
	}
	return (i);
}

int	reverse_shared(int a_reverse, int b_reverse)
{
	int	i;

	i = 0;
	while (a_reverse && b_reverse)
	{
		a_reverse--;
		b_reverse--;
		i++;
	}
	if (a_reverse > 0)
	{
		while (a_reverse--)
			i++;
	}
	if (b_reverse > 0)
	{
		while (b_reverse--)
			i++;
	}
	return (i);
}

int	get_nth_idx(t_list *head, int index)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current->index);
		count++;
		current = current->next;
	}
	return (-1);
}

int	min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int	max_of(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}

void	indexer(t_list *stack_a)
{
	t_list	*sorted;
	int		i;

	sorted = copy(stack_a);
	bubble_sort(sorted);
	while (stack_a != NULL)
	{
		i = 1;
		while (i < ft_lstsize(sorted))
		{
			if (stack_a->content == get_nth(sorted, i))
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
	free(sorted);
}

int	reset_temp(int temp_len, int i, t_state *state)
{
	if (state->len < temp_len)
	{
		state->len = temp_len;
		state->run_start = i - (state->len - 1);
		state->run_end = i;
	}
	temp_len = 1;
	return (temp_len);
}

void	count_consec(t_list **head, t_state *state, int len)
{
	int	i;
	int	j;
	int	k;
	int	temp_len;

	i = -1;
	j = 0;
	k = 1;
	temp_len = 1;
	state->len = 1;
	while (++i < (len * 2))
	{
		if (get_nth_idx(*head, j++) < get_nth_idx(*head, k++))
			temp_len++;
		else
			temp_len = reset_temp(temp_len, i, state);
		if (k == len)
			k = 0;
		if (j == len)
			j = 0;
	}
}

int	max_run(t_list **head, t_state *state)
{
	int	len;

	len = ft_lstsize(*head);
	count_consec(head, state, len);
	if (state->run_end >= len)
		state->run_end = state->run_end - len;
	if (state->run_start >= len)
		state->run_start = state->run_start - len;
	return (state->len);
}

int	slot_in_run(int val, t_list **stack_a, t_state *state)
{
	int	fits;
	int	i;

	fits = 0;
	i = state->run_start;
	while (fits != 2)
	{
		fits = 0;
		if (val > get_nth_idx(*stack_a, i))
			fits++;
		if (i == ft_lstsize(*stack_a))
			i = -1;
		if (val < get_nth_idx(*stack_a, i + 1))
			fits++;
		i++;
	}
	return (i);
}

void	insert_pos(int val, t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	moves;
	int	i;

	max_run(stack_a, state);
	if (val < get_nth_idx(*stack_a, state->run_start))
		moves = state->run_start;
	else if (val > get_nth_idx(*stack_a, state->run_end))
		moves = state->run_end;
	else
		moves = slot_in_run(val, stack_a, state);
	state->a_moves = moves;
	i = 0;
	while (get_nth_idx(*stack_b, i) != val)
		i++;
	state->b_moves = i;
}

int	max_idx(int len, t_list **head)
{
	int	i;
	int	max_val;
	int	max_idx;

	i = 0;
	max_val = 0;
	while (i < len)
	{
		if (get_nth_idx(*head, i) > max_val)
		{
			max_val = get_nth_idx(*head, i);
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	find_bin(int val, t_list **stack_b)
{
	int	len;
	int	i;
	int	j;

	len = ft_lstsize(*stack_b);
	if (len == 0 || len == 1)
		return (0);
	i = max_idx(len, stack_b);
	j = 0;
	while (j < len)
	{
		if (val > get_nth_idx(*stack_b, i))
			return (i);
		j++;
		i++;
		if (i == len)
			i = 0;
	}
	return (max_idx(len, stack_b));
}

void	a_moves(int a_rotate, int a_reverse, t_list **stack_a)
{
	if (a_reverse < a_rotate)
	{	
		while (a_reverse--)
			reverse_rotate_a(stack_a, 0);
	}
	else
	{
		while (a_rotate--)
			rotate_a(stack_a, 0);
	}
}

void	b_moves(int b_rotate, int b_reverse, t_list **stack_b)
{
	if (b_reverse < b_rotate)
	{	
		while (b_reverse--)
			reverse_rotate_b(stack_b, 0);
	}
	else
	{
		while (b_rotate--)
			rotate_b(stack_b, 0);
	}
}

void	fwd_rotates(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a && b)
	{
		a--;
		b--;
		double_rotate(stack_a, stack_b);
	}
	while (a--)
		rotate_a(stack_a, 0);
	while (b--)
		rotate_b(stack_b, 0);
	push_b(stack_a, stack_b);
}

void	rev_rotates(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a && b)
	{
		a--;
		b--;
		double_reverse_rotate(stack_a, stack_b);
	}
	while (a--)
		reverse_rotate_a(stack_a, 0);
	while (b--)
		reverse_rotate_b(stack_b, 0);
	push_b(stack_a, stack_b);
}

void	move_lowest(int lowest, t_list **stack_a, t_list **stack_b)
{
	int	a_rotate;
	int	a_reverse;
	int	b_rotate;
	int	b_reverse;
	int	unshared;

	a_rotate = 0;
	while (lowest != get_nth_idx(*stack_a, a_rotate))
		a_rotate++;
	b_rotate = find_bin(lowest, stack_b);
	a_reverse = ft_lstsize(*stack_a) - a_rotate;
	b_reverse = ft_lstsize(*stack_b) - b_rotate;
	unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
	if (unshared < forward_shared(a_rotate, b_rotate) && unshared
		< reverse_shared(a_reverse, b_reverse))
	{
		a_moves(a_rotate, a_reverse, stack_a);
		b_moves(b_rotate, b_reverse, stack_b);
		push_b(stack_a, stack_b);
	}
	else if (forward_shared(a_rotate, b_rotate)
		< reverse_shared(a_reverse, b_reverse))
		fwd_rotates(a_rotate, b_rotate, stack_a, stack_b);
	else
		rev_rotates(a_reverse, b_reverse, stack_a, stack_b);
}

void	find_lowest(int unshared, int forward, int reverse, t_state *state)
{
	if (unshared <= min(forward, reverse) && unshared < state->move_thresh)
	{
		state->move_thresh = unshared;
		state->lowest_val = state->val_holder;
	}
	else if (forward < reverse && forward < state->move_thresh)
	{
		state->move_thresh = forward;
		state->lowest_val = state->val_holder;
	}
	else if (reverse < state->move_thresh)
	{
		state->move_thresh = reverse;
		state->lowest_val = state->val_holder;
	}
}

static void	set_state(t_state *state)
{
	state->move_thresh = 1000;
	state->lowest_val = -1;
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	i;
	int	limit;
	int	unshared;

	i = -1;
	limit = ft_lstsize(*stack_a);
	if (state->run_end < state->run_start)
	{
		i = state->run_end - 1;
		limit = state->run_start;
	}
	set_state(state);
	while (++i < limit)
	{
		state->val_holder = get_nth_idx(*stack_a, i);
		unshared = min(i, ft_lstsize(*stack_a) - i) \
			+ min(find_bin(state->val_holder, stack_b), ft_lstsize(*stack_b) \
			- find_bin(state->val_holder, stack_b));
		if (!(i >= state->run_start && i <= state->run_end))
			find_lowest(unshared, \
				forward_shared(i, find_bin(state->val_holder, stack_b)), \
				reverse_shared(ft_lstsize(*stack_a) - i, ft_lstsize(*stack_b) \
				- find_bin(state->val_holder, stack_b)), state);
	}
	move_lowest(state->lowest_val, stack_a, stack_b);
}

int	push_to_a(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	lowest_val;
	int	val;
	int	unshared;
	int	i;

	i = 0;
	lowest_val = -1;
	while (get_nth_idx(*stack_b, i) != -1)
	{
		val = get_nth_idx(*stack_b, i);
		insert_pos(val, stack_a, stack_b, state);
		unshared = min(state->a_moves, ft_lstsize(*stack_a) - state->a_moves) \
			+ min(state->b_moves, ft_lstsize(*stack_b) - state->b_moves);
		if (unshared < 1 || forward_shared(state->a_moves, state->b_moves) < 1 \
			|| reverse_shared(ft_lstsize(*stack_a) - state->a_moves, \
			ft_lstsize(*stack_b) - state->b_moves) < 1)
			lowest_val = val;
		i++;
	}
	if (lowest_val != -1)
	{
		push_a(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	end_correction(t_list **stack_a, t_list **stack_b, t_state *state)
{
	insert_pos(-1, stack_a, stack_b, state);
	while (get_nth_idx(*stack_a, 0) != 0)
	{
		if ((ft_lstsize(*stack_a) - state->a_moves) > state->a_moves)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
}

void	solver(t_list **stack_a, t_list **stack_b)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	while ((max_run(stack_a, state) < ft_lstsize(*stack_a)) \
		|| ft_lstsize(*stack_b))
	{
		if (ft_lstsize(*stack_b) && push_to_a(stack_a, stack_b, state))
			continue ;
		if ((ft_lstsize(*stack_a) == max_run(stack_a, state) \
			&& ft_lstsize(*stack_b)) || state->run_start == 0)
			reverse_rotate_a(stack_a, 0);
		else if (state->run_end < state->len)
		{
			if (state->run_end > (ft_lstsize(*stack_a) - state->run_start))
				reverse_rotate_a(stack_a, 0);
			else
				rotate_a(stack_a, 0);
		}
		else if (ft_lstsize(*stack_a) > 2)
			push_to_b(stack_a, stack_b, state);
	}
	end_correction(stack_a, stack_b, state);
	free(state);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	stack_b = malloc(sizeof(t_list));
	indexer(*stack_a);
	solver(stack_a, stack_b);
	// printf("----------\"solved\":---------\n");
	// print_ll(*stack_a, *stack_b);
	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
