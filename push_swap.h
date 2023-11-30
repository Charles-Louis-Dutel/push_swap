/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:02:51 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/30 15:55:19 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct pile_elem
{
	int					nbr;
	struct pile_elem	*next;
}	*t_pile;

/*Error management*/
int	check_args(int argc, char **argv);
long	ft_atoi_modif(const char *str);
/*Pile management*/
t_pile	new_pile(void);
int	is_pile_empty(t_pile);
t_pile	push_pile(t_pile pile, int nbr);
t_pile	clear_pile(t_pile pile);
void	print_pile(t_pile pile);

#endif
