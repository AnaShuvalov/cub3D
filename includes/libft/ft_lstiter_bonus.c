/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:41:19 by anshuval          #+#    #+#             */
/*   Updated: 2025/07/26 19:20:44 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_node;

	if (f == NULL || lst == NULL)
		return ;
	current_node = lst;
	while (current_node != NULL)
	{
		f(current_node -> content);
		current_node = current_node -> next;
	}
}
