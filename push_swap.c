/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:53 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/08 16:27:59 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_pile	*set_pile(int argc, char **argv)
{
	t_pile	*temp;
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
			clear_pile(&temp);
			return (new_pile());
		}
		push_pile(&temp, nb);
		i--;
	}
	if (check_doublons(temp) == 1)
	{
		write(2, "Error\n", 6);
		clear_pile(&temp);
		return (new_pile());
	}
	return (temp);
}

static void	exec_command(t_pile **pile_a)
{
	t_pile	*pile_b;

	//pile_b = new_pile();

	/*swap*/
	//swap(pile_a);
	//swap(pile_b);

	/*push a to b == push b*/
	//push(pile_a, &pile_b);

	/*push b to a == push a*/
	//push(&pile_b, pile_a);

	/*rotate a*/
	rotate(pile_a);

	/*rotate b*/
	//pile_b = rotate(pile_b);

	/*reverse rotate a*/
	//pile_a = rev_rotate(pile_a);

	/*reverse rotate b*/
	//pile_b = rev_rotate(pile_b);

	// __builtin_printf("v\n");
	// print_pile(pile_a);
	// __builtin_printf("v\n");
	// print_pile(&pile_b);

	//clear_pile(&pile_b);
	//return (*pile_a);
}

// static t_pile	test(t_pile pile_a)
// {
// 	t_pile	pile_b;

// 	pile_b = new_pile();

// 	pile_a = swap(pile_a);

// 	pile_b = push(pile_a, pile_b);
// 	pile_a = pop_one(pile_a);

// 	pile_b = push(pile_a, pile_b);
// 	pile_a = pop_one(pile_a);

// 	pile_b = push(pile_a, pile_b);
// 	pile_a = pop_one(pile_a);

// 	pile_a = swap(pile_a);

// 	pile_a = push(pile_b, pile_a);
// 	pile_b = pop_one(pile_b);

// 	pile_a = push(pile_b, pile_a);
// 	pile_b = pop_one(pile_b);

// 	pile_a = push(pile_b, pile_a);
// 	pile_b = pop_one(pile_b);

// 	pile_b = clear_pile(pile_b);
// 	return (pile_a);
// }

int	main(int argc, char **argv)
{
	t_pile	*pile_a;

	if (argc > 1)
	{
		if (check_args(argc, argv) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		pile_a = new_pile();
		pile_a = set_pile(argc, argv);
		if (!pile_a)
			return (1);
		print_pile(&pile_a);
		exec_command(&pile_a);
		__builtin_printf("\n");
		print_pile(&pile_a);

		clear_pile(&pile_a);
	}
	return (0);
}
