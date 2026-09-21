/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:17:03 by anshuval          #+#    #+#             */
/*   Updated: 2025/07/26 19:19:12 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		counter;

	counter = 0;
	current_node = lst;
	while (current_node != NULL)
	{
		counter++;
		current_node = current_node -> next;
	}
	return (counter);
}
