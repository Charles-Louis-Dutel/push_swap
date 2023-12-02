/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:21:14 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/01 14:39:49 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	get_last(t_pile pile)
{
	t_pile	temp;

	temp = pile;
	if (!temp)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

int	pile_len(t_pile pile)
{
	t_pile	temp;
	int		i;

	temp = pile;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
