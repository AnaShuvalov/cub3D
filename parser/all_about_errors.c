/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_about_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:26:47 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/28 15:42:42 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_message(char *s)
{
	write (2, "Error\n", 6);
	if (s)
		ft_putstr_fd(s, 2);
}

void	ft_error(char *s)
{
	error_message(s);
	exit(1);
}
