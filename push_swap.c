/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:53 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/03 19:22:08 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_pile	set_pile(int argc, char **argv)
{
	t_pile	temp;
	int		i;
	long	nb;

	temp = new_pile();
	i = argc - 1;
	while (i > 0)
	{
		nb = ft_atoi_modif(argv[i]);
		if (nb == 11111111111)
		{
			write(2, "Error\n", 6);
			temp = clear_pile(temp);
			return (temp);
		}
		temp = push_pile(temp, nb);
		i--;
	}
	if (check_doublons(temp) == 1)
	{
		write(2, "Error\n", 6);
		temp = clear_pile(temp);
		return (temp);
	}
	return (temp);
}

static t_pile	exec_command(t_pile pile_a)
{
	t_pile	pile_b;

	pile_b = new_pile();
	/*swap*/
	//pile_a = swap(pile_a);
	//pile_b = swap(pile_b)

	/*push a to b*/
	//pile_b = push(pile_a, pile_b);
	//pile_a = pop_one(pile_a);

	/*push b to a*/
	//pile_a = push(pile_b, pile_a);
	//pile_b = pop_one(pile_b);

	/*rotate a*/
	//pile_a = rotate(pile_a);

	/*rotate b*/
	//pile_b = rotate(pile_b);

	/*reverse rotate a*/
	pile_a = rev_rotate(pile_a);
	__builtin_printf("\n");
	print_pile(pile_a);
	/*__builtin_printf("\n");
	print_pile(pile_b);

	clear_pile(pile_b);*/
	return (pile_a);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;

	if (argc > 1)
	{
		if (check_args(argc, argv) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		pile_a = set_pile(argc, argv);
		if (!pile_a)
			return (1);
		print_pile(pile_a);
		pile_a = exec_command(pile_a);
		//__builtin_printf("\n");
		//print_pile(pile_a);

		pile_a = clear_pile(pile_a);
	}
	return (0);
}
