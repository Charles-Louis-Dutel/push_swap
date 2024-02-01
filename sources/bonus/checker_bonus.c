/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:26:44 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/01 17:46:32 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	exec_instruction(t_pile **pile_a, t_pile **pile_b, const char *ins)
{
	if (ft_strncmp(ins, "sa\n", 4) == 0)
		swap_bonus(pile_a);
	else if (ft_strncmp(ins, "sb\n", 4) == 0)
		swap_bonus(pile_b);
	else if (ft_strncmp(ins, "pa\n", 4) == 0)
		push_bonus(pile_b, pile_a);
	else if (ft_strncmp(ins, "pb\n", 4) == 0)
		push_bonus(pile_a, pile_b);
	else if (ft_strncmp(ins, "ra\n", 4) == 0)
		rotate_bonus(pile_a);
	else if (ft_strncmp(ins, "rb\n", 4) == 0)
		rotate_bonus(pile_b);
	else if (ft_strncmp(ins, "rr\n", 4) == 0)
		rotate_all(pile_a, pile_b, ins);
	else if (ft_strncmp(ins, "rra\n", 5) == 0)
		rev_rotate_bonus(pile_a);
	else if (ft_strncmp(ins, "rrb\n", 5) == 0)
		rev_rotate_bonus(pile_b);
	else if (ft_strncmp(ins, "rrr\n", 5) == 0)
		rotate_all(pile_a, pile_b, ins);
	else
		return (1);
	return (0);
}

static void	get_instructions(t_pile **pile_a, t_pile **pile_b)
{
	int		error;
	int		len;
	char	*ins;

	error = 0;
	len = pile_len(pile_a);
	while (1)
	{
		ins = get_next_line(0);
		if (ins == NULL)
			break ;
		if (exec_instruction(pile_a, pile_b, ins) == 1)
			error = 1;
		free(ins);
	}
	if (error == 1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (is_pile_sorted(pile_a) == 0 && pile_len(pile_a) == len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static int	case_one_arg(const char *argv)
{
	char	**args;
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		i;

	args = ft_split(argv, ' ');
	i = 0;
	while (args[i])
		i++;
	if (check_args(i, args, 0) == 1)
	{
		ft_le_xav(args);
		write(2, "Error\n", 6);
		return (1);
	}
	pile_a = new_pile();
	pile_a = set_pile_2(i, args);
	ft_le_xav(args);
	if (!pile_a)
		return (1);
	pile_b = new_pile();
	get_instructions(&pile_a, &pile_b);
	clear_pile(&pile_a);
	clear_pile(&pile_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 2)
		return (case_one_arg(argv[1]));
	else if (argc > 2)
	{
		if (check_args(argc, argv, 1) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		pile_a = new_pile();
		pile_a = set_pile(argc, argv);
		if (!pile_a)
			return (1);
		pile_b = new_pile();
		get_instructions(&pile_a, &pile_b);
		clear_pile(&pile_a);
		clear_pile(&pile_b);
	}
	return (0);
}
