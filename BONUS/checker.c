/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:33:01 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/27 14:33:04 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

static int	str_cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	instructions(char *line, t_stack *stack)
{
	static char	*instruc_str[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", \
		"rr", "rra", "rrb", "rrr"};
	static void	(*instruc_func[11])(t_stack *) = {sa, sb, ss, pa, pb, ra, rb, \
		rr, rra, rrb, rrr};
	int			i;

	i = -1;
	while (++i < 11)
		if (!str_cmp(line, instruc_str[i]))
			return (instruc_func[i](stack));
	error_(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	*line;

	if (ac == 1)
		return (0);
	stack = parsing(--ac, ++av);
	if (!stack)
		return (1);
	stack->print = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		instructions(line, stack);
		free(line);
	}
	if (is_sort(stack, 1))
		put_str_nl("\033[92mOK\033[0m");
	else
		put_str_nl("\033[91mKO\033[0m");
	free_stack(stack, ALL);
}
