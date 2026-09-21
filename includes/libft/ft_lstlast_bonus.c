/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:37:04 by anshuval          #+#    #+#             */
/*   Updated: 2025/07/25 21:18:17 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = lst;
	while (current_node != NULL)
	{
		next_node = current_node -> next;
		if (next_node == NULL)
			return (current_node);
		current_node = current_node -> next;
	}
	return (current_node);
}
