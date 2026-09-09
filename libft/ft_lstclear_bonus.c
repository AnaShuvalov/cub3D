/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:58:46 by anshuval          #+#    #+#             */
/*   Updated: 2025/07/27 16:00:01 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_node;
	t_list	*next_node;

	if (del == NULL || lst == NULL || *lst == NULL)
		return ;
	current_node = *lst;
	while (current_node != NULL)
	{
		next_node = current_node -> next;
		del(current_node -> content);
		free (current_node);
		current_node = next_node;
	}
	*lst = NULL;
}
