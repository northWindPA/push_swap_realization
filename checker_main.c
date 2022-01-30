#include "main.h"

void	chkr_get_cmds(t_2_stcks *stcks)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		chkr_exec_cmds(stcks, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	chkr_exec_cmds(t_2_stcks *stcks, char *cmd_s)
{
	if (!ft_strncmp(cmd_s, "sa", 25))
		sa(stcks, 0);
	else if (!ft_strncmp(cmd_s, "sb", 25))
		sb(stcks, 0);
	else if (!ft_strncmp(cmd_s, "ss", 25))
		ss(stcks, 0);
	else if (!ft_strncmp(cmd_s, "pa", 25))
		pa(stcks, 0);
	else if (!ft_strncmp(cmd_s, "pb", 25))
		pb(stcks, 0);
	else if (!ft_strncmp(cmd_s, "ra", 25))
		ra(stcks, 0);
	else if (!ft_strncmp(cmd_s, "rb", 25))
		rb(stcks, 0);
	else if (!ft_strncmp(cmd_s, "rr", 25))
		rr(stcks, 0);
	else if (!ft_strncmp(cmd_s, "rra", 25))
		rra(stcks, 0);
	else if (!ft_strncmp(cmd_s, "rrb", 25))
		rrb(stcks, 0);
	else if (!ft_strncmp(cmd_s, "rrr", 25))
		rrr(stcks, 0);
	else
		error_out(1);
}

int	main(int ac, char **av)
{
	t_ns		numbers;
	t_2_stcks	all_stacks;

	if (ac == 1)
		error_out(5);
	ns_init(&numbers);
	stcks_init(&all_stacks);
	args_prs(ac, av, &numbers);
	chk_dup(&numbers);
	pt_lst(&all_stacks, &numbers);
	chkr_get_cmds(&all_stacks);
	if (!chk_lst_srt(all_stacks.a_stck) && !all_stacks.b_stck_len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stcks_free(&all_stacks);
	return (0);
}
