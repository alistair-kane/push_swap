/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:46:12 by alistair          #+#    #+#             */
/*   Updated: 2022/02/02 11:46:30 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(2, "Error\n", 6);
	return (0);
}

t_list	*print_gne(t_list *node, int *holder)
{
	t_list	*empty;

	empty = malloc(sizeof(t_list));
	empty->content = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return (empty);
	}
	else
		*holder = node->content;
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

int	apply_instructions(char *command, t_list **stack_a, t_list **stack_b)
{
	static	int	counter = 0;
	if (!ft_strncmp("pb\n", command, 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", command, 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp("sa\n", command, 3))
		swap_a(stack_a, 0);
	else if (!ft_strncmp("sb\n", command, 3))
		swap_b(stack_b, 0);
	else if (!ft_strncmp("ss\n", command, 3))
		double_swap(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", command, 3))
		rotate_a(stack_a, 0);
	else if (!ft_strncmp("rb\n", command, 3))
		rotate_b(stack_a, 0);
	else if (!ft_strncmp("rr\n", command, 3))
		double_rotate(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", command, 4))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strncmp("rrb\n", command, 4))
		reverse_rotate_b(stack_b, 0);
	else if (!ft_strncmp("rrr\n", command, 4))
		double_reverse_rotate(stack_a, stack_b);

	else if (!ft_strncmp(" \n", command, 2))
		return (0);

	else
		return (-1);
	printf("---------- %.2s ----------\n", command);
	printf("Counter: %d\n", counter++);
	print_ll(*stack_a, *stack_b);
	return (0);
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
	return(-1);
}

int	min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

t_list	*reverse_list(t_list **head)
{
	t_list *prev;
	t_list *current;
	t_list *next;
	
	prev = NULL;
	current = *head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return(prev);
}

void	max_run(t_list **head)
{
	int		i;
	int 	run_start;
	int		run_end;
	t_list	*temp;

	temp = head;
	i = 0;
	run_len = 0;
	temp_run = 0;
	while (temp->next != NULL)
	{	
		while (((temp->content) < (temp->next->content))
		{
			run_start = i;
			temp_run++;
			if (run_len < temp_run)
			{
				run_len = temp_run;
				state->run_start = run_start;
				state->run_end = i;
			}
			else
				temp_run = 0;
		last_val  = temp->content;
		temp = temp->next;
		i++;
		// reset back to start to loop
		if (temp == NULL)
			temp = head;
	}
}

// static void move_maker(int target, t_list **stack_a)
// {

// }

static void	move_vals(t_list **stack_b, t_list **stack_a, t_state *state)
{
	t_list *order;
	t_list *holder_pointer;
	int i;
	char *ins_b;
	char *ins_a;
	//lets just reverse at the start
	if (state->active == 0)
		order = *(state->order);
	else
		order = reverse_list(*&(state->order));
	printf("Len: %d Starting width: %d\n", state->a_len, state->width);
	i = 0;
	if (state->width == 2 && state->a_len > 3)
	{
		while (i++ <= (state->a_len / 2))
			push_b(stack_a, stack_b);
	}

		
	// now need to split up the order into the same chunks for operations?
	

	while (order != NULL)
	{
		if ((state->width < state->a_len) && state->a_len > 3)
			printf("order?: %d\n", order->content);
		order = order->next;

	// 	if (state->active == 0)
	// 	{
	// 		// looking to match the values here,
	// 		// need to find the difference between them to know what move to do.
	// 		while ((*stack_a)->content != order->content)
	// 			rotate_a(stack_a, 0);
			
	// 		// move_maker(order->content, stack_a);
			
	// 		order = order->next;
	// 		push_b(stack_a, stack_b);
	// 	}
	// 	else
	// 	{
	// 		while ((*stack_b)->content != order->content)
	// 			rotate_b(stack_b, 0);
	// 		order = order->next;
	// 		push_a(stack_a, stack_b);
	// 	}
	}
}

static	t_list *copy(t_list *head)
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
			tail = new_list;
		}
		else
		{
			tail->next = (t_list *)malloc(sizeof(t_list));
			tail = tail->next;
			tail->content = current->content;
			tail->next = NULL;
		}
		current = current->next;
	}
	return (new_list);
}


void	sortver(t_list **stack_a, t_list **stack_b)
{
	t_state	*state;

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
	// printf("---------ENTRY STACK:-----------\n");
	// print_ll(*stack_a, *stack_b);

	// char	*instruction;
	// while (1)
	// {
	
	sortver(stack_a, stack_b);

	// instruction = get_next_line(0);
	// if (instruction == NULL)
	// 	break ;
	// if(apply_instructions(instruction, stack_a, stack_b))
	// 	return(return_error());
	// }
	printf("\n---------- done ----------\n");
	print_ll(*stack_a, *stack_b);
	
	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
// 537980 for 500 with no basic optimization.

// here is my 1st solver, 90945 moves for 500 numbers wow
// int	solver(t_list **stack_a, t_list **stack_b)
// {
// 	int	lst_a_size;
// 	int	max_r;
// 	int	moves;
	
// 	moves = 0;
// 	lst_a_size = ft_lstsize(*stack_a);
// 	max_r = max_run(*stack_a);
// 	if (max_r == lst_a_size)
// 		return(moves); 
// 	while (max_run(*stack_a) < ft_lstsize(*stack_a) && ft_lstsize(*stack_a) > 1)
// 	{
// 		// printf("---------- Status ----------\n");
// 		// print_ll(*stack_a, *stack_b);
// 		if ((*stack_a)->content == ft_lstsize(*stack_b))
// 		{
// 			push_b(stack_a, stack_b);
// 		}
// 		else if ((*stack_a)->content > (*stack_a)->next->content)
// 		{
// 			swap_a(stack_a, 0);
// 		}
// 		else
// 			reverse_rotate_a(stack_a, 0);
// 		moves++;
// 	}

// void	sortver(t_list **stack_a, t_list **stack_b)
// {
// 	int	a_len;
// 	int	width;
// 	int	i;
	
// 	a_len = ft_lstsize(*stack_a);
// 	width = 1;
// 	while (width < a_len)
// 	{
// 		i = 0;
// 		while (i < a_len)
// 		{
// 			if (ft_lstsize(*stack_a) > 1)
// 				merge(stack_a, i, width, stack_b);
// 			// after 1st merge stacks have shifted, now need to go from b to a
// 			else
// 				i = i + 2 * width;
// 		}
// 		width = 2 * width;
// 		i = 0;
// 		while (i <= a_len)
// 		{
// 			// reverse_rotate_b(stack_b, 0);
// 			push_a(stack_a, stack_b);
// 			i++;
// 		}
// 		// printf("---------- a-push ----------\n\n");
// 		// print_ll(*stack_a, *stack_b);
// 	}
// }

// static void	merge(t_list **stack_a, int width, t_list **stack_b)
// {
// 	int i;
// 	int j;
// 	int	k;
// 	int i_left;
// 	int i_right;
	
// 	t_list *temp;
// 	temp = copy(*stack_a);
	
// 	i = 0;
// 	j = width;
// 	k = 0;
	
// 	int len = ft_lstsize(*stack_a);
// 	i_left = width;
// 	i_right = 2 * width;
	
	
// 	if (i_left > len)
// 		i_left = len;
// 	if (i_right > len)
// 		i_right = len;

// 	while (k < len)
// 	{
// 		if (k > 0 && k % 2 != 0 && width < 2)
// 			push_b(stack_a, stack_b);
// 		else if (i < i_right && (j >= len || get_nth(*stack_a, 0) < get_nth(*stack_a, )))
// 		{
// 			move_b_idx(stack_b, stack_a, 0);
// 			i++;
// 		}
// 		else
// 		{
// 			move_b_idx(stack_b, stack_a, (j-i) );
// 			j++;
// 		}
// 		k++;
// 	}
	
// 	printf("---------- moves ----------\n\n");
// 	print_ll(*stack_a, *stack_b);
// 	// "active/focus" stack switches 
// }

// static void	sort_three(t_list **stack_a, t_list **stack_b)
// {
// 	int	len;

// 	len = ft_lstsize(*stack_a);
// 	if (len == 1)
// 		push_b(stack_a, stack_b);
// 	else if (len == 2)
// 	{
// 		if (get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			swap_a(stack_a, 0);
// 		push_b(stack_a, stack_b);
// 		push_b(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		if ((get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) > get_nth(*stack_a, 2))
// 			&& (get_nth(*stack_a, 1) > get_nth(*stack_a, 2)))
// 		{
// 			rotate_a(stack_a, 0);
// 			swap_a(stack_a, 0);
// 		}	
// 		else if ((get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) > get_nth(*stack_a, 2))
// 			&& (get_nth(*stack_a, 1) < get_nth(*stack_a, 2)))
// 			rotate_a(stack_a, 0);
// 		else if ((get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) < get_nth(*stack_a, 2)))
// 			swap_a(stack_a, 0);
// 		else if ((get_nth(*stack_a, 0) < get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) > get_nth(*stack_a, 2)))
// 			reverse_rotate_a(stack_a, 0);
// 		else if ((get_nth(*stack_a, 0) < get_nth(*stack_a, 2))
// 			&& (get_nth(*stack_a, 1) > get_nth(*stack_a, 2)))
// 		{
// 			rotate_a(stack_a, 0);
// 			swap_a(stack_a, 0);
// 			reverse_rotate_a(stack_a, 0);
// 		}
// 	}
// }

// static int	comparison(t_list *temp, int i, int j, int active)
// {

// 	if (!active)
// 	{
// 		if (get_nth(temp, i) > get_nth(temp, j))
// 			return (1);
// 	}
// 	else
// 	{
// 		if (get_nth(temp, i) < get_nth(temp, j))
// 			return (1);
// 	}
// 	return (0);
// }

// static void	merge(t_list *temp, int i_left, int i_right, int i_end)

// gcc -Wall -Werror -Wextra -g list_instructions_1.c list_instructions_2.c list_instructions_3.c checker.c libft/libft.a -o checker

// static void	sort_three(t_list **stack_a, t_list **stack_b)
// {
// 	int	len;

// 	len = ft_lstsize(*stack_a);
// 	if (len == 1)
// 	{
// 		push_b(stack_a, stack_b);
// 		return ;
// 	}
// 	else if (len == 2)
// 	{
// 		if (get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			swap_a(stack_a, 0);
// 		push_b(stack_a, stack_b);
// 		push_b(stack_a, stack_b);
// 		return ;
// 	}
// 	else
// 	{
// 		if ((get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) > get_nth(*stack_a, 2))
// 			&& (get_nth(*stack_a, 1) < get_nth(*stack_a, 2)))
// 			rotate_a(stack_a, 0);
// 		else if ((get_nth(*stack_a, 0) > get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) < get_nth(*stack_a, 2)))
// 			swap_a(stack_a, 0);
// 		else if ((get_nth(*stack_a, 0) < get_nth(*stack_a, 1))
// 			&& (get_nth(*stack_a, 0) > get_nth(*stack_a, 2)))
// 			reverse_rotate_a(stack_a, 0);
// 		else if ((get_nth(*stack_a, 0) < get_nth(*stack_a, 2))
// 			&& (get_nth(*stack_a, 1) > get_nth(*stack_a, 2)))
// 		{
// 			rotate_a(stack_a, 0);
// 			swap_a(stack_a, 0);
// 			reverse_rotate_a(stack_a, 0);
// 		}
// 		sort_three(stack_a, stack_b);
// 	}
// }

// static t_list *reverse_single(t_list *head)
// {
// 	t_list *prev;
// 	t_list *current;
// 	t_list *temp;
	
// 	prev = NULL;
// 	current = head;
// 	while (current)
// 	{
// 		temp = current->next;
// 		current->next = prev;
// 		prev = current;
// 		current = temp;
// 	}
// 	return(prev);
// }

// int	max_val(t_list *head)
// {
// 	int max = 0;
  
// 	while (head != NULL)
// 	{
// 		if (max < head->content)
// 			max = head->content;
// 		head = head->next;
// 	}
// 	return (max);
// }

