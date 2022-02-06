/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/02/06 02:54:27 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

void	swap_a(t_list **head_a, int double_flag);
void	swap_b(t_list **head_b, int double_flag);
void	double_swap(t_list **head_a, t_list **head_b);
void	push_a(t_list **head_a, t_list **head_b);
void	push_b(t_list **head_a, t_list **head_b);

void	rotate_a(t_list **head_a, int double_flag);
void	rotate_b(t_list **head_b, int double_flag);
void	double_rotate(t_list **head_a, t_list **head_b);

void	reverse_rotate_a(t_list **head_a, int double_flag);
void	reverse_rotate_b(t_list **head_b, int double_flag);
void	double_reverse_rotate(t_list **head_a, t_list **head_b);

typedef struct s_state
{
	int	run_start;
	int	run_end;
	int	len;
	int	reverse;
	int	a_moves;
	int	b_moves;
}	t_state;

#endif