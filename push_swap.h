/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/01/20 20:53:34 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

// long    ft_atoi(const char *nptr);
// t_list	*ft_lstnew(int content);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// int		ft_lstsize(t_list *lst);

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

#endif