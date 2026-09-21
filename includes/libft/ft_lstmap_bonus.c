/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:22:21 by anshuval          #+#    #+#             */
/*   Updated: 2025/07/27 16:35:40 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_node;
	t_list	*new_node;
	t_list	*new_list;
	void	*new_content;

	if (del == NULL || f == NULL || lst == NULL)
		return (NULL);
	new_list = NULL;
	current_node = lst;
	while (current_node != NULL)
	{
		new_content = f(current_node -> content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current_node = current_node -> next;
	}
	return (new_list);
}
