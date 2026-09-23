/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_about_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:26:47 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 16:56:44 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	replace_with_spaces(char *line)
{
	int		i;
	int		len;

	if (line == NULL)
		return ;
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
	{
		len--;
		line[len] = '\0';
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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
