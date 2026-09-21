/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:06:51 by anshuval          #+#    #+#             */
/*   Updated: 2025/08/03 15:13:23 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;
	t_list	*next_node;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current_node = *lst;
	while (current_node != NULL)
	{
		next_node = current_node -> next;
		if (next_node == NULL)
		{
			current_node -> next = new;
			return ;
		}
		else
			current_node = current_node -> next;
	}
}
