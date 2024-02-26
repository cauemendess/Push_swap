/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:46:54 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:46:55 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	clear_lines(t_push *push, char *line)
{
	get_next_line(-1);
	free(line);
	ft_clear_err("Error", push);
}

void	exec_moves(t_push *push, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		do_sa(push);
	else if (!ft_strncmp(line, "sb\n", 3))
		do_sb(push);
	else if (!ft_strncmp(line, "ss\n", 3))
		do_ss(push);
	else if (!ft_strncmp(line, "pa\n", 3))
		do_pa(push);
	else if (!ft_strncmp(line, "pb\n", 3))
		do_pb(push);
	else if (!ft_strncmp(line, "ra\n", 3))
		do_ra(push);
	else if (!ft_strncmp(line, "rb\n", 3))
		do_rb(push);
	else if (!ft_strncmp(line, "rr\n", 3))
		do_rr(push);
	else if (!ft_strncmp(line, "rra\n", 4))
		do_rra(push);
	else if (!ft_strncmp(line, "rrb\n", 4))
		do_rrb(push);
	else if (!ft_strncmp(line, "rrr\n", 4))
		do_rrr(push);
	else
		clear_lines(push, line);
	free(line);
}

void	read_moves(t_push *push)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		exec_moves(push, line);
	}
	free(line);
	get_next_line(-1);
}

int	main(int argc, char **argv)
{
	t_push	*push;

	push = init_all(argc, argv);
	init_stack(push);
	validate(push);
	read_moves(push);
	if (is_ordened(push->stack_a) && push->stack_b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_finish(push);
}
