/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/01/27 00:21:45 by alistair         ###   ########.fr       */
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
	t_list	*temp;
	t_list	**order;
	int		i_right;
	int		i_end;
	int		active;
}	t_state;

#endif