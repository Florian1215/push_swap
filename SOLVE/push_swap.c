/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:35:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/27 14:35:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	solve3(t_stack *stack)
{
	if (is_sort(stack, 0) || stack->len_a != 3)
		return ;
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2])
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->a[2] < stack->a[1] && stack->a[2] < stack->a[0])
	{
		if (stack->a[1] < stack->a[0])
			sa(stack);
		rra(stack);
	}
	else if (stack->a[2] > stack->a[0])
		sa(stack);
	else
		ra(stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (SUCCESS);
	stack = parsing(--ac, ++av);
	if (!stack)
		return (ERROR);
	stack->print = 1;
	if (!is_sort(stack, 0))
	{
		if (stack->len == 3)
			solve3(stack);
		else if (stack->len > 6 || stack->len == 5)
			solve_smart_sort(stack);
		else
			solve_radix(stack);
	}
	free_stack(stack, ALL);
	return (SUCCESS);
}
